/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <math.h>
#include <poll.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <cutils/log.h>

#include "PressureSensor.h"

#define CAL_DATA_IF                     "/sys/class/hwmon/hwmon2/device/cal_data"
#define PRESSURE_ADC_IF                 "/sys/class/hwmon/hwmon2/device/pressure"

#define DATA_DELIM_STRING                    ","
#define CAL_DATA_SIZE       8

/*****************************************************************************/
int C[CAL_DATA_SIZE];
int ADC[2];

PressureSensor::PressureSensor()
    : SensorBase(NULL, "pressuresensor"),
      mEnabled(0),
      mInputReader(4),
      mHasPendingEvent(false)
{
    mPendingEvent.version = sizeof(sensors_event_t);
    mPendingEvent.sensor = ID_P;
    mPendingEvent.type = SENSOR_TYPE_PRESSURE;
    memset(mPendingEvent.data, 0, sizeof(mPendingEvent.data));

    if (data_fd) {
        strcpy(input_sysfs_path, "/sys/class/input/");
        strcat(input_sysfs_path, input_name);
        strcat(input_sysfs_path, "/device/");
        input_sysfs_path_len = strlen(input_sysfs_path);
        enable(0, 1);
    }

    if(1)
    {
        int fd;
        char buf[60];
        char *p=NULL;
        int count=0;

        fd=open(CAL_DATA_IF, O_RDONLY);
        if(fd<0)
        {
            perror("Open Cal_data");
        }

        memset(buf, 0, 60);
        read(fd, buf, 60);

        if(1)
        {
            p=strtok(buf,DATA_DELIM_STRING);
            while(p)
            {
                C[count] = atol(p);
                count++;
                p=strtok(NULL,DATA_DELIM_STRING);
            }
            if(count!=CAL_DATA_SIZE)
                LOGE("Incorrect convertion result!! \n");
        }
        LOGE("Failed to read calibration data!! \n");
    }
}

PressureSensor::~PressureSensor() {
    if (mEnabled) {
        enable(0, 0);
    }
}

int PressureSensor::setDelay(int32_t handle, int64_t ns)
{
    int fd;
    strcpy(&input_sysfs_path[input_sysfs_path_len], "poll_delay");
    fd = open(input_sysfs_path, O_RDWR);
    if (fd >= 0) {
        char buf[80];
        sprintf(buf, "%lld", ns);
        write(fd, buf, strlen(buf)+1);
        close(fd);
        return 0;
    }
    return -1;
}

int PressureSensor::enable(int32_t handle, int en)
{
#if 0
    int flags = en ? 1 : 0;
    if (flags != mEnabled) {
        int fd;
        strcpy(&input_sysfs_path[input_sysfs_path_len], "enable");
        fd = open(input_sysfs_path, O_RDWR);
        if (fd >= 0) {
            char buf[2];
            int err;
            buf[1] = 0;
            if (flags) {
                buf[0] = '1';
            } else {
                buf[0] = '0';
            }
            err = write(fd, buf, sizeof(buf));
            close(fd);
            mEnabled = flags;
            return 0;
        }
        return -1;
    }
#else
    int flags = en ? 1 : 0;
    mEnabled = flags;
#endif
    return 0;
}

bool PressureSensor::hasPendingEvents() const {
    return mHasPendingEvent;
}

int PressureSensor::readEvents(sensors_event_t* data, int count)
{
    int temperature;
    int pressure;
    int32_t dT; //difference between actual and measured temp.
    int64_t OFF; //offset at actual temperature
    int64_t SENS; //sensitivity at actual temperature
    int32_t T2;
    int64_t OFF2;
    int64_t SENS2;
    int64_t TEMP;
    if (count < 1)
        return -EINVAL;

    if (mHasPendingEvent) {
        mHasPendingEvent = false;
        mPendingEvent.timestamp = getTimestamp();
        *data = mPendingEvent;
        return mEnabled ? 1 : 0;
    }

    ssize_t n = mInputReader.fill(data_fd);
    if (n < 0)
        return n;

    int numEventReceived = 0;
    input_event const* event;

    while (count && mInputReader.readEvent(&event)) {
        int type = event->type;
        if (type == EV_ABS) {
            if (event->code == EVENT_TYPE_PRESSURE1) {
                ADC[0] = event->value;
            }
            else if(event->code == EVENT_TYPE_PRESSURE2)
            {
                ADC[1] = event->value;
                // mPendingEvent.pressure = event->value;
            }
        } else if (type == EV_SYN) {

            dT = ADC[1] - C[5] * pow(2,8);
            OFF = C[2] * pow(2,16) + (dT * C[4]) / pow(2,7);
            SENS = C[1] * pow(2,15) + (dT * C[3]) / pow(2,8);
            temperature = 2000 + dT * C[6]/pow(2,23);
            //SECOND ORDER TEMP COMPENSATION
            if(temperature < 2000){
                T2 = (dT *dT) >> 31;
                TEMP = temperature - 2000;
                OFF2 = (5 *  TEMP * TEMP) >> 1;
                SENS2 = OFF2 >> 1;
                if(temperature < -1500){
                    TEMP = temperature + 1500;
                    OFF2 = OFF2 + 7 * TEMP * TEMP;
                    SENS2 = (SENS2 + (11 * TEMP * TEMP)) >> 1;
                }
                temperature -= T2;
                OFF -= OFF2;
                SENS -= SENS2;
            }
            pressure = (int32_t)((ADC[0] * SENS / pow(2,21) - OFF)/pow(2,15));

            mPendingEvent.pressure = pressure/100.0f;
            // LOGE("PressureSensor:  (type=%d, code=%d) pressure:%f", type, event->code, mPendingEvent.pressure);

            mPendingEvent.timestamp = timevalToNano(event->time);
            if (mEnabled) {
                *data++ = mPendingEvent;
                count--;
                numEventReceived++;
            }
        } else {
            LOGE("PressureSensor: unknown event (type=%d, code=%d)",
                    type, event->code);
        }
        mInputReader.next();
    }

    return numEventReceived;
}

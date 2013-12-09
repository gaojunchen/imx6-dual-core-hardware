/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *	http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Copyright (C) 2011-2012 Freescale Semiconductor, Inc.
 */

#ifndef RUNTIME_H
#define RUNTIME_H

extern int start_uevent_monitor(void);
extern const char *runtime_3g_port_device(void);
extern const char *runtime_3g_port_data(void);
extern int runtime_3g_port_type(void);
enum {
	HUAWEI_MODEM = 0,
	AMAZON_MODEM,
	ZTE_MODEM,
	UNKNOWN_MODEM,
};

extern int current_modem_type;

#endif

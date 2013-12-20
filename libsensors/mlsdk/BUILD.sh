#!/bin/bash

# This is a sample of the command line make used to build
#   the libraries and binaries.
# Please customize this path to match the location of your
#   Android source tree. Other variables may also need
#   to be customized such as:
#   $CROSS, $PRODUCT, $KERNEL_ROOT

export ANDROID_BASE=`pwd`/../../../


make MPU_NAME=MPU6050B1 VERBOSE=1 TARGET=android ANDROID_ROOT=${ANDROID_BASE} KERNEL_ROOT=${ANDROID_BASE}/kernel_imx CROSS=${ANDROID_BASE}/prebuilt/linux-x86/toolchain/arm-linux-androideabi-4.4.x/bin/arm-linux-androideabi- PRODUCT=WP001 MPL_LIB_NAME=mplmpu echo_in_colors=echo -f Android-shared.mk $1

make MPU_NAME=MPU6050B1 VERBOSE=1 TARGET=android ANDROID_ROOT=${ANDROID_BASE} KERNEL_ROOT=${ANDROID_BASE}/kernel_imx CROSS=${ANDROID_BASE}/prebuilt/linux-x86/toolchain/arm-linux-androideabi-4.4.x/bin/arm-linux-androideabi- PRODUCT=WP001 MPL_LIB_NAME=mplmpu echo_in_colors=echo -f Android-static.mk $1


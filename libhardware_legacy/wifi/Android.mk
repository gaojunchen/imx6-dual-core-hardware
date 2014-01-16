# Copyright 2006 The Android Open Source Project

LOCAL_CFLAGS += -DCONFIG_CTRL_IFACE_CLIENT_DIR=\"/data/misc/wifi/sockets\"
LOCAL_CFLAGS += -DCONFIG_CTRL_IFACE_CLIENT_PREFIX=\"wpa_ctrl_\"

ifdef WIFI_DRIVER_MODULE_PATH
LOCAL_CFLAGS += -DWIFI_DRIVER_MODULE_PATH=\"$(WIFI_DRIVER_MODULE_PATH)\"
endif
ifdef WIFI_DRIVER_MODULE_ARG
LOCAL_CFLAGS += -DWIFI_DRIVER_MODULE_ARG=\"$(WIFI_DRIVER_MODULE_ARG)\"
endif
ifdef WIFI_DRIVER_P2P_MODULE_ARG
LOCAL_CFLAGS += -DWIFI_DRIVER_P2P_MODULE_ARG=\"$(WIFI_DRIVER_P2P_MODULE_ARG)\"
endif
ifdef WIFI_DRIVER_MODULE_NAME
LOCAL_CFLAGS += -DWIFI_DRIVER_MODULE_NAME=\"$(WIFI_DRIVER_MODULE_NAME)\"
endif

ifdef WIFI_SDIO_IF_DRIVER_MODULE_PATH
LOCAL_CFLAGS += -DWIFI_SDIO_IF_DRIVER_MODULE_PATH=\"$(WIFI_SDIO_IF_DRIVER_MODULE_PATH)\"
endif
ifdef WIFI_SDIO_IF_DRIVER_MODULE_ARG
LOCAL_CFLAGS += -DWIFI_SDIO_IF_DRIVER_MODULE_ARG=\"$(WIFI_SDIO_IF_DRIVER_MODULE_ARG)\"
endif
ifdef WIFI_SDIO_IF_DRIVER_MODULE_NAME
LOCAL_CFLAGS += -DWIFI_SDIO_IF_DRIVER_MODULE_NAME=\"$(WIFI_SDIO_IF_DRIVER_MODULE_NAME)\"
endif

ifdef WIFI_COMPAT_MODULE_PATH
LOCAL_CFLAGS += -DWIFI_COMPAT_MODULE_PATH=\"$(WIFI_COMPAT_MODULE_PATH)\"
endif
ifdef WIFI_COMPAT_MODULE_ARG
LOCAL_CFLAGS += -DWIFI_COMPAT_MODULE_ARG=\"$(WIFI_COMPAT_MODULE_ARG)\"
endif
ifdef WIFI_COMPAT_MODULE_NAME
LOCAL_CFLAGS += -DWIFI_COMPAT_MODULE_NAME=\"$(WIFI_COMPAT_MODULE_NAME)\"
endif

ifdef WIFI_FIRMWARE_LOADER
LOCAL_CFLAGS += -DWIFI_FIRMWARE_LOADER=\"$(WIFI_FIRMWARE_LOADER)\"
endif
ifdef WIFI_DRIVER_FW_PATH_STA
LOCAL_CFLAGS += -DWIFI_DRIVER_FW_PATH_STA=\"$(WIFI_DRIVER_FW_PATH_STA)\"
endif
ifdef WIFI_DRIVER_FW_PATH_AP
LOCAL_CFLAGS += -DWIFI_DRIVER_FW_PATH_AP=\"$(WIFI_DRIVER_FW_PATH_AP)\"
endif
ifdef WIFI_DRIVER_FW_PATH_P2P
LOCAL_CFLAGS += -DWIFI_DRIVER_FW_PATH_P2P=\"$(WIFI_DRIVER_FW_PATH_P2P)\"
endif
ifdef WIFI_DRIVER_FW_PATH_PARAM
LOCAL_CFLAGS += -DWIFI_DRIVER_FW_PATH_PARAM=\"$(WIFI_DRIVER_FW_PATH_PARAM)\"
endif
ifeq ($(BOARD_SOC_CLASS),IMX5X)
LOCAL_CFLAGS += -DIMX5X
endif

ifeq ($(BOARD_WLAN_VENDOR),ATHEROS)
  LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../external/wpa_supplicant_8/wpa_supplicant/src/common
  LOCAL_CFLAGS += -DBOARD_HAS_ATH_WLAN=\"$(BOARD_HAS_ATH_WLAN)\"
  LOCAL_SRC_FILES += wifi/wifi_ath.c
else
ifeq ($(BOARD_WIFI_VENDOR), realtek)
LOCAL_SRC_FILES += ../realtek/wlan/libhardware_legacy/wifi/wifi_realtek.c
else
  ifdef BOARD_HAVE_WIFI_CSR
	LOCAL_SRC_FILES += wifi/wifi_unifi.c
  else
		ifeq ($(BOARD_WLAN_VENDOR),INTEL)
			LOCAL_SRC_FILES += wifi/wifi_intel.c
			LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../external/wpa_supplicant_7/src/common
		else
			LOCAL_SRC_FILES += wifi/wifi.c
			LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../external/wpa_supplicant_8/src/common
		endif
  endif
endif
endif


LOCAL_SHARED_LIBRARIES += libnetutils

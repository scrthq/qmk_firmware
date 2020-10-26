SRC += scrthq.c babblePaste.c babl_windows.c babl_mac.c babl_vi.c
ifneq ($(strip $(NO_SECRETS)), yes)
    ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
        SRC += secrets.c
    endif
endif

VIA_ENABLE = no
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = no
OLED_DRIVER_ENABLE = no
TAP_DANCE_ENABLE = yes
LTO_ENABLE = yes

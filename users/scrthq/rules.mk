SRC +=  scrthq.c

SRC +=  babblePaste.c \
        babl_windows.c \
        babl_mac.c

SRC +=  scrthq_process_records.c

ifneq ($(strip $(NO_SECRETS)), yes)
    ifneq ("$(wildcard $(USER_PATH)/scrthq_secrets.c)","")
        SRC += scrthq_secrets.c
    endif
endif

CONSOLE_ENABLE = no
#MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = no
TAP_DANCE_ENABLE = no

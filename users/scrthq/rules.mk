SRC += scrthq.c \
        scrthq_layouts.c \
        scrthq_key_definitions.c \
        babblePaste.c babl_windows.c babl_mac.c babl_vi.c \
        scrthq_process_records.c

ifneq ($(strip $(NO_SECRETS)), yes)
    ifneq ("$(wildcard $(USER_PATH)/scrthq_secrets.c)","")
        SRC += scrthq_secrets.c
    endif
endif

CONSOLE_ENABLE = yes
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = no
TAP_DANCE_ENABLE = yes

SRC +=  scrthq.c

# SRC +=  babblePaste.c \
#         babl_windows.c \
#         babl_mac.c

SRC +=  scrthq_os_keys.c \
		scrthq_process_records.c \
		scrthq_matrix_scan.c

ifneq ($(strip $(NO_SECRETS)), yes)
    ifneq ("$(wildcard $(USER_PATH)/scrthq_secrets.c)","")
        SRC += scrthq_secrets.c
    endif
endif

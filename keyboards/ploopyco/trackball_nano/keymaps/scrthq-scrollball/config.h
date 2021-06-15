#pragma once

//turn on scroll ball
#define PLOOPY_SCROLL_BALL true
#define PLOOPY_SCROLL_INVERT true
#define PLOOPY_DPI_OPTIONS { CPI125, CPI250, CPI375 }
#define PLOOPY_DPI_DEFAULT 0
#ifdef USB_POLLING_INTERVAL_MS
    #undef USB_POLLING_INTERVAL_MS
    #define USB_POLLING_INTERVAL_MS 50
#endif

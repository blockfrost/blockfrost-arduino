#if defined(DEBUG_APP) && defined(DEBUG_ESP_PORT)
#define DEBUG_MSG(...) DEBUG_ESP_PORT.printf( __VA_ARGS__ )
#else
#define DEBUG_MSG(...)
#endif

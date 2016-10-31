#define RNACI_HEADER_ONLY SETME

#if RNACI_HEADER_ONLY
#define RNACI_FUNTYPE static inline 
#else
#define RNACI_FUNTYPE
#endif

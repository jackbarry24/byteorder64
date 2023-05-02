#include "byteorder64.h"

static uint16_t endian_v16 = 0xaabb;
static uint8_t *endian_p8 = (uint8_t *)&endian_v16;

#define IS_BIG_ENDIAN (endian_p8[0] == 0xaa)
#define IS_LITTLE_ENDIAN (endian_p8[0] == 0xbb)

int is_big_endian(){
    return IS_BIG_ENDIAN ? 1 : 0;
}

int is_little_endian(){
    return IS_LITTLE_ENDIAN ? 1 : 0;
}

#define REVERSE_64(v64)(               \
    (v64 & 0xff00000000000000) >> 56 | \
    (v64 & 0x00ff000000000000) >> 40 | \
    (v64 & 0x0000ff0000000000) >> 24 | \
    (v64 & 0x000000ff00000000) >> 8  | \
    (v64 & 0x00000000ff000000) << 8  | \
    (v64 & 0x0000000000ff0000) << 24 | \
    (v64 & 0x000000000000ff00) << 40 | \
    (v64 & 0x00000000000000ff) << 56   \
)

uint64_t hton64(uint64_t host64){
    return IS_BIG_ENDIAN ? host64 : REVERSE_64(host64);
}

uint64_t ntoh64(uint64_t net64){
    return IS_BIG_ENDIAN ? net64 : REVERSE_64(net64);
}



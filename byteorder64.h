#ifndef _byteorder64_h_
#define _byteorder64_h_

#include <stdint.h>

int is_big_endian();
int is_little_endian();

uint64_t hton64(uint64_t stream);
uint64_t ntoh64(uint64_t stream);

#endif // _byteorder64_h_
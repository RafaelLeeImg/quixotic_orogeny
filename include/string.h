#ifndef __STRING_H__
#define __STRING_H__
#include "stdint.h"
#include "sys/types.h"

#define MAX_STRING_LEN 4096

size_t strnlen(const char s[], size_t maxlen);
// size_t strnlen();

void *memset(void *s, int c, size_t n);

#endif /* __STRING_H__ */
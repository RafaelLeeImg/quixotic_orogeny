// string.c

#include "string.h"
#include "stdint.h"

size_t strnlen(const char s[], size_t maxlen) {
  for (size_t i = 0; i < maxlen; i++) {
    if (!s[i])
      return i + 1;
  }
  return maxlen;
}

// TODO: What if c in memset >= 256???
void *memset(void *s, int c, size_t n) {
  unsigned char *ptr = s;
  for (size_t i = 0; i < n; i++) {
    *(ptr + i) = (unsigned int)c & 0xFF;
  }
  return s;
}

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

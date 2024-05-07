#ifndef __STARG_H__
#define __STARG_H__
// #include "stdint.h"
#define NULL 0

typedef char *va_list;

#define va_start(ap, last_named_arg)                                           \
  ((void)((ap) = (va_list) & (last_named_arg) + sizeof(last_named_arg)))

#define va_end(ap) ((void)(ap = NULL))

#define va_arg(ap, type) (*(type *)((ap) += sizeof(type)))
#endif /* __STARG_H__ */

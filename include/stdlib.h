#ifndef __STDLIB_H__
#define __STDLIB_H__

typedef struct memory_block {
  size_t size;
  struct memory_block *next;
  void *memory;
} memory_block_t; // used in malloc

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif /* __STDLIB_H__ */

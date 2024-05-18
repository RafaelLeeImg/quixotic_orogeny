#include <stdio.h>
#include <stdlib.h>

// design:
// Manage memory with list, the list is at the head of malloced area, so this
// malloc can work without dynamic memory available

// TODO: does the memory alignment needs to be put here?

// +---------+------------+              +------------+----------+
// |header   |  allocated |              |  header    | allocated|
// |size     |  memory    |              |  size      | memory   |
// |next_node|            |              |  next_node |          |
// |   \     |            |              |    /       |          |
// |    \    |            |              |   /        |          |
// +-----\---+------------+              +--/---------+----------+
//        \                                /
//         \                              /
//          -----------------------------/

extern unsigned char *heap;
extern unsigned char *heap_start;
extern unsigned char *heap_end;

void debug_malloc(void);
size_t malloc_available_size(memory_block_t *block);

// shall be heap_start, anyway, they are the same address
// g_root is a NULL value or pointer points to the next node of the linked list
memory_block_t *g_root = (void *)0;

// if block not exists, all heap size is available
// if block exists and next block is valid, calculate the space after this block
// and between next block header if block exists and next block is not valid,
// calculate the space after this block and before heap_end
size_t malloc_available_size(memory_block_t *block) {
  // sizeof(memory_block_t) needs to be extracted, since it needs to reserve
  // some area for the memory_block_t when making a new area, so this equation
  // could lead to negative numbers
  if (!block) {
    return (unsigned int)heap_end - sizeof(memory_block_t) -
           (unsigned int)heap_start;
  }
  // g_root points to somewhere after heap_start, so there is a space at the
  // start of heap which is not used try to allocate memory in this space
  else if (block == (memory_block_t *)heap_start &&
           (unsigned char *)g_root > heap_start) {
    size_t x = (unsigned char *)g_root - (unsigned char *)heap_start -
               sizeof(memory_block_t);
    return x;
  }

  size_t end;
  if (!(block->next)) {
    // last node
    end = (size_t)(unsigned char *)heap_end;
  } else {
    // area between this node and next node
    end = (size_t)(unsigned char *)(block->next);
  }
  ssize_t x = end - sizeof(memory_block_t) -
              (size_t)(unsigned char *)block->memory - block->size;
  // because of "- sizeof(memory_block_t)", the size could be less than 0
  if (x < 0) {
    return 0;
  } else {
    return (size_t)x;
  }
}

// posix
// FIXME: known problem: if first node is freed, then the area will not be
// allocated (fixed)
void *malloc(size_t size) {
  if (0 == size) {
    return (void *)0;
  }
  // if no other node is allocated and required size is within available size
  // create first node
  if (!g_root || g_root != (memory_block_t *)heap_start) {
    // FIXME: error here, 20240517 00:01
    // if g_root not exists, calculate size with all stack
    // if g_root exists, find the space between heap_start and the first block
    size_t available_size;
    if (!g_root) {
      available_size = malloc_available_size((memory_block_t *)0);
    } else {
      available_size = malloc_available_size((memory_block_t *)heap_start);
    }
    // printf("available_size = 0x%x\n", available_size);
    if (available_size >= size) {
      memory_block_t *iter = (memory_block_t *)heap_start;
      memory_block_t *next_node = g_root;
      g_root = iter;
      iter->size = size;
      iter->memory = heap_start + sizeof(memory_block_t);
      iter->next = next_node;
      return iter->memory;
    } else {
      return (void *)0;
    }
  }

  memory_block_t *iter = g_root;

  // select first area that are available
  while (1) {
    size_t available_size = malloc_available_size(iter);
    // if available_size >= size, allocate here, if not try next node
    if (available_size >= size) {
      memory_block_t *new_area = 0;
      new_area = (memory_block_t *)((unsigned char *)iter->memory + iter->size);
      new_area->size = size;
      new_area->memory = (unsigned char *)new_area + sizeof(memory_block_t);

      // if this node is last
      if (iter->next) {
        new_area->next = iter->next;
      } else {
        new_area->next = 0;
      }
      iter->next = new_area;

      // debugging
      // for (size_t i = 0; i < size; i++) {
      //   ((unsigned char *)new_area->memory)[i] = 0xaa;
      // }

      return new_area->memory;
    } else {
      if (!(iter->next)) {
        return 0;
      }
      iter = iter->next;
    }
  }
}

// FIXME: when double free, there will be error
void free(void *ptr) {
  if (!g_root) {
    return;
  }
  memory_block_t *iter = g_root;
  memory_block_t *last;
  // first
  {
    if (iter->memory == ptr) {
      g_root = iter->next;
      return;
    }
    last = iter;
    // printf("iter = ");
    iter = iter->next;
  }
  // second to last
  while (iter) {
    if (iter->memory == ptr) {
      // remove this node from linked list
      last->next = iter->next;
      return;
    }
    last = iter;
    iter = iter->next;
  }
}

void debug_malloc(void) {
  memory_block_t *iter = g_root;
  for (int i = 0; iter; i++) {
    printf("[% 3d], iter = %p, ", i, (void *)iter);
    printf(".size = % 8d, ", iter->size);
    printf(".memory = %p, ", iter->memory);
    printf(".next = %p\n", (void *)iter->next);
    // if iter->next == 0, loop will break
    iter = iter->next;
  }
}

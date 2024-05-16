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

// shall be heap_start, anyway, they are the same address
// g_root is a NULL value or pointer points to the next node of the linked list
memory_block_t *g_root = (void *)0;

// if block not exists, all heap size is available
// if block exists and next block is valid, calculate the space after this block
// and between next block header if block exists and next block is not valid,
// calculate the space after this block and before heap_end
size_t malloc_available_size(memory_block_t *block) {
  // sizeof(memory_block_t) needs to be extracted, since it needs to reserve
  // some area for the memory_block_t when making a new area

  if (!block) {
    ssize_t x = heap_end - sizeof(memory_block_t) - heap_start;
    return x;
  }

  ssize_t end;
  if (!(block->next)) {
    end = (ssize_t)(unsigned char *)heap_end;
  } else {
    end = (ssize_t)(unsigned char *)(block->next);
  }
  ssize_t x = end - sizeof(memory_block_t) -
              (ssize_t)(unsigned char *)block->memory - block->size;
  // because of "- sizeof(memory_block_t)", the size could be less than 0
  if (x < 0) {
    return 0;
  } else {
    return x;
  }
  return x;
}

// posix
// FIXME: known problem: if first node is freed, then the area will not be
// allocated
void *malloc(size_t size) {
  if (0 == size) {
    return (void *)0;
  }
  // if no other node is allocated and required size is within available size
  // create first node
  if (!g_root) {
    size_t available_size = malloc_available_size((memory_block_t *)0);
    // printf("available_size = 0x%x\n", available_size);
    if (available_size >= size) {
      memory_block_t *iter = (memory_block_t *)heap_start;
      g_root = iter;
      iter->size = size;
      iter->memory = heap_start + sizeof(memory_block_t);
      iter->next = (memory_block_t *)0;
      return iter->memory;
    } else {
      return (void *)0;
    }
  }

  memory_block_t *iter = g_root;

  // select first area that are available
  while (1) {
    ssize_t available_size = malloc_available_size(iter);
    // if available_size >= size, allocate here, if not try next node
    if (available_size >= size) {
      memory_block_t *new_area = 0;
      new_area = (memory_block_t *)((unsigned char *)iter->memory + iter->size);
      new_area->size = size;
      new_area->memory = (unsigned char *)new_area + sizeof(memory_block_t);
      new_area->next = (memory_block_t *)0;
      iter->next = new_area;
      ((unsigned char *)new_area->memory)[0] = 0xf1;
      ((unsigned char *)new_area->memory)[1] = 0xf2;
      ((unsigned char *)new_area->memory)[2] = 0x3f;
      ((unsigned char *)new_area->memory)[3] = 0x4f;

      // //   new_area
      // if (iter->next) {
      //   new_area->next = iter->next;
      //   iter->next = new_area;
      // }
      return new_area->memory;
    } else {
      if (!(iter->next)) {
        return 0;
      }
      iter = iter->next;
      // printf("next, ");
      continue;
    }
  }
}

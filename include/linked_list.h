#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "sys/types.h"

// the reason to make a double sided list is that making this is similar with
// single sided linked list, the size occupation is only 4 bytes more for each
// node
typedef struct list_node {
  void *element;
  struct list_node *next;
  struct list_node *previous;
} list_node_t;

// Insert a node after given node
void list_insert(list_node_t *head, list_node_t *origin_node,
                 list_node_t *new_node);

// Insert a node at a index (0-based) in the list
void list_insert_by_index(list_node_t *head, size_t index,
                          list_node_t *new_node);

// Insert a node before the given node
void list_insert_previous(list_node_t *head, list_node_t *origin_node,
                          list_node_t *new_node);

// Remove a node from the list
void list_remove(list_node_t *head, list_node_t *this_node);

// Append a node to the end of the list
void list_push_back(list_node_t *head, list_node_t *this_node);

// return the pointer of last node of the list
list_node_t *list_end(list_node_t *head);

// Create a new node
list_node_t *create_node(void *element);

// Free a node
void free_node(list_node_t *node);

#endif /* __LINKED_LIST_H__ */

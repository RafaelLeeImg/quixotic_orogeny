#include "linked_list.h"
#include "stddef.h"
#include "stdlib.h"

// Insert a node after the given previous node
void list_insert(list_node_t *head, list_node_t *origin_node,
                 list_node_t *new_node) {
  if (origin_node == NULL || new_node == NULL) {
    return;
  }

  new_node->next = origin_node->next;
  new_node->previous = origin_node;

  if (origin_node->next != NULL) {
    origin_node->next->previous = new_node;
  }
  origin_node->next = new_node;
}

// Insert a node at a index (0-based) in the list
void list_insert_by_index(list_node_t *head, size_t index,
                          list_node_t *new_node) {
  if (head == NULL || new_node == NULL) {
    return;
  }

  list_node_t *current = head;
  for (size_t i = 0; i < index; i++) {
    if (current->next == NULL) {
      break;
    }
    current = current->next;
  }

  list_insert(head, current, new_node);
}

// Insert a node before the given node
void list_insert_previous(list_node_t *head, list_node_t *origin_node,
                          list_node_t *new_node) {
  if (origin_node == NULL || new_node == NULL) {
    return;
  }

  new_node->next = origin_node;
  new_node->previous = origin_node->previous;

  if (origin_node->previous != NULL) {
    origin_node->previous->next = new_node;
  }
  origin_node->previous = new_node;
}

// Remove a node from the list
void list_remove(list_node_t *head, list_node_t *this_node) {
  if (this_node == NULL) {
    return;
  }

  if (this_node->previous != NULL) {
    this_node->previous->next = this_node->next;
  }

  if (this_node->next != NULL) {
    this_node->next->previous = this_node->previous;
  }

  this_node->next = NULL;
  this_node->previous = NULL;
}

// Append a node to the end of the list
void list_push_back(list_node_t *head, list_node_t *this_node) {
  if (head == NULL || this_node == NULL) {
    return;
  }

  list_node_t *current = head;
  while (current->next != NULL) {
    current = current->next;
  }

  list_insert(head, current, this_node);
}

// return the pointer of last node of the list
list_node_t *list_end(list_node_t *head) {
  list_node_t *iter = head->next;
  while (iter->next) {
    iter = iter->next;
  }
  return iter;
}

// Create a new node
list_node_t *create_node(void *element) {
  list_node_t *new_node = (list_node_t *)malloc(sizeof(list_node_t));
  if (new_node == NULL) {
    perror("Failed to create node");
    return (void *)0;
  }
  new_node->element = element;
  new_node->next = NULL;
  new_node->previous = NULL;
  return new_node;
}

// Free a node
void free_node(list_node_t *node) {
  if (node != NULL) {
    free(node);
  }
}

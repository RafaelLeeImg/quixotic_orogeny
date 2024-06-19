#include "linked_list.h"
#include "stddef.h"
#include "stdio.h"
#include "stdlib.h"

void list_print_list(list_node_t *head) {
  // Print list elements
  list_node_t *current = head->next; // skip head as it is a dummy node
  while (current != NULL) {
    printf("%s\n", (char *)current->element);
    current = current->next;
  }
}

void list_print_node(list_node_t *node) {
  if (node != NULL) {
    printf("%s\n", (char *)node->element);
  }
}

void test_linked_list() {
  // Create a head node
  list_node_t *head = create_node(NULL);

  // Create other nodes
  list_node_t *node1 = create_node((void *)"Node 1");
  list_node_t *node2 = create_node((void *)"Node 2");
  list_node_t *node3 = create_node((void *)"Node 3");
  list_node_t *node4 = create_node((void *)"Node 4");
  list_node_t *node5 = create_node((void *)"Node 5");

  // Insert nodes
  list_push_back(head, node1);
  list_push_back(head, node2);
  list_push_back(head, node3);
  list_push_back(head, node4);
  // list_push_back(head, node5);
  // list_insert_by_index(head, 4, node3);

  printf("after list creation\n");
  list_print_list(head);

  // list_remove(head, node2);
  list_insert_previous(head, node2, node5);

  printf("after list_insert_previous(head, node2, node5);\n");
  list_print_list(head);

  printf("------------------------------------\n");

  list_print_node(list_end(head));

  printf("------------------------------------\n");
  list_remove(head, node4);
  printf("after list_remove(head, node4);\n");

  list_print_node(list_end(head));
  printf("------------------------------------\n");

  // Free nodes
  free_node(head);
  free_node(node1);
  free_node(node2);
  free_node(node3);
  free_node(node4);
  free_node(node5);
}

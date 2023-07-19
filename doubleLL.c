#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *next;
  struct node *prev;
};
struct node *addAtEnd(struct node *, int);
struct node *addAtBeg(struct node *, int);
struct node *deleteAtBeg(struct node *);
struct node *deleteAtEnd(struct node *);
void traverse(struct node *);

int main() {
  struct node *head = NULL;
  struct node *one;
  struct node *two;
  struct node *three;

  one = (struct node *)malloc(sizeof(struct node));
  two = (struct node *)malloc(sizeof(struct node));
  three = (struct node *)malloc(sizeof(struct node));

  // creation of double LL
  one->data = 1;
  two->data = 2;
  three->data = 3;

  one->next = two;
  one->prev = NULL;
  two->next = three;
  two->prev = one;
  three->next = NULL;
  three->prev = two;

  head = one;
  traverse(head);
  printf("\n");
  head = addAtBeg(head, 5);
  traverse(head);
  printf("\n");
  head = addAtEnd(head, 6);
  traverse(head);
  printf("\n");
  head = deleteAtBeg(head);
  traverse(head);
  printf("\n");
  head = deleteAtEnd(head);
  traverse(head);
  return 0;
}

// Traverse a Double Linked List
void traverse(struct node *head) {
  struct node *ptr = head;
  while (ptr != NULL) {

    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
}

// Addition at beginning of a Doubly LL
struct node *addAtBeg(struct node *head, int ele) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = ele;
  temp->next = head;
  head = temp;
  return head;
}

// Addition at the end of the doubly ll
struct node *addAtEnd(struct node *head, int ele) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = ele;
  temp->next = NULL;
  struct node *ptr = head;
  while (ptr->next != NULL)
    ptr = ptr->next;
  ptr->next = temp;
  return head;
}

// deletion of a node from the beginning
struct node *deleteAtBeg(struct node *head) {
  struct node *temp = head;
  head = head->next;
  temp->next = NULL;
  free(temp);
  return head;
}

// delete at the end
struct node *deleteAtEnd(struct node *head) {
  struct node *ptr = head;
  while (ptr->next->next != NULL)
    ptr = ptr->next;
  struct node *temp = ptr->next;
  ptr->next = NULL;
  free(temp);
  return head;
}
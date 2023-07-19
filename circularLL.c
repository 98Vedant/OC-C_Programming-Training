#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};
struct node *deleteAtBeg(struct node *);
struct node *deleteAtEnd(struct node *);
struct node *addAtBeg(struct node *, int);
struct node *addAtEnd(struct node *, int);
void traverse(struct node *);
int main() {
  struct node *head;
  struct node *one;
  struct node *two;
  struct node *three;

  // creation of single linked list
  one = (struct node *)malloc(sizeof(struct node));
  two = (struct node *)malloc(sizeof(struct node));
  three = (struct node *)malloc(sizeof(struct node));
  one->data = 1;
  two->data = 2;
  three->data = 3;
  one->next = two;
  two->next = three;
  head = one;
  three->next = head;

  traverse(head);
  printf("\n");
  // add a node at the end of the linked list
  head = addAtEnd(head, 4);
  traverse(head);
  // add a node at beginning
  printf("\n");
  head = addAtBeg(head, 5);
  traverse(head);

  // delete at the end
  printf("\n");
  head = deleteAtEnd(head);
  traverse(head);

  // delete from the beginning
  printf("\n");
  head = deleteAtBeg(head);
  traverse(head);

  return 0;
}

// traverse a linked list
void traverse(struct node *head) {
  struct node *ptr = head;
  while (ptr->next != head) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("%d", ptr->data);
}
// add a node at the end of the linkedList
struct node *addAtEnd(struct node *head, int ele) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = ele;
  temp->next = head;
  struct node *ptr = head;
  while (ptr->next != head)
    ptr = ptr->next;
  ptr->next = temp;
  return head;
}

// add at beginning
struct node *addAtBeg(struct node *head, int ele) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = ele;
  temp->next = head;
  struct node *ptr = head;
  while (ptr->next != head)
    ptr = ptr->next;
  ptr->next = temp;
  head = temp;
  return head;
}

// delete a node at the end
struct node *deleteAtEnd(struct node *head) {
  struct node *ptr = head;
  struct node *temp = NULL;
  while (ptr->next->next != head)
    ptr = ptr->next;
  temp = ptr->next;
  ptr->next = head;
  free(temp);
  return head;
}

// delete a node at the beginning
struct node *deleteAtBeg(struct node *head) {
  struct node *temp = head;
  struct node *ptr = head;

  while (ptr->next != head)
    ptr = ptr->next;
  head = head->next;
  ptr->next = head;
  temp->next = NULL;
  free(temp);
  return head;
}

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};
struct node *reverse(struct node *);
struct node *deleteAtBeg(struct node *);
struct node *deleteAtEnd(struct node *);
struct node *addAtBeg(struct node *, int );
struct node *addAtEnd(struct node *, int);
void traverse(struct node*);
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
  three->next = NULL;
  head = one;

  traverse(head);
  printf("\n");
  // add a node at the end of the linked list
  head = addAtEnd(head, 4);
  traverse(head);
  //add a node at beginning 
  printf("\n");
  head = addAtBeg(head, 5);
  traverse(head);

  //delete at the end
  printf("\n");
  head = deleteAtEnd(head);
  traverse(head);

  //delete from the beginning
  printf("\n");
  head = deleteAtBeg(head);
  traverse(head);
  //reverse a LinkedList
  printf("\n");
  head = reverse(head);
  traverse(head);
  return 0;
}



//traverse a linked list
void traverse(struct node *head) {
  struct node *ptr = head;
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
}
//add a node at the end of the linkedList
struct node *addAtEnd(struct node *head, int ele){
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp->data = ele;
  temp ->next = NULL;
  struct node *ptr = head;
  while(ptr->next != NULL)
      ptr = ptr->next;
  ptr->next = temp;
  return head;
}
struct node *addAtBeg(struct node *head, int ele){
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp->data = ele;
  temp -> next = head;
  head = temp;
  return head;
}

struct node *deleteAtEnd(struct node *head){
  struct node *ptr = head;
  struct node *temp = NULL;
  while(ptr->next->next != NULL)
      ptr = ptr->next;
  temp = ptr->next;
  ptr->next = NULL;
  free(temp);
  return head;
}
struct node *deleteAtBeg(struct node *head){
  struct node *temp = head;
  head = head->next;
  temp->next = NULL;
  free(temp);
  return head;
}

struct node *reverse(struct node *head){
  struct node *forward = NULL;
  struct node *backward = NULL;
  struct node *curr = head;
  while(curr != NULL){
    forward = curr->next;
    curr->next = backward;
    backward = curr;
    curr = forward;
  } 
  head = backward;
  return head;
}
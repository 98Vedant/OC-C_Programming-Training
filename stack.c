#include <stdio.h>
#include <stdlib.h>

struct stack {
  int arr[10];
  int top; // Member for the top of the stack
};
int pop(struct stack *);
struct stack *push(struct stack *st, int ele);

int main() {
  struct stack *st = (struct stack *)malloc(sizeof(struct stack));
  st->top = -1; // Initialize top to -1 to indicate an empty stack

  st = push(st, 1);
  st = push(st, 2);
  st = push(st, 3);
  st = push(st, 4);

  printf("%d ", pop(st));
  printf("%d ", pop(st));
  printf("%d ", pop(st));
  printf("%d ", pop(st));

  return 0;
}

struct stack *push(struct stack *st, int ele) {
  st->arr[++st->top] = ele; // Accessing top member correctly
  return st;
}

int pop(struct stack *st) { return st->arr[st->top--]; }
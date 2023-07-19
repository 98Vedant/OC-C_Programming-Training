#include <stdio.h>
#include <stdlib.h>

struct Queue {
  int arr[10];
  int front;
  int rear;
};

struct Queue *enque(struct Queue *q, int ele);
int deque(struct Queue *q);

int main() {
  struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
  q->rear = -1;
  q->front = 0;
  q = enque(q, 1);
  q = enque(q, 2);
  q = enque(q, 3);
  q = enque(q, 4);

  printf("%d ", deque(q));
  printf("%d ", deque(q));
  printf("%d ", deque(q));
  printf("%d ", deque(q));

  return 0;
}

struct Queue *enque(struct Queue *q, int ele) {
  q->rear++;
  q->arr[q->rear] = ele;
  return q;
}

int deque(struct Queue *q) { return q->arr[q->front++]; }

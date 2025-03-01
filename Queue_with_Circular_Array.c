#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACITY 3 // Maximum size of the circular queue

typedef struct {
  int arr[CAPACITY];
  int front, size;
} CircularQueue;

// Function to check if the queue is full
bool isFull(CircularQueue *q) {
  return (q->size == CAPACITY);
}

// Function to check if the queue is empty
bool isEmpty(CircularQueue *q) {
  return (q->size == 0);
}

// Function to get the front index
int getFront(CircularQueue *q) {
  if (isEmpty(q))
    return -1;
  return q->front;
}

// Function to get the rear index
int getRear(CircularQueue *q) {
  if (isEmpty(q))
    return -1;
  return (q->front + q->size - 1) % CAPACITY;
}

// Function to enqueue an element
void enqueue(CircularQueue *q, int x) {
  if (isFull(q))
    return;

  int rear = getRear(q);
  rear = (rear + 1) % CAPACITY;
  q->arr[rear] = x;
  q->size++;
}

// Function to dequeue an element
int dequeue(CircularQueue *q) {
  if (isEmpty(q)) {
    printf("Underflow!");
    return INT_MIN;
  }
  int x= q->arr[q->front];
  q->front = (q->front + 1) % CAPACITY;
  q->size--;
  return x;
}

// Function to print the queue
void printQueue(CircularQueue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty.\n");
    return;
  }

  printf("Queue elements: ");
  for (int i = 0; i < q->size; i++) {
    int index = (q->front + i) % CAPACITY;
    printf("%d ", q->arr[index]);
  }
  printf("\n");
}

// Main function
int main() {
  CircularQueue q = {{0}, 0, 0}; // Initialize queue

  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);
  printQueue(&q);

  printf("Deque %d\n",dequeue(&q));
  printf("Deque %d\n",dequeue(&q));
  printf("Deque %d\n",dequeue(&q));

  enqueue(&q, 40);
  printQueue(&q);

  dequeue(&q);
  printQueue(&q);

  return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20


typedef struct{
  int array[MAXSIZE];
  int rear;
  int front;
  int size;

}Queue;

void initialize(Queue *q1) {
  q1->rear=-1;
  q1->front=-1;
  q1->size=0;

}

int isFull(const Queue q1) {
  return q1.size==MAXSIZE;
}

int isEmpty(const Queue q1) {
  return q1.size==0;
}

void enqueue(Queue *q1, int value) {
  if(isFull(*q1)) {
    printf("Underflow!");
    return;
  }

  if(isEmpty(*q1)) {
    q1->front=0;
  }

  q1->rear=(q1->rear+1)%MAXSIZE;
  q1->array[q1->rear] = value;
  q1->size++;

}

int dequeue(Queue* q1) {

  if(isEmpty(*q1)) {
    printf("Underflow!");
    return -1;
  }

  q1->front=(q1->front+1)%MAXSIZE;
  return q1->array[q1->front];



}

int main(){
  Queue q1;
}
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

typedef struct {
    Node* front;
    Node* rear;
    int size;
}Queue;

Queue* initializeQueue() {
    Queue* q = malloc(sizeof(Queue));
    q->front=NULL;
    q->rear=NULL;
    q->size=0;

    return q;
}

void enqueue(Queue *q, int data) {
    Node *newNode = createNode(data);
    //for null queue
    if(q->front==NULL) //empty queue
    {
        q->front=q->rear=newNode;
    }

    q->rear->next=newNode;
    q->rear=newNode;
    q->size++;
}

void dequeue(Queue *q){
    if(q->front==NULL) {
        return;
    }

    Node* temp=q->front;
    q->front=q->front->next;
    if(q->front==NULL) {q->rear=NULL;} //if remaining one node is too deleted reinitialize QUEUE
    free(temp);
}

void displayQueue(Queue *q) {
    if(q->front==NULL) {
        printf("Queue is empty !\n");
        return;
    }
    Node* temp=q->front;
    while(temp) {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main() {
    Queue* q = initializeQueue();

    // Enqueue elements
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    // Display queue
    displayQueue(q);

    // Dequeue elements
    printf("Dequeuing an element...\n");
    dequeue(q);
    displayQueue(q);

    printf("Dequeuing another element...\n");
    dequeue(q);
    displayQueue(q);

    // Free the queue memory
    while (q->front != NULL) {
        dequeue(q);
    }
    free(q);

    return 0;
}
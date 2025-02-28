#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

struct MyStack {
    struct Node *head;
    int size;
};

struct MyStack* initializeStack() {
    struct MyStack* temp = malloc(sizeof(struct MyStack));
    temp->head=NULL;
    temp->size=0;
    return temp;
}
int pop(struct MyStack* s) {
    if(s->head==NULL) {
        printf("Stack Underflow! \n");
        return INT_MIN; //underflow
    }
    struct Node* temp = s->head;
    s->head = s->head->next;
    int val = temp->data;
    free(temp);
    s->size--;
    return val;
}

void push(struct MyStack* s,int data) {
    struct Node* temp = createNode(data);
    temp->next= s->head;
    s->head = temp;
    s->size++;
}

void printStack(struct MyStack *s) {
    if(s->head==NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct Node* temp= s->head;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
   struct MyStack *s = initializeStack();
    push(s, 10);
    push(s, 20);
    push(s, 30);
    printStack(s);  // Output: Stack: 30 -> 20 -> 10 -> NULL

    pop(s);
    printStack(s);  // Output: Stack: 20 -> 10 -> NULL

    pop(s);
    printf("Popped value: %d\n",pop(s));
    printStack(s);
    pop(s);  // Output: Stack Underflow!

    return 0;

}
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void prepend(struct Node **head,int data,int *length) {
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data=data;
    new_node->next=(*head);
    *head= new_node;
    (*length)++;
}

void append(struct Node **tail, struct Node **head, int data, int *length) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data=data;
    new_node->next=NULL;
    if(*tail!=NULL) {
        (*tail)->next=new_node;
        (*tail)=new_node;
    }
    else { //linked list is empty
        (*tail)=new_node;
        (*head)=(*tail);

    }
    (*length)++;

}

struct Node* split(struct Node **head, struct Node **tail,int *length) {
    if (*head == NULL || *length < 2) {
        return NULL;  // No split possible for empty or single-element list
    }

    int split_idx = (*length % 2 == 0) ? (*length / 2) : (*length / 2) + 1;
    struct Node* current = *head;
    struct Node* prev = NULL;


    for (int i = 0; i < split_idx; i++) {
        prev = current;
        current = current->next;
    }

    if (prev) {
        prev->next = NULL;  // Break the first half
    }

    *tail = current;  // New head of second half

    *length = split_idx;  // Update length of the first half
    return *tail;  // Return new head of the second half
}

int insert(struct Node **head, int index, int value,int *length) {

    if(index<0){ printf("index can't be negative"); return -1; }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data=value;

    if(index==0) {
        new_node -> next = *head;
        *head=new_node;
        return 0;
    }
    struct Node* current = *head;
    for (int i = 0; i < index - 1; i++) {
        if (current == NULL) {
            printf("Index out of bounds.\n");
            free(new_node);
            return 0;
        }
        current = current->next;
    }


    new_node->next = current->next;
    current->next = new_node;
    (*length)++;
    return 0;
}

void printList(struct Node** head) {
    struct Node* current = *head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void main() {
    struct Node* head=NULL;
    struct Node* tail=NULL;
    int length=0;

    prepend(&head,5,&length);
    tail=head;

    prepend(&head,7,&length);
    append(&tail,&head,8,&length);
    append(&tail,&head,9,&length);
    insert(&head, 2,3,&length);
    printList(&head);
}
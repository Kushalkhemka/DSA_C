#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *head_ref) {
    Node *temp = head_ref;
    if(head_ref==nullptr) return;
    do {
        std::cout << temp->data << "->";
        temp=temp->next;
    }while (temp != head_ref);
    std::cout << "NULL" << std::endl;
}

Node* reverseLL(Node* head_ref) {
    Node* curr = head_ref; Node *prev = nullptr; Node* next=nullptr;
    while(curr!=nullptr) {
        next=curr->next;
        curr->next=prev;
        prev = curr;
        curr = next;

    }
}

Node* prepend(Node *head_ref, int data) {
    Node *newNode = new Node(data);
    if(head_ref==nullptr) {
        newNode->next=newNode;
    }

    Node* temp = head_ref;

    while(temp->next!=head_ref) {
        temp=temp->next;
    }
    temp->next = newNode;
    newNode->next = head_ref;
    return newNode;

}

Node* insertPos(Node *head,int pos, int data) {
    Node *newNode = new Node(data);
    Node *prev = head;
    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }
    if(head==nullptr) {
        newNode->next = head;  // head is NULL here
        head = newNode;
        return head;
    }
    for(int i=0;i<pos-2 && prev!=nullptr;i++) {
        prev = prev->next;
    }

    if(prev==nullptr) {
        return head;
    }
    newNode->next=prev->next;
    prev->next=newNode;
    return head;

}

Node* append(Node *head_ref, int data) {
    Node *newNode = new Node(data);
    if (head_ref == NULL) {
        // If the list is empty, new node becomes the head.
        newNode->next=newNode;
        return newNode;
    }

    Node *temp = head_ref;  // Use a temporary pointer to traverse.
    while (temp->next != head_ref) {
        temp = temp->next;
    }
    temp->next = newNode;  // Append new node at the end.
    newNode->next=head_ref;
    return head_ref;       // Return the original head.
}

Node* effappend(Node *head_ref, int data) { //O(1)
    Node *newNode = new Node(data);
    if (head_ref == NULL) {
        // If the list is empty, new node becomes the head.
        newNode->next=newNode;
        return newNode;
    }


    newNode->next=head_ref->next; //insert at 2nd position
    head_ref->next=newNode; //insert at 2nd position
    //swapping values
    int t= head_ref->data;
    head_ref->data = newNode->data;
    newNode->data= t;

    //now changing head ref to second node
    head_ref=head_ref->next;
    return head_ref;
    //similar prepend can be optimised to do the prepend in O(1).
}
Node* delHead(Node* head_ref) {
    // Node* temp = head_ref;
    //swapping data
    if(head_ref==nullptr) {
        return nullptr;
    }
    if(head_ref->next==head_ref) {
        delete(head_ref);
        return nullptr;
    }
    head_ref->data=head_ref->next->data;
    Node* temp = head_ref->next;
    head_ref->next= head_ref->next->next;
    delete(temp);
    return head_ref;



}


void recursive_printList(Node *head_ref) {
    Node *temp = head_ref; // temp is a pointer to the head of the list
    if (temp == NULL) {
        std::cout << "NULL" << std::endl;
        return;
    }
    std::cout << temp->data << "->";
    recursive_printList(temp->next);
}

Node* delete_last_node(Node *head_ref) {

    if(head_ref==nullptr) {
        return nullptr;
    }

    if(head_ref->next==nullptr) {
        delete(head_ref);
        return nullptr;
    }
    Node *temp=head_ref;
    while(temp->next->next!=nullptr) {
        temp=temp->next;
    }

    delete(temp->next);
    temp->next=nullptr;
    return head_ref;
}
int search(Node* head_ref, int key) {
    Node* temp = head_ref;
    int pos=0;

    while(temp!=nullptr) {
        if(temp->data==key) {
            return pos;
        }
        temp=temp->next;
        pos++;
    }
    return -1;
}

int rSearch(Node* head_ref, int key, int pos) {

    if(head_ref==nullptr) {
        return -1;
    }

    if(head_ref->data==key) {
        return pos;
    }

    return rSearch(head_ref->next,key,pos+1);
}
using namespace std;

int main() {
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=head;
    head = append(head,40);
    head= prepend(head,50);
    head = effappend(head, 60);
    printList(head);

    // recursive_printList(head);
    // head=prepend(head,5);
    // head= append(head,7);
    // head = insertPos(head, 1, 9);
    // head = delete_last_node(head);
    // printList(head);
    return 0;
}

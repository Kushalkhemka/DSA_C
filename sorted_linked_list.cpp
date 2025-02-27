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
    while (temp != NULL) {
        std::cout << temp->data << "->";
        temp = temp->next;
    }
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
    return prev;
}
Node* RreverseLL(Node* head_ref) {
    if(head_ref==nullptr || head_ref->next==nullptr) {
        return head_ref;
    }
    Node* rest_head = RreverseLL(head_ref->next);
    Node* rest_tail = head_ref->next;
    rest_tail->next = head_ref; //changing link from next to prev (reversing)
    head_ref->next = nullptr;
    return rest_head;
}

void middleNode(Node* head_ref) {
    if(head_ref==nullptr) return;



    Node* slow = head_ref; Node* fast = head_ref;
    while(fast!=nullptr&&fast->next!=nullptr){ //taking care of both odd and even number of nodes //fast!=nullptr is taking care of all cases shortcircuiting
        slow=slow->next;
        fast=fast->next->next;

    }
    std::cout << slow->data << std::endl;
}

Node* removeDuplicate(Node* head_ref) {
    Node* temp = head_ref;
    if(head_ref==nullptr) return nullptr;
    while(temp->next!=nullptr) {
        if(temp->data==temp->next->data) {
            Node* del=temp->next;
            temp->next = del->next;
            delete(del);
        }
        else {
            temp=temp->next;
        }
    }
    return head_ref;
}

Node* insert(Node* head_ref,int data) {
    Node* newNode = new Node(data);
    if(head_ref==nullptr) {
        return newNode;
    }
    if(data<head_ref->data) {
        newNode->next = head_ref;
        return newNode;
    }
    Node* temp = head_ref;
    while(temp->next!=nullptr && temp->next->data<data) {
        temp=temp->next;
    }


    newNode->next=temp->next;
    temp->next=newNode;
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
    printList(head);
    // head = insert(head,25);
    // head = insert(head,40);
    // head = insert(head,7);
    // head = insert(head,20);
    // head = insert(head,20);
    // head = insert(head,30);
    head = removeDuplicate(head);
    head = RreverseLL(head);
    printList(head);
    // middleNode(head);
    // recursive_printList(head);
    // head=prepend(head,5);
    // head= append(head,7);
    // head = insertPos(head, 1, 9);
    // head = delete_last_node(head);
    // printList(head);
    return 0;
}

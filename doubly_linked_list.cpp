#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *insertBegin(Node *head, int data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    if (head!=NULL) head->prev = newNode;
    return newNode;

}

Node *insertEnd(Node *head, int data) {
    Node *newNode = new Node(data);
    Node *cur = head;
    if(head==nullptr) {
        head = newNode;
        return head;
    }
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next=newNode;
    newNode->prev=cur;

    return head;
}

void printList(Node *head_ref) {
    Node *temp=head_ref;
    cout << "Doubly Linked List: ";
    while(temp!=nullptr) {
        cout << temp->data << "<->";
        temp=temp->next;

    }
    cout << "NULL" <<endl;
}

Node* delete_first_node(Node* head_ref) {
    if(head_ref==nullptr) {
        return nullptr;

    }
    if(head_ref->next==NULL) {
        delete(head_ref);
        return NULL;
    }

    Node* temp = head_ref;
    head_ref = head_ref->next;
    head_ref->prev = nullptr;
    delete(temp);
    return head_ref;

}

Node* reverse_DLL(Node* head_ref) {
    Node* current = head_ref; Node* prev=nullptr;
    if(head_ref==nullptr || head_ref->next==nullptr) {
        return head_ref;
    }
    while(current!=nullptr) {
        prev = current->prev;
        current->prev=current->next;
        current->next = prev;
        current=current->prev;
    }
   return prev->prev;

}

Node* delete_last_node(Node* head_ref) {
    Node* curr = head_ref;
    if(head_ref==NULL) {
        return nullptr;
    }
    if(head_ref->next==NULL) {
        delete(head_ref);
        return nullptr;
    }

    while(curr->next->next!=nullptr) {
        curr=curr->next; //second last node
    }
    Node* temp = curr->next;
    curr->next = nullptr;
    delete(temp);
    return head_ref;
}


int main(){
    Node *head = NULL;

    // Inserting at the beginning
    head = insertBegin(head, 10);
    head = insertBegin(head, 20);
    head = insertBegin(head, 30);

    cout << "After inserting at the beginning: " << endl;
    printList(head);

    // Inserting at the end
    // head = insertEnd(head, 40);
    // head = insertEnd(head, 50);
    // head = insertEnd(head, 60);

    cout << "After inserting at the end: " << endl;
    printList(head);
    head = reverse_DLL(head);
    head=delete_first_node(head);
    head = delete_last_node(head);
    printList(head);
}
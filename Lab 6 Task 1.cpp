#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBefore(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void insertAfter(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}


void deleteNode(int key) {
    if (head == NULL) {
        cout << "List is empty"<<endl;
        return;
    }

    Node *curr = head, *prev = NULL;

    if (head->next == head && head->data == key) {
        delete head;
        head = NULL;
        return;
    }

    if (head->data == key) {
        Node* last = head;
        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
        delete curr;
        return;
    }

    do {
        prev = curr;
        curr = curr->next;

        if (curr->data == key) {
            prev->next = curr->next;
            delete curr;
            return;
        }
    } while (curr != head);

    cout << "Value not found!"<<endl;
}

void display() {
    if (head == NULL) {
        cout << "List is empty..."<<endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)";
}

int main() {
    
    // Initially empty list
    cout << "Inserting at beginning:"<<endl;
    insertBefore(10);
    insertBefore(5);
    insertBefore(2);
    display();

    cout << "Inserting at end:"<<endl;
    insertAfter(20);
    insertAfter(30);
    display();

    cout << "Deleting nodes:"<<endl;
    
    cout << "Delete head (2):"<<endl;
    deleteNode(2);
    display();

    cout << "Delete middle (10):"<<endl;
    deleteNode(10);
    display();

    cout << "Delete last (30):"<<endl;
    deleteNode(30);
    display();

    cout << "Delete non-existing (100):"<<endl;
    deleteNode(100);
    display();

    return 0;
}

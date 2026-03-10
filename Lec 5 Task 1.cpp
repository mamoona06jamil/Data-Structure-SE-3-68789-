#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

// Insert at end 
void insertEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Display List
void display() {
    Node* temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Insert at beginning
void addAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;
    else
        tail = newNode;

    head = newNode;
}

// Insert after 45
void addAfter45(int value) {
    Node* temp = head;

    while (temp != NULL && temp->data != 45)
        temp = temp->next;

    if (temp == NULL) {
        cout << "45 not found!";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;
    else
        tail = newNode;

    temp->next = newNode;
}

// Delete at beginning
void deleteBeginning() {
    if (head == NULL) {
        cout << "List is empty!";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;

    delete temp;
}

// Delete node after 45
void deleteAfter45() {
    Node* temp = head;

    while (temp != NULL && temp->data != 45)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        cout << "Deletion not possible...";
        return;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;

    if (delNode->next != NULL)
        delNode->next->prev = temp;
    else
        tail = temp;

    delete delNode;
}

int main() {
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        insertEnd(value);
    }

    display();

    cout << "Insert at beginning: "<<endl;
    cin >> value;
    addAtBeginning(value);
    display();

    cout << "Insert after 45: "<<endl;
    cin >> value;
    addAfter45(value);
    display();

    cout << "Delete at beginning"<<endl;
    deleteBeginning();
    display();

    cout << "Delete after 45"<<endl;
    deleteAfter45();
    display();

    return 0;
}
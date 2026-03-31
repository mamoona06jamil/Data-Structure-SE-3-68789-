#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }

    // Insert at rear (Enqueue)
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Inserted: " << value << endl;
    }

    // Delete from front (Dequeue)
    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow! No elements to delete."<<endl;
            return;
        }

        Node* temp = front;
        cout << "Deleted: " << temp->data << endl;

        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    // Display elements
    void display() {
        if (front == NULL) {
            cout << "Queue is empty."<<endl;
            return;
        }

        Node* temp = front;
        cout << "Queue elements: "<<endl;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "--- Queue Menu (Linked List) ---"<<endl;
        cout << "1. Enqueue"<<endl;
        cout << "2. Dequeue"<<endl;
        cout << "3. Display"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter choice: "<<endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: "<<endl;
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting..."<<endl;
                break;

            default:
                cout << "Invalid choice!"<<endl;
        }

    } 
	while (choice != 4);

    return 0;
}
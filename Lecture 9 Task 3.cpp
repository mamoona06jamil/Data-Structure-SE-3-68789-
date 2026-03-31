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

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow!"<<endl;
            return;
        }

        Node* temp = front;
        cout << "Deleted: " << temp->data << endl;

        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    // Display queue
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

    // Count elements in queue
    int count() {
        int cnt = 0;
        Node* temp = front;

        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "--- Queue Menu ---"<<endl;
        cout << "1. Enqueue"<<endl;
        cout << "2. Dequeue"<<endl;
        cout << "3. Display"<<endl;
        cout << "4. Count Elements"<<endl;
        cout << "5. Exit"<<endl;
        cout << "Enter choice: "<<endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
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
                cout << "Total elements in queue: " << q.count() << endl;
                break;

            case 5:
                cout << "Exiting..."<<endl;
                break;

            default:
                cout << "Invalid choice!"<<endl;
        }

    }
	while (choice != 5);

    return 0;
}
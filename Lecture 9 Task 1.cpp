#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout << "Queue Overflow! Cannot insert element."<<endl;
}
    else {
        if (front == -1) 
            front = 0;

            rear++;
            arr[rear] = value;
        cout << "Inserted: " << value << endl;
        }
    }

    void dequeue() {
    if (front == -1 || front > rear) {
        cout << "No elements to remove."<<endl;
}
    else {
        cout << "Deleted: " << arr[front] << endl;
        front++;

    if (front > rear) {
        front = rear = -1;
    }
}
}

    void display() {
    if (front == -1) {
        cout << "Queue is empty."<<endl;
}
    else {
        cout << "Queue elements: "<<endl;
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
}
        cout << endl;
        }
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "=== Queue Menu ==="<<endl;
        cout << "1. Enqueue"<<endl;
        cout << "2. Dequeue"<<endl;
        cout << "3. Display"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: "<<endl;
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
                cout << "Exiting program..."<<endl;
                break;

            default:
                cout << "Invalid choice! Try again."<<endl;
}
}	
	while (choice != 4);

    return 0;
}
#include <iostream>
using namespace std;

class Inventory {
private:
    int serialNum;
    int manufactYear;
    int lotNum;

public:
    void setData(int s, int m, int l) {
        serialNum = s;
        manufactYear = m;
        lotNum = l;
    }

    void display() {
        cout << "Serial Number: " << serialNum << endl;
        cout << "Manufacturing Year: " << manufactYear << endl;
        cout << "Lot Number: " << lotNum << endl;
        cout << "------------------------" << endl;
    }
};

class Node {
public:
    Inventory data;
    Node* next;

    Node(Inventory i) {
        data = i;
        next = NULL;
    }
};

// Stack Class (Linked List)
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Push
    void push(Inventory i) {
        Node* newNode = new Node(i);
        newNode->next = top;
        top = newNode;
    }

    // Pop
    void pop() {
    if (top == NULL) {
        cout << "Inventory is empty!"<<endl;
    return;
        }

        Node* temp = top;
        cout << "Removed Part Details:"<<endl;
        temp->data.display();

    top = top->next;
    delete temp;
    }

    // Display remaining stack
void display() {
    if (top == NULL) {
        cout << "No items left in inventory."<<endl;
    return;
        }
        Node* temp = top;
        cout << "Remaining Inventory:"<<endl;
        
    while (temp != NULL) {
        temp->data.display();
        temp = temp->next;
        }
    }
};

int main() {
    Stack s;
    int ch;

    do {
        cout << "1. Add Part to Inventory"<<endl;
        cout << "2. Remove Part from Inventory"<<endl;
        cout << "3. Exit"<<endl;
        cout << "Enter choice: "<<endl;
        cin >> ch;

        if (ch == 1) {
        Inventory i;
        int sNum, year, lot;

            cout << "Enter Serial Number: ";
            cin >> sNum;
            cout << "Enter Manufacturing Year: ";
            cin >> year;
            cout << "Enter Lot Number: ";
            cin >> lot;

        i.setData(sNum, year, lot);
        s.push(i);

        cout << "Part added successfully!\n";
}

    else if (ch == 2) {
    s.pop();
}

} 
	while (ch != 3);

    // Display remaining items
    s.display();

    return 0;
}
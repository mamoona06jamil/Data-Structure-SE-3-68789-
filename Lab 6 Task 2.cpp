#include <iostream>
using namespace std;

struct Node {
    string name;
    Node* next;
};

Node* head = NULL;

// Checking if name already exists
bool exists(string name) {
    if (head == NULL) return false;

    Node* temp = head;
    do {
        if (temp->name == name)
            return true;
        temp = temp->next;
    } while (temp != head);

    return false;
}

// Add Employee
void addEmployee(string name) {
    if (exists(name)) {
        cout << "Employee already exists"<<endl;
        return;
    }

    Node* newNode = new Node();
    newNode->name = name;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    cout << "Employee added successfully"<<endl;
}

// Delete Employee
void deleteEmployee(string name) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node *curr = head, *prev = NULL;

    // Single node case
    if (head->next == head && head->name == name) {
        delete head;
        head = NULL;
        cout << "Employee deleted successfully"<<endl;
        return;
    }

    // Delete head
    if (head->name == name) {
        Node* last = head;
        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
        delete curr;

        cout << "Employee deleted successfully"<<endl;
        return;
    }

    // Delete other nodes
    do {
        prev = curr;
        curr = curr->next;

        if (curr->name == name) {
            prev->next = curr->next;
            delete curr;
            cout << "Employee deleted successfully"<<endl;
            return;
        }
    } while (curr != head);

    cout << "Employee not found"<<endl;
}

// Search Employee
void searchEmployee(string name) {
    if (head == NULL) {
        cout << "List is empty"<<endl;
        return;
    }

    Node* temp = head;
    do {
        if (temp->name == name) {
            cout << "Employee found successfully"<<endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Employee not found."<<endl;
}

// Update Employee
void updateEmployee(string oldName, string newName) {
    if (head == NULL) {
        cout << "List is empty!"<<endl;
        return;
    }

    if (exists(newName)) {
        cout << "New name already exists."<<endl;
        return;
    }

    Node* temp = head;
    do {
        if (temp->name == oldName) {
            temp->name = newName;
            cout << "Employee updated successfully."<<endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Employee not found..."<<endl;
}

// Display all employees
void display() {
    if (head == NULL) {
        cout << "No employees"<<endl;
        return;
    }

    Node* temp = head;
    cout << "Employees: "<<endl;
    do {
        cout << temp->name << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)";
}

int main() {
    int choice;
    string name, newName;

    do {
        cout << "\n===== Employee Management System =====\n"<<endl;
        cout << "1. Add Employee"<<endl;
        cout << "2. Delete Employee"<<endl;
        cout << "3. Search Employee"<<endl;
        cout << "4. Update Employee"<<endl;
        cout << "5. Display All"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter choice: "<<endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name: "<<endl;
            cin >> name;
            addEmployee(name);
            break;

        case 2:
            cout << "Enter name to delete: "<<endl;
            cin >> name;
            deleteEmployee(name);
            break;

        case 3:
            cout << "Enter name to search: "<<endl;
            cin >> name;
            searchEmployee(name);
            break;

        case 4:
            cout << "Enter old name: "<<endl;
            cin >> name;
            cout << "Enter new name: "<<endl;
            cin >> newName;
            updateEmployee(name, newName);
            break;

        case 5:
            display();
            break;

        case 0:
            cout << "Exiting..."<<endl;
            break;

        default:
            cout << "Invalid choice."<<endl;
        }

    } while (choice != 0);

    return 0;
}
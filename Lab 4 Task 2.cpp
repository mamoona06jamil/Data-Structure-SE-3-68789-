#include <iostream>
using namespace std;

struct Node {
    string username;
    int age;
    string bio;
    Node* next;
};

Node* head = NULL;

void createProfile() {
    Node* newNode = new Node();

    cout << "Enter Your Username: "<<endl;
    cin >> newNode->username;

    cout << "Enter Your Age: "<<endl;
    cin >> newNode->age;

    cin.ignore();
    cout << "Enter Your Bio: "<<endl;
    getline(cin, newNode->bio);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "Profile Created!"<<endl;
}

Node* searchProfile(string name) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->username == name) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void updateProfile() {
    if (head == NULL) {
        cout << "No profiles available."<<endl;
        return;
    }

    string name;
    cout << "Enter Username to Update: "<<endl;
    cin >> name;

    Node* user = searchProfile(name);

    if (user == NULL) {
        cout << "Profile Not Found!"<<endl;
        return;
    }

    cout << "Enter New Age: "<<endl;
    cin >> user->age;

    cin.ignore();
    cout << "Enter New Bio: "<<endl;
    getline(cin, user->bio);

    cout << "Profile Updated Successfully!"<<endl;
}

void deleteProfile() {
    if (head == NULL) {
        cout << "No profiles available."<<endl;
        return;
    }

    string name;
    cout << "Enter Username to Delete: "<<endl;
    cin >> name;

    Node* temp = head;
    Node* prev = NULL;

    if (temp != NULL && temp->username == name) {
        head = temp->next;
        delete temp;
        cout << "Profile Deleted!"<<endl;
        return;
    }

    while (temp != NULL && temp->username != name) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Profile Not Found..."<<endl;
        return;
    }

    prev->next = temp->next;
    delete temp;

    cout << "Profile Deleted!"<<endl;
}

void viewProfiles() {
    if (head == NULL) {
        cout << "No profiles available."<<endl;
        return;
    }

    Node* temp = head;
    cout << "All User Profiles"<<endl;

    while (temp != NULL) {
        cout << "Username: " << temp->username << endl;
        cout << "Age: " << temp->age << endl;
        cout << "Bio: " << temp->bio << endl;
        cout << "========================="<<endl;
        temp = temp->next;
    }
}

int main() {
    int choice;

    do {
        cout << "1. Create Profile"<<endl;
        cout << "2. Update Profile"<<endl;
        cout << "3. Delete Profile"<<endl;
        cout << "4. Search Profile"<<endl;
        cout << "5. View All Profiles"<<endl;
        cout << "6. Exit"<<endl;
        cout << "Enter Choice: "<<endl;
        cin >> choice;

        switch (choice) {
            case 1:
                createProfile();
                break;
            case 2:
                updateProfile();
                break;
            case 3:
                deleteProfile();
                break;
            case 4: {
                string name;
                cout << "Enter Username to Search: "<<endl;
                cin >> name;

                Node* user = searchProfile(name);

                if (user == NULL) {
                    cout << "Profile Not Found!"<<endl;
                } else {
                    cout << "Username: " << user->username << endl;
                    cout << "Age: " << user->age << endl;
                    cout << "Bio: " << user->bio << endl;
                }
                break;
            }
            case 5:
                viewProfiles();
                break;
            case 6:
                cout << "Exiting Program...";
                break;
            default:
                cout << "Invalid Choice.";
        }

    } while (choice != 6);

    return 0;
}

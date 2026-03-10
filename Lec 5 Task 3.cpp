#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int score;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

int getValidScore() {
    int s;
    cin >> s;
    while (s < 0) {
        cout << "Score cannot be negative. Enter again: ";
        cin >> s;
    }
    return s;
}

// Insert in sorted order (ascending by score)
void addPlayer(string name, int score) {
    Node* newNode = new Node();
    newNode->name = name;
    newNode->score = score;
    newNode->prev = newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
        return;
    }

    Node* temp = head;

    // Insert at beginning
    if (score < head->score) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    // Traverse to find position
    while (temp->next != NULL && temp->next->score <= score) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;
    else
        tail = newNode;

    temp->next = newNode;
}

// Delete player by name
void deletePlayer(string name) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    while (temp != NULL && temp->name != name)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Player not found.\n";
        return;
    }

    if (temp == head)
        head = temp->next;

    if (temp == tail)
        tail = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
    cout << "Player deleted successfully.\n";
}

// Display full list
void displayAll() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "\nPlayers List (Ascending Scores):\n";
    while (temp != NULL) {
        cout << temp->name << " - " << temp->score << endl;
        temp = temp->next;
    }
}

// Display lowest score player(s)
void displayLowest() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    int lowest = head->score;
    Node* temp = head;

    cout << "\nPlayer(s) with Lowest Score:\n";
    while (temp != NULL && temp->score == lowest) {
        cout << temp->name << " - " << temp->score << endl;
        temp = temp->next;
    }
}

// Display players with same score
void displaySameScore(int score) {
    Node* temp = head;
    bool found = false;

    cout << "\nPlayers with Score " << score << ":\n";
    while (temp != NULL) {
        if (temp->score == score) {
            cout << temp->name << endl;
            found = true;
        }
        temp = temp->next;
    }

    if (!found)
        cout << "No players found with this score.\n";
}

// Display backward from given player
void displayBackwardFrom(string name) {
    Node* temp = head;

    while (temp != NULL && temp->name != name)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Player not found.\n";
        return;
    }

    cout << "\nPlayers behind " << name << ":\n";
    temp = temp->prev;

    while (temp != NULL) {
        cout << temp->name << " - " << temp->score << endl;
        temp = temp->prev;
    }
}

int main() {
    int choice;
    string name;
    int score;

    do {
        cout << "\n===== Golf Tournament Menu =====\n"<<endl;
        cout << "1. Add New Player\n"<<endl;
        cout << "2. Delete Player\n"<<endl;
        cout << "3. Display All Players\n"<<endl;
        cout << "4. Display Lowest Score Player(s)\n"<<endl;
        cout << "5. Display Players With Same Score\n"<<endl;
        cout << "6. Display Backward From Player\n"<<endl;
        cout << "7. Exit\n"<<endl;
        cout << "Enter choice: "<<endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Player Name: ";
            cin >> name;
            cout << "Enter Score: ";
            score = getValidScore();
            addPlayer(name, score);
            break;

        case 2:
            cout << "Enter Player Name to Delete: ";
            cin >> name;
            deletePlayer(name);
            break;

        case 3:
            displayAll();
            break;

        case 4:
            displayLowest();
            break;

        case 5:
            cout << "Enter Score: ";
            score = getValidScore();
            displaySameScore(score);
            break;

        case 6:
            cout << "Enter Player Name: ";
            cin >> name;
            displayBackwardFrom(name);
            break;

        case 7:
            cout << "Exiting Program.";
            break;

        default:
            cout << "Invalid choice.";
        }

    } while (choice != 7);

    return 0;
}
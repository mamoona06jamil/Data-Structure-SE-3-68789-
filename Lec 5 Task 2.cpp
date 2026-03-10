#include <iostream>
using namespace std;

struct Node {
    float data;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

float getValidRainfall() {
    float value;
    cin >> value;
    while (value < 0) {
        cout << "Rainfall cannot be negative. Enter again: "<<endl;
        cin >> value;
    }
    return value;
}

void insertEnd(float value) {
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

void calculateRainfall() {
    Node* temp = head;
    float total = 0, max, min;
    int day = 1, maxDay = 1, minDay = 1;

    max = min = head->data;

    while (temp != NULL) {
        total += temp->data;

        if (temp->data > max) {
            max = temp->data;
            maxDay = day;
        }

        if (temp->data < min) {
            min = temp->data;
            minDay = day;
        }

        temp = temp->next;
        day++;
    }

    cout << "Total Rainfall: " << total<<endl;
    cout << "Average Rainfall: " << total / 7<<endl;
    cout << "Highest Rainfall on Day " << maxDay << ": " << max<<endl;
    cout << "Lowest Rainfall on Day " << minDay << ": " << min<<endl;

    // Rainfall after 5th node (6th day)
    temp = head;
    for (int i = 1; i < 6; i++)
        temp = temp->next;

    cout << "Rainfall after 5th day: " << temp->data;
}

int main() {
    float rainfall;

    cout << "Enter rainfall for 7 days:"<<endl;
    for (int i = 1; i <= 7; i++) {
        cout << "Day " << i << ": "<<endl;
        rainfall = getValidRainfall();
        insertEnd(rainfall);
    }

    calculateRainfall();

    return 0;
}
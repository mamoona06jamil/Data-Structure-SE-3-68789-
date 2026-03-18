#include <iostream>
using namespace std;

class Book{
public:
    string title;
    double price;
    int edition;
    int pgs;

    Book (){
        title = "";
        price = 0;
        edition = 0;
        pgs = 0;
    }

    Book (string t, double p, int e, int pg){
        title = t;
        price = p;
        edition = e;
        pgs = pg;
    }

    void display (){
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Edition: "<<edition<<endl;
        cout<<"Pages: "<<pgs<<endl;
        cout<<"----------------"<<endl;
    }
};

class Node{
public:
    Book data;
    Node* next;

    Node (Book b){
        data = b;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack(){
        top = NULL;
    }

    void push(Book b){
        Node* newNode = new Node(b);
        newNode->next = top;
        top = newNode;
    }

    void pop(){
        if (top == NULL){
            cout<<"Stack Underflow!"<<endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;  
    }

    void peek(){
        if (top == NULL){
            cout <<"Stack is empty!"<<endl;
            return;
        }
        cout << "Top Book:"<<endl;
        top->data.display();
    }

    void display(){
        if (top == NULL){
            cout<<"Stack is empty!"<<endl;
            return;
        }
        Node* temp = top;
        cout<<"Books in Stack: "<<endl;
        while (temp!= NULL){
            temp->data.display();
            temp= temp->next;
        }
    }
};

int main(){
    Stack s;

    // Push 5 books
    s.push(Book("Art of Writing", 700, 1, 300));
    s.push(Book("Data Structures", 200, 2, 450));
    s.push(Book("Algorithms", 570, 3, 503));
    s.push(Book("OOP Concepts", 650, 2, 320));
    s.push(Book("Operating Systems", 999, 4, 600));

    // Find top element
    s.peek();

    // Pop 2 books
    cout << "Popping 2 books..."<<endl;
    s.pop();
    s.pop();

    // Display remaining books
    s.display();

    return 0;
}
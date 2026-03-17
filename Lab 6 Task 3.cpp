#include <iostream>
using namespace std;

class Book {
private:
    string bookId;
    string bookName;
    double bookPrice;
    string bookAuthor;
    string bookISBN;

public:
    Book() {
        bookId = "";
        bookName = "";
        bookPrice = 0;
        bookAuthor = "";
        bookISBN = "";
    }

    Book(string id, string name, double price, string author, string isbn) {
        bookId = id;
        bookName = name;
        bookPrice = price;
        bookAuthor = author;
        bookISBN = isbn;
    }

    string getId() { return bookId; }
    string getName() { return bookName; }
    double getPrice() { return bookPrice; }
    string getAuthor() { return bookAuthor; }
    string getISBN() { return bookISBN; }

    void setName(string name) { bookName = name; }
    void setPrice(double price) { bookPrice = price; }
    void setAuthor(string author) { bookAuthor = author; }
    void setISBN(string isbn) { bookISBN = isbn; }
};


class Node {
private:
    Book book;
    Node* next;
    Node* prev;

public:
    Node() {
        next = prev = NULL;
    }

    Node(Book b) {
        book = b;
        next = prev = NULL;
    }

    Book getBook() { return book; }
    Node* getNext() { return next; }
    Node* getPrev() { return prev; }

    void setBook(Book b) { book = b; }
    void setNext(Node* n) { next = n; }
    void setPrev(Node* p) { prev = p; }
};

class BookList {
private:
    Node* head;

public:
    BookList() {
        head = NULL;
    }

    void addBook(string id, string name, double price, string author, string isbn) {
        Book b(id, name, price, author, isbn);
        Node* newNode = new Node(b);

        if (head == NULL) {
            head = newNode;
            head->setNext(head);
            head->setPrev(head);
        } else {
            Node* last = head->getPrev();

            last->setNext(newNode);
            newNode->setPrev(last);

            newNode->setNext(head);
            head->setPrev(newNode);
        }

        cout << "Book added successfully"<<endl;
    }

    // Remove Book
    void removeBook(string id) {
        if (head == NULL) {
            cout << "List is empty"<<endl;
            return;
        }

        Node* temp = head;

        do {
        if (temp->getBook().getId() == id) {

            // Single node
        if (temp->getNext() == head && temp == head) {
            delete temp;
            head = NULL;
}
                // Deleting head
        else if (temp == head) {
            Node* last = head->getPrev();
            head = head->getNext();

            last->setNext(head);
            head->setPrev(last);

            delete temp;
}
                // Other nodes
        else {
        Node* prev = temp->getPrev();
            Node* next = temp->getNext();

        prev->setNext(next);
            next->setPrev(prev);

        delete temp;
}

        cout << "Book deleted successfully.";
        return;
}
    temp = temp->getNext();
}
	while (temp != head);

    cout << "Book not found.";
    }

    // Update Book
    void updateBook(string id, string name, double price, string author, string isbn) {
        if (head == NULL) {
            cout << "List is empty.";
            return;
        }

        Node* temp = head;
        do {
            if (temp->getBook().getId() == id) {
                Book b = temp->getBook();
                b.setName(name);
                b.setPrice(price);
                b.setAuthor(author);
                b.setISBN(isbn);

            temp->setBook(b);

        cout << "Book updated successfully.";
        return;
}
        temp = temp->getNext();
}		while (temp != head);

        cout << "Book not found.";
}

    // Print all books
    void printBooks() {
        if (head == NULL) {
            cout << "No books available";
            return;
        }

        Node* temp = head;
        do {
            Book b = temp->getBook();
            cout << "ID: " << b.getId()
                 << "Name: " << b.getName()
                 << "Price: " << b.getPrice()
                 << "Author: " << b.getAuthor()
                 << "ISBN: " << b.getISBN() << "\n";

            temp = temp->getNext();
        } while (temp != head);
    }

    void printBook(string id) {
        if (head == NULL) {
            cout << "List is empty.";
            return;
        }

        Node* temp = head;
        do {
            if (temp->getBook().getId() == id) {
                Book b = temp->getBook();
                cout << "Book Found:";
                cout << "ID: " << b.getId()
                     << "Name: " << b.getName()
                     << "Price: " << b.getPrice()
                     << "Author: " << b.getAuthor()
                     << "ISBN: " << b.getISBN() << "\n";
                return;
            }
        temp = temp->getNext();
}		 while (temp != head);

        cout << "Book not found.";
    }
};
int main() {
    BookList list;

    // Add 10 books
    list.addBook("B1", "SE", 500, "Aleena", "123");
    list.addBook("B2", "DSA", 600, "Sara", "242");
    list.addBook("B3", "OOP", 700, "Ahmed", "433");
    list.addBook("B4", "DB", 800, "Sara", "465");
    list.addBook("B5", "OS", 900, "Usman", "545");
    list.addBook("B6", "Cyber", 1000, "Rina", "696");
    list.addBook("B7", "COAL", 1100, "Sila", "763");
    list.addBook("B8", "ML", 1200, "Bilal", "878");
    list.addBook("B9", "C", 1300, "Fatima", "999");
    list.addBook("B10", "AI", 1400, "Umar", "1045");

    // Print one book
    list.printBook("B5");

    // Remove (valid + invalid)
    list.removeBook("B3");   // valid
    list.removeBook("B100"); // invalid

    // Print again
    list.printBook("B5");

    // Update book
    list.updateBook("B5", "Operating System", 950, "Usman Khan", "555X");

    // Print updated book
    list.printBook("B5");

    return 0;
}
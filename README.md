# Library Management System

## Objective

To develop a Library Management System that efficiently manages books, members, and borrowing records using Object-Oriented Programming in C++.

## Features

* Add New Books
* Display Available Books
* Search Books by Title
* Search Books by Author
* Issue Books to Members
* Return Issued Books
* Menu-Driven Interface
* Book Availability Tracking

## C++ Source Code

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    int bookId;
    string title;
    string author;
    bool issued;

    Book(int id, string t, string a) {
        bookId = id;
        title = t;
        author = a;
        issued = false;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        int id;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));

        cout << "\nBook Added Successfully!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "\nNo Books Available!\n";
            return;
        }

        cout << "\n------ Book List ------\n";

        for (auto &b : books) {
            cout << "\nBook ID : " << b.bookId;
            cout << "\nTitle   : " << b.title;
            cout << "\nAuthor  : " << b.author;
            cout << "\nStatus  : "
                 << (b.issued ? "Issued" : "Available")
                 << "\n";
        }
    }

    void searchByTitle() {
        string title;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        bool found = false;

        for (auto &b : books) {
            if (b.title == title) {
                cout << "\nBook Found\n";
                cout << "ID: " << b.bookId
                     << "\nAuthor: " << b.author
                     << "\nStatus: "
                     << (b.issued ? "Issued" : "Available")
                     << "\n";

                found = true;
            }
        }

        if (!found)
            cout << "\nBook Not Found!\n";
    }

    void searchByAuthor() {
        string author;
        cin.ignore();

        cout << "Enter Author Name: ";
        getline(cin, author);

        bool found = false;

        for (auto &b : books) {
            if (b.author == author) {
                cout << "\nBook Found\n";
                cout << "ID: " << b.bookId
                     << "\nTitle: " << b.title
                     << "\nStatus: "
                     << (b.issued ? "Issued" : "Available")
                     << "\n";

                found = true;
            }
        }

        if (!found)
            cout << "\nNo Books Found!\n";
    }

    void issueBook() {
        int id;
        cout << "Enter Book ID to Issue: ";
        cin >> id;

        for (auto &b : books) {
            if (b.bookId == id) {
                if (!b.issued) {
                    b.issued = true;
                    cout << "\nBook Issued Successfully!\n";
                } else {
                    cout << "\nBook Already Issued!\n";
                }
                return;
            }
        }

        cout << "\nBook Not Found!\n";
    }

    void returnBook() {
        int id;
        cout << "Enter Book ID to Return: ";
        cin >> id;

        for (auto &b : books) {
            if (b.bookId == id) {
                if (b.issued) {
                    b.issued = false;
                    cout << "\nBook Returned Successfully!\n";
                } else {
                    cout << "\nBook Was Not Issued!\n";
                }
                return;
            }
        }

        cout << "\nBook Not Found!\n";
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n====== Library Management System ======\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search by Title\n";
        cout << "4. Search by Author\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                lib.addBook();
                break;
            case 2:
                lib.displayBooks();
                break;
            case 3:
                lib.searchByTitle();
                break;
            case 4:
                lib.searchByAuthor();
                break;
            case 5:
                lib.issueBook();
                break;
            case 6:
                lib.returnBook();
                break;
            case 7:
                cout << "\nThank You!\n";
                break;
            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 7);

    return 0;
}
```

## Sample Output

```text
====== Library Management System ======
1. Add Book
2. Display Books
3. Search by Title
4. Search by Author
5. Issue Book
6. Return Book
7. Exit

Enter Choice: 1

Enter Book ID: 101
Enter Book Title: C++ Programming
Enter Author Name: Bjarne Stroustrup

Book Added Successfully!
```

## Expected Outcome

The system allows librarians to manage books efficiently by adding new books, searching by title or author, issuing books to members, and processing returns. The menu-driven interface makes operations simple and user-friendly.

## Conclusion

This project demonstrates the use of Object-Oriented Programming concepts such as classes, objects, encapsulation, and vectors in C++. It provides a practical solution for managing library resources and can be further enhanced with file handling and member management features.

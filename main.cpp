#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

class Library {
public:

    void addBook() {
        int id;
        string title, author;

        cout << "\nEnter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        ofstream file("books.txt", ios::app);

        file << id << "|"
             << title << "|"
             << author << "|0" << endl;

        file.close();

        cout << "\nBook Added Successfully!\n";
    }

    void displayBooks() {
        ifstream file("books.txt");

        string line;

        cout << "\n========== BOOK LIST ==========\n";

        bool found = false;

        while (getline(file, line)) {
            found = true;

            size_t p1 = line.find('|');
            size_t p2 = line.find('|', p1 + 1);
            size_t p3 = line.find('|', p2 + 1);

            string id = line.substr(0, p1);
            string title = line.substr(p1 + 1, p2 - p1 - 1);
            string author = line.substr(p2 + 1, p3 - p2 - 1);
            string status = line.substr(p3 + 1);

            cout << "\nBook ID : " << id;
            cout << "\nTitle   : " << title;
            cout << "\nAuthor  : " << author;
            cout << "\nStatus  : "
                 << (status == "0" ? "Available" : "Issued");
            cout << "\n-----------------------------";
        }

        if (!found)
            cout << "\nNo Books Available!\n";

        file.close();
    }

    void searchByTitle() {
        string title;

        cin.ignore();

        cout << "\nEnter Book Title: ";
        getline(cin, title);

        ifstream file("books.txt");

        string line;
        bool found = false;

        while (getline(file, line)) {

            size_t p1 = line.find('|');
            size_t p2 = line.find('|', p1 + 1);

            string fileTitle =
                line.substr(p1 + 1, p2 - p1 - 1);

            if (fileTitle == title) {
                cout << "\nBook Found:\n";
                cout << line << endl;
                found = true;
            }
        }

        if (!found)
            cout << "\nBook Not Found!\n";

        file.close();
    }

    void searchByAuthor() {
        string author;

        cin.ignore();

        cout << "\nEnter Author Name: ";
        getline(cin, author);

        ifstream file("books.txt");

        string line;
        bool found = false;

        while (getline(file, line)) {

            size_t p1 = line.find('|');
            size_t p2 = line.find('|', p1 + 1);
            size_t p3 = line.find('|', p2 + 1);

            string fileAuthor =
                line.substr(p2 + 1, p3 - p2 - 1);

            if (fileAuthor == author) {
                cout << "\nBook Found:\n";
                cout << line << endl;
                found = true;
            }
        }

        if (!found)
            cout << "\nAuthor Not Found!\n";

        file.close();
    }

    void issueBook() {
        int id;

        cout << "\nEnter Book ID to Issue: ";
        cin >> id;

        ifstream file("books.txt");
        ofstream temp("temp.txt");

        string line;
        bool found = false;

        while (getline(file, line)) {

            size_t p1 = line.find('|');
            int bookId = stoi(line.substr(0, p1));

            if (bookId == id) {

                size_t last = line.rfind('|');

                string status = line.substr(last + 1);

                if (status == "1") {
                    cout << "\nBook Already Issued!\n";
                    temp << line << endl;
                }
                else {
                    string updated =
                        line.substr(0, last + 1) + "1";

                    temp << updated << endl;
                    cout << "\nBook Issued Successfully!\n";
                }

                found = true;
            }
            else {
                temp << line << endl;
            }
        }

        file.close();
        temp.close();

        remove("books.txt");
        rename("temp.txt", "books.txt");

        if (!found)
            cout << "\nBook Not Found!\n";
    }

    void returnBook() {
        int id;

        cout << "\nEnter Book ID to Return: ";
        cin >> id;

        ifstream file("books.txt");
        ofstream temp("temp.txt");

        string line;
        bool found = false;

        while (getline(file, line)) {

            size_t p1 = line.find('|');
            int bookId = stoi(line.substr(0, p1));

            if (bookId == id) {

                size_t last = line.rfind('|');

                string status = line.substr(last + 1);

                if (status == "0") {
                    cout << "\nBook Is Already Available!\n";
                    temp << line << endl;
                }
                else {
                    string updated =
                        line.substr(0, last + 1) + "0";

                    temp << updated << endl;
                    cout << "\nBook Returned Successfully!\n";
                }

                found = true;
            }
            else {
                temp << line << endl;
            }
        }

        file.close();
        temp.close();

        remove("books.txt");
        rename("temp.txt", "books.txt");

        if (!found)
            cout << "\nBook Not Found!\n";
    }

    void deleteBook() {
        int id;

        cout << "\nEnter Book ID to Delete: ";
        cin >> id;

        ifstream file("books.txt");
        ofstream temp("temp.txt");

        string line;
        bool found = false;

        while (getline(file, line)) {

            size_t p1 = line.find('|');
            int bookId = stoi(line.substr(0, p1));

            if (bookId == id) {
                found = true;
            }
            else {
                temp << line << endl;
            }
        }

        file.close();
        temp.close();

        remove("books.txt");
        rename("temp.txt", "books.txt");

        if (found)
            cout << "\nBook Deleted Successfully!\n";
        else
            cout << "\nBook Not Found!\n";
    }
};

int main() {

    Library lib;

    int choice;

    do {

        cout << "\n\n========== LIBRARY MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search By Title\n";
        cout << "4. Search By Author\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Delete Book\n";
        cout << "8. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {

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
            lib.deleteBook();
            break;

        case 8:
            cout << "\nThank You For Using Library Management System!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 8);

    return 0;
}


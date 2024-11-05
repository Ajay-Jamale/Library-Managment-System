#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 100; // Limit for simplicity

class Book {
public:
    int id;
    string title;
    string author;
    bool isBorrowed;

    Book() : id(0), title(""), author(""), isBorrowed(false) {}

    void addBook(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        isBorrowed = false;
    }

    void displayBook() {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author
             << ", Status: " << (isBorrowed ? "Borrowed" : "Available") << endl;
    }
};

class Library {
public:
    Book books[MAX_BOOKS];
    int bookCount;

    Library() : bookCount(0) {}

    void addBook(int id, string title, string author) {
        if (bookCount < MAX_BOOKS) {
            books[bookCount].addBook(id, title, author);
            bookCount++;
            cout << "Book added successfully!" << endl;
        } else {
            cout << "Library is full. Cannot add more books." << endl;
        }
    }

    void borrowBook(int id) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == id) {
                if (!books[i].isBorrowed) {
                    books[i].isBorrowed = true;
                    cout << "Book borrowed successfully!" << endl;
                } else {
                    cout << "Book is already borrowed!" << endl;
                }
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void returnBook(int id) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == id) {
                if (books[i].isBorrowed) {
                    books[i].isBorrowed = false;
                    cout << "Book returned successfully!" << endl;
                } else {
                    cout << "Book was not borrowed!" << endl;
                }
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void displayBooks() {
        if (bookCount == 0) {
            cout << "No books in the library." << endl;
            return;
        }
        for (int i = 0; i < bookCount; i++) {
            books[i].displayBook();
        }
    }
};

int main() {
    Library library;
    int choice, id;
    string title, author;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Borrow Book\n";
        cout << "3. Return Book\n";
        cout << "4. Display All Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Book Title: ";
                getline(cin, title);
                cout << "Enter Book Author: ";
                getline(cin, author);
                library.addBook(id, title, author);
                break;

            case 2:
                cout << "Enter Book ID to borrow: ";
                cin >> id;
                library.borrowBook(id);
                break;

            case 3:
                cout << "Enter Book ID to return: ";
                cin >> id;
                library.returnBook(id);
                break;

            case 4:
                cout << "Displaying all books:\n";
                library.displayBooks();
                break;

            case 5:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

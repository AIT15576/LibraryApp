#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Book{
private:
	string title;
	string author;
	string ISBN;
	bool availability;
	string dateAdd;

public:
	//Method to assign values to the book's attributes
	void setBookDetails(string book_title, string book_author, string book_ISBN, bool book_availability, string book_dateAdd) {
		title = book_title;
		author = book_author;
		ISBN = book_ISBN;
		availability = book_availability;
		dateAdd = book_dateAdd;
	}

	//Method to display the book's details
	void displayBookDetails() {
		cout << left << setw(20) << title
			         << setw(20) << author
			         << setw(15) << ISBN
			         << setw(15) << (availability ? "Available" : "Borrowed")
			         << setw(15) << dateAdd << endl;
	}

	//Method to get for ISBN
	string getISBN() const {
		return ISBN;
	}

	//Method to borrow a book
	bool borrowBook() {
		if (availability) {
			availability = false;
			cout << "You have successfully borrowed \"" << title << "\".\n";
			return true;
		}
		else {
			cout << "Sorry, the book \"" << title << "\" is currently unavailable.\n";
			return false;
		}
	}

	//Method to return a book
	void returnBook() {
		availability = true;
		cout << "The book \"" << title << "\" has been returned.\n";
	}

	//Method to sort books by ISBN (simple bubble sort)
	static void sortBookData(Book books[], int n) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (books[j].ISBN > books[j + 1].ISBN) {
					swap(books[j], books[j + 1]);
				}
			}
		}
	}

};

void Display_all_books(int numBooks,Book listBooks[]);

int main() {
	const int amountBooks = 5;
	Book libraryBooks[amountBooks];
	string inputISBN;

	// Initialize 5 books
	libraryBooks[4].setBookDetails("Title book 1", "Author book 1", "12345", true, "2025-01-11");
	libraryBooks[1].setBookDetails("Title book 2", "Author book 2", "23456", false, "2025-02-12");
	libraryBooks[0].setBookDetails("Title book 3", "Author book 3", "34567", true, "2025-03-13");
	libraryBooks[2].setBookDetails("Title book 4", "Author book 4", "45678", false, "2025-04-14");
	libraryBooks[3].setBookDetails("Title book 5", "Author book 5", "56789", true, "2025-05-15");

	// Welcome
	cout << string(85, '*') << endl;
	cout << string(85, '*') << endl;
	cout << string(10, '*') << string(13, ' ');
	cout << "Welcome to the Community Library System";
	cout << string(10, ' ') << string(13, '*') << endl;
	cout << string(85, '*') << endl;
	cout << string(85, '*') << endl << endl;

	int choice;

	do {
		cout << string(40, ' ');
		cout << "Menu" << endl << endl;
		cout << string(25, ' ');
		cout << "1. Display all books\n";
		cout << string(25, ' ');
		cout << "2. Sort all books\n";
		cout << string(25, ' ');
		cout << "3. Borrow a book\n";
		cout << string(25, ' ');
		cout << "4. Return a book\n";
		cout << string(25, ' ');
		cout << "5. Exit\n\n";
		cout << string(25, ' ');
		cout << "Enter your choice (1-5): ";
		cin >> choice;
		cout << string(85, '-') << endl;

		switch (choice) {
		case 1:
			Display_all_books(amountBooks, libraryBooks);
			break;
		case 2:
			// Sort books by ISBN
			Book::sortBookData(libraryBooks, amountBooks);
			break;
		case 3:
			cout << "\nEnter ISBN to borrow a book: ";
			cin >> inputISBN;
			{	// Searching for a book
				bool book_found = false;
				for (int i = 0; i < amountBooks; i++) {
					if (libraryBooks[i].getISBN() == inputISBN) {
						book_found = true;
						libraryBooks[i].borrowBook();
						break;
					}
				}
				if (!book_found) {
					cout << "Sorry, No book found with ISBN " << inputISBN << ". Please try again.\n";
				}
			}
			break;
		case 4:
			cout << "Enter ISBN to return a book: ";
			cin >> inputISBN;
			{	// Searching for a book
				bool book_found = false;
				for (int i = 0; i < amountBooks; i++) {
					if (libraryBooks[i].getISBN() == inputISBN) {
						book_found = true;
						libraryBooks[i].returnBook();
						break;
					}
				}
				if (!book_found) {
					cout << "Sorry, No book found with ISBN " << inputISBN << ". Please try again.\n";
				}
			}
			break;
		case 5:
			// Exit the program
			cout << endl;
			cout << string(85, '*') << endl;
			cout << string(15, ' ');
			cout << "Thank you for using the local community Library System.\n";
			cout << string(40, ' ');
			cout << "Goodbye!\n";
			cout << string(85, '*') << endl;
			break;
		default:
			cout << "Invalid choice. Please enter a number between 1 and 5.\n";
			break;
		}
		cout << string(85, '-') << endl;
	} while (choice != 5);

	return 0;
}

void Display_all_books(int numBooks, Book listBooks[]) {
	// list books
	cout << string(30, ' ');
	cout << "Current Book Collection:" << endl << endl;
	cout << string(85, '-') << endl;
	cout << left << setw(20) << "Title"
		<< setw(20) << "Author"
		<< setw(15) << "ISBN"
		<< setw(15) << "Status"
		<< setw(15) << "Date Added" << endl;
	cout << string(85, '-') << endl;

	for (int i = 0; i < numBooks; i++) {
		listBooks[i].displayBookDetails();
	}
	cout << string(85, '*') << endl;
}
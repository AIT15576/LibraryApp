// Implementation of methods and functions
#include "HeaderFile.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Class Method to assign values to the book's attributes
void Book::setBookDetails(string book_title, string book_author, string book_ISBN, bool book_availability, string book_dateAdd) {
	title = book_title;
	author = book_author;
	ISBN = book_ISBN;
	availability = book_availability;
	dateAdd = book_dateAdd;
}

// Class Method to display the book's details
void Book::displayBookDetails() {
	cout << left << setw(25) << title
		         << setw(20) << author
		         << setw(15) << ISBN
		         << setw(15) << (availability ? "Available" : "Borrowed")
		         << setw(15) << dateAdd;
}

// Class Method to get for ISBN
string Book::getISBN() const {
	return ISBN;
}

// Class Method to borrow a book
bool Book::borrowBook() {
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

// Class Method to return a book
void Book::returnBook() {
	availability = true;
	cout << "The book \"" << title << "\" has been returned.\n";
}

// Class Method to sort books by ISBN (simple bubble sort)
void Book::sortBookData(Book* books[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (books[j]->ISBN > books[j + 1]->ISBN) {
				swap(books[j], books[j + 1]);
			}
		}
	}
}

void HardcopyBook::setShelfNumber(string shelf) {
    shelfNumber = shelf;
}

void HardcopyBook::displayBookDetails() {
    Book::displayBookDetails();
    cout << setw(15) << ("Shelf: " + shelfNumber) << endl;
}

void EBook::setLicenseEnd(string date) {
    licenseEndDate = date;
}

void EBook::displayBookDetails() {
    Book::displayBookDetails();
    cout << setw(1) << ("License: " + licenseEndDate) << endl;
}

// Function to list all books
void displayBooks(int numBooks, Book* listBooks[]) {
	cout << string(30, ' ');
	cout << "Current Book Collection:" << endl << endl;
	cout << string(110, '-') << endl;
	cout << left 
		<< setw(25) << "Title"
		<< setw(20) << "Author"
		<< setw(15) << "ISBN"
		<< setw(15) << "Status"
		<< setw(15) << "Date Added"
		<< "Extra Info\n";
	cout << string(110, '-') << endl;

	for (int i = 0; i < numBooks; i++) {
		listBooks[i]->displayBookDetails();
	}
	cout << string(110, '*') << endl;
}

// Function to display Welcome
void displayWelcome() {
	cout << string(110, '*') << endl;
	cout << string(110, '*') << endl;
	cout << string(10, '*') << string(13, ' ');
	cout << "Welcome to the Community Library System";
	cout << string(10, ' ') << string(38, '*') << endl;
	cout << string(110, '*') << endl;
	cout << string(110, '*') << endl << endl;
}

// Function to display Menu
void displayMenu() {
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
}

// Function to display Goodbye
void displayGoodbye() {
	cout << endl;
	cout << string(110, '*') << endl;
	cout << string(15, ' ');
	cout << "Thank you for using the local community Library System.\n";
	cout << string(40, ' ');
	cout << "Goodbye!\n";
	cout << string(110, '*') << endl;
}

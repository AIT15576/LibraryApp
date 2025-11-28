//command to compile:g++ main.cpp ResourceFile.cpp -o main
//command to compile:g++ main.cpp ResourceFile.cpp -o main -std=c++11 //standar C++11 (the minimum requirement for override)
//command to execute:.\main.exe
#include "HeaderFile.h"
#include <iostream>
using namespace std;

int main() {
	const int amountBooks = 6;
	Book* libraryBooks[amountBooks];
	string inputISBN;

	// Initialize 3 HardcopyBooks
	HardcopyBook hb1, hb2, hb3;

	hb1.setBookDetails("Title Hardcopy book 1", "Author book h1", "12345", true, "2025-01-11");
	hb1.setShelfNumber("A102");

    hb2.setBookDetails("Title Hardcopy book 2", "Author book h2", "34567", false, "2025-01-11");
	hb2.setShelfNumber("B203");

	hb3.setBookDetails("Title Hardcopy book 3", "Author book h3", "56789", true, "2025-01-11");
	hb3.setShelfNumber("C304");
	
	// Initialize 3 EBook
	EBook eb1, eb2, eb3;

	eb1.setBookDetails("Title e book 1", "Author book e1", "23456", false, "2025-01-11");
	eb1.setLicenseEnd("2026-12-31");

    eb2.setBookDetails("Title e book 2", "Author book e2", "45678", true, "2025-01-11");
	eb2.setLicenseEnd("2026-12-31");

	eb3.setBookDetails("Title e book 3", "Author book e3", "67890", false, "2025-01-11");
	eb3.setLicenseEnd("2026-12-31");

	// keep HardcopyBook and EBook
	libraryBooks[0] = &eb3;
	libraryBooks[1] = &hb3;
	libraryBooks[2] = &eb2;
	libraryBooks[3] = &hb2;
	libraryBooks[4] = &eb1;
	libraryBooks[5] = &hb1;

	// Welcome
	displayWelcome();

	int choice;

	do {
		displayMenu();
		cin >> choice;
		cout << string(110, '-') << endl;

		switch (choice) {
		case 1:
			displayBooks(amountBooks, libraryBooks);
			break;
		case 2:
			// Sort books by ISBN
			Book::sortBookData(libraryBooks, amountBooks);
			cout << "Books sorted by ISBN successfully!\n";
			break;
		case 3:
			cout << "\nEnter ISBN to borrow a book: ";
			cin >> inputISBN;
			{
				// Searching for a book
				bool book_found = false;
				for (int i = 0; i < amountBooks; i++) {
					if (libraryBooks[i]->getISBN() == inputISBN) {
						book_found = true;
						libraryBooks[i]->borrowBook();
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
			{
				// Searching for a book
				bool book_found = false;
				for (int i = 0; i < amountBooks; i++) {
					if (libraryBooks[i]->getISBN() == inputISBN) {
						book_found = true;
						libraryBooks[i]->returnBook();
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
			displayGoodbye();
			break;
		default:
			cout << "Invalid choice. Please enter a number between 1 and 5.\n";
			break;
		}
		cout << string(110, '-') << endl;
	} while (choice != 5);
	cin.ignore();
	cin.get();
	return 0;
}

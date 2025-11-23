//command to compile:g++ main.cpp ResourceFile.cpp -o main
//command to execute:.\main.exe
#include "HeaderFile.h"
#include <iostream>
using namespace std;

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
	displayWelcome();

	int choice;

	do {
		displayMenu();
		cin >> choice;
		cout << string(85, '-') << endl;

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
			{
				// Searching for a book
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
			displayGoodbye();
			break;
		default:
			cout << "Invalid choice. Please enter a number between 1 and 5.\n";
			break;
		}
		cout << string(85, '-') << endl;
	} while (choice != 5);
	std::cin.get();
	return 0;
}

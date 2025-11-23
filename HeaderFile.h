#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <string>
using namespace std;

// Book Class Declaration
class Book {
private:
	string title;
	string author;
	string ISBN;
	bool availability;
	string dateAdd;

public:
    // Book Class Methods Declaration
	void setBookDetails(string book_title, string book_author, string book_ISBN, bool book_availability, string book_dateAdd);
	void displayBookDetails();
	string getISBN() const;
	bool borrowBook();
	void returnBook();
	static void sortBookData(Book books[], int n);
};

// Functions Declaration
void displayBooks(int numBooks, Book listBooks[]);
void displayWelcome();
void displayMenu();
void displayGoodbye();

#endif

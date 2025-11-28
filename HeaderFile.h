#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <string>
using namespace std;

// Book Class Declaration
class Book {
protected:
	string title;
	string author;
	string ISBN;
	bool availability;
	string dateAdd;

public:
    // Book Class Methods Declaration
	void setBookDetails(string book_title, string book_author, string book_ISBN, bool book_availability, string book_dateAdd);
	virtual void displayBookDetails();
	string getISBN() const;
	bool borrowBook();
	void returnBook();
	static void sortBookData(Book* books[], int n);
};

// HardcopyBook Class - inherits from Book
class HardcopyBook : public Book {
private:
	string shelfNumber;

public:
	void setShelfNumber(string shelf);
	void displayBookDetails() override;
};

// Ebook Class - inherits from Book
class EBook : public Book {
private:
	string licenseEndDate;

public:
	void setLicenseEnd(string date);
	void displayBookDetails() override;
};

// Functions Declaration
void displayBooks(int numBooks, Book* listBooks[]);
void displayWelcome();
void displayMenu();
void displayGoodbye();

#endif

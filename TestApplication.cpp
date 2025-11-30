// 1. Create a test application
#include <iostream>
#include "HeaderFile.h" // 1.a. import the class implementation and 1.b. sort function implementation.
#include <iomanip>
using namespace std;

void displayHeadInfo();

int main() {

    cout << string(25, ' ');
    cout << "===== TESTING BOOK CLASS =====\n\n";

    // 2. Create three(3) Book instances.
    Book book1, book2, book3;

    // 2.a. Correct initialization.
    cout << string(25, ' ');
    cout << "--- Correct Initialization ---\n\n";

    book1.setBookDetails("Title correct book1", "Author book1", "12345", true, "2025-01-01");
    book2.setBookDetails("Title correct book2", "Author book2", "23456", false, "2025-01-02");
    book3.setBookDetails("Title correct book3", "Author book3", "34567", true, "2025-01-03");

    displayHeadInfo();
    book1.displayBookDetails(); cout << endl;
    book2.displayBookDetails(); cout << endl;
    book3.displayBookDetails(); cout << endl;

    // 2.b. Incorrect initialization.
    cout << endl << endl;
    cout << string(25, ' ');
    cout << "--- Incorrect Initialization ---\n\n";


    book1.setBookDetails("", "", "isbn", true, "");
    book2.setBookDetails("  ", "  ", "-99999", false, "  ");
    book3.setBookDetails("12345", "#####", "?????", false, "date");

    displayHeadInfo();
    book1.displayBookDetails(); cout << endl;
    book2.displayBookDetails(); cout << endl;
    book3.displayBookDetails(); cout << endl;

    // 3. Create an three(3) array to store three(3) books each, 
    //    and add three(3) books in the the array with the different order 

    // 3.a. Ascending order added. 
    Book* ascending[3] = { &book1, &book2, &book3 };
    cout << endl << endl;
    cout << string(25, ' ');
    cout << "--- Before Sorting - Ascending Order Added:\n\n";
    displayHeadInfo();
    for (auto bk : ascending) { 
        bk->displayBookDetails(); 
        cout << endl; 
    }

    // 3.b. Descending  order added. 
    Book* descending[3] = { &book3, &book2, &book1 };
    cout << endl << endl;
    cout << string(25, ' ');
    cout << "--- Before Sorting - Descending Order Added:\n\n";
    displayHeadInfo();
    for (auto bk : descending) {
        bk->displayBookDetails();
        cout << endl;
    }

    // 3.c. Mixed  order added. 
    Book* mixed[3] = { &book2, &book3, &book1 };
    cout << endl << endl;
    cout << string(25, ' ');
    cout << "--- Before Sorting - Mixed Order Added:\n\n";
    displayHeadInfo();
    for (auto bk : mixed) {
        bk->displayBookDetails();
        cout << endl;
    }

    // 4. Call sort function on all three(3) arrays.

    Book::sortBookData(ascending, 3);
    cout << endl << endl;
    cout << string(25, ' ');
    cout << "--- Sorted Ascending Array:\n\n";
    displayHeadInfo();
    for (auto bk : ascending) {
        bk->displayBookDetails(); 
        cout << endl; 
    }

    Book::sortBookData(descending, 3);
    cout << endl << endl;
    cout << string(25, ' ');
    cout << "--- Sorted Descending Array:\n\n";
    displayHeadInfo();
    for (auto bk : descending) { 
        bk->displayBookDetails(); 
        cout << endl; 
    }

    Book::sortBookData(mixed, 3);
    cout << endl << endl;
    cout << string(25, ' ');
    cout << "--- Sorted Mixed Array:\n\n";
    displayHeadInfo();
    for (auto bk : mixed) { 
        bk->displayBookDetails(); 
        cout << endl; 
    }

    cout << endl << endl;
    cout << string(25, ' ');
    cout << "===== TESTING COMPLETE =====\n";

    cin.ignore();
    cin.get();
    return 0;
}

void displayHeadInfo() {
    cout << left
        << setw(25) << "Title"
        << setw(20) << "Author"
        << setw(15) << "ISBN"
        << setw(15) << "Status"
        << setw(15) << "Date Added" << endl;
    cout << string(85, '-') << endl;
}

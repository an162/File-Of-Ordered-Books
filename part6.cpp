#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

struct Author {
    string firstName;
    string lastName;
    int age;
};

struct Book {
    string title;
    Author author;
    int yearPublished;
    int numPages;
    float price;
};

bool compareBooks(const Book& a, const Book& b) {
    return a.yearPublished < b.yearPublished;
}

int main() {
    int numBooks;
    cout << "Enter number of books: ";
    cin >> numBooks;

    Book* books = new Book[numBooks];

    for (int i = 0; i < numBooks; i++) {
        cout << "Enter information for book #" << i + 1 << ":" << endl;
        cin.ignore(); // ignore newline character left by previous input
        cout << "Title: ";
        getline(cin, books[i].title);
        cout << "Author's first name: ";
        getline(cin, books[i].author.firstName);
        cout << "Author's last name: ";
        getline(cin, books[i].author.lastName);
        cout << "Author's age: ";
        cin >> books[i].author.age;
        cout << "Year published: ";
        cin >> books[i].yearPublished;
        cout << "Number of pages: ";
        cin >> books[i].numPages;
        cout << "Price: $";
        cin >> books[i].price;
    }

    sort(books, books + numBooks, compareBooks);

    ofstream outfile("books.csv");
    if (!outfile) {
        cout << "Error: could not open file" << endl;
        return 1;
    }

    outfile << "Title,Author,Year Published,Number of Pages,Price" << endl;
    for (int i = 0; i < numBooks; i++) {
        outfile << books[i].title << ","
                << books[i].author.firstName << " " << books[i].author.lastName << ","
                << books[i].yearPublished << ","
                << books[i].numPages << ","
                << books[i].price << endl;
    }
    outfile.close();

    cout << "List of books (sorted by year of publication):" << endl;
    for (int i = 0; i < numBooks; i++) {
        cout << "Title: " << books[i].title << endl;
        cout << "Author: " << books[i].author.firstName << " " << books[i].author.lastName
             << ", age " << books[i].author.age << endl;
        cout << "Year published: " << books[i].yearPublished << endl;
        cout << "Number of pages: " << books[i].numPages << endl;
        cout << "Price: $" << books[i].price << endl << endl;
    }

    delete[] books;

    return 0;
}

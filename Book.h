// Jareth Franco
// October 26, 2026
// Purpose: Define a book's title, author, price, and display method.
#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    double price;

public:
    Book(const std::string& title, const std::string& author, double price);
    void displayInfo() const;
};

#endif
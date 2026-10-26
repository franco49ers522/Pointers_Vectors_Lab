// Jareth Franco
// October 26, 2026
// Purpose: Initialize and display book information.
#include "Book.h"
#include <iomanip>
#include <iostream>

Book::Book(const std::string& title, const std::string& author, double price)
    : title(title), author(author), price(price) {
}

void Book::displayInfo() const {
    std::cout << "Title: " << title << '\n'
              << "Author: " << author << '\n'
              << "Price: $" << std::fixed << std::setprecision(2) << price << '\n';
}
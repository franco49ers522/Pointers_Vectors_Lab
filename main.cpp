// Jareth Franco
// October 26, 2026
// Purpose: Run a menu-driven book inventory using pointers and RAII.
#include "Inventory.h"
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

// Read a whole line so bad input cannot leave the menu stuck in a loop.
template <typename T>
bool readNumber(const std::string& prompt, T& number) {
    std::string line;
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, line)) {
            return false;
        }
        std::istringstream input(line);
        char extra;
        if ((input >> number) && !(input >> extra)) {
            return true;
        }
        std::cout << "Please enter a valid number.\n";
    }
}

bool readText(const std::string& prompt, std::string& text) {
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, text)) {
            return false;
        }
        if (text.find_first_not_of(" \t\r") != std::string::npos) {
            return true;
        }
        std::cout << "This field cannot be blank.\n";
    }
}

int main() {
    Inventory store;
    int choice;

    std::cout << "Book Inventory\n";
    while (true) {
        std::cout << "\n1. Add New Book\n"
                  << "2. Display All Books\n"
                  << "3. Remove Book\n"
                  << "4. Quit\n";

        if (!readNumber("Choose an option: ", choice)) {
            break;
        }

        if (choice == 1) {
            std::string title;
            std::string author;
            double price;

            if (!readText("Title: ", title) || !readText("Author: ", author)) {
                break;
            }
            bool havePrice = false;
            while (readNumber("Price: $", price)) {
                if (std::isfinite(price) && price >= 0.0) {
                    havePrice = true;
                    break;
                }
                std::cout << "Price must be a finite, nonnegative number.\n";
            }
            if (!havePrice) {
                break;
            }

            // Inventory takes ownership and handles the book's lifetime.
            store.addBook(new Book(title, author, price));
            std::cout << "Book added.\n";
        } else if (choice == 2) {
            store.displayAll();
        } else if (choice == 3) {
            store.displayAll();
            int index;
            if (!readNumber("Book index to remove (starts at 0): ", index)) {
                break;
            }
            store.removeBook(index);
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Please choose an option from 1 to 4.\n";
        }
    }

    std::cout << "Goodbye!\n";
    // No manual deletion here: store's destructor cleans up remaining books.
    return 0;
}
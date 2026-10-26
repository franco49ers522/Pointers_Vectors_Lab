// Jareth Franco
// October 26, 2026
// Purpose: Add, display, remove, and automatically clean up owned books.
#include "Inventory.h"
#include <iostream>

Inventory::~Inventory() {
    // RAII: free every remaining book when this inventory leaves scope.
    for (Book* bookPtr : books) {
        delete bookPtr;
    }
}

void Inventory::addBook(Book* bookPtr) {
    if (bookPtr == nullptr) {
        return;
    }

    // If vector allocation fails, the incoming book still needs cleanup.
    try {
        books.push_back(bookPtr);
    } catch (...) {
        delete bookPtr;
        throw;
    }
}

void Inventory::displayAll() const {
    if (books.empty()) {
        std::cout << "The inventory is empty.\n";
        return;
    }

    for (std::size_t i = 0; i < books.size(); ++i) {
        std::cout << "\nBook index " << i << ":\n";
        books[i]->displayInfo();
    }
}

void Inventory::removeBook(int index) {
    if (index < 0 || static_cast<std::size_t>(index) >= books.size()) {
        std::cout << "Invalid book index. No book was removed.\n";
        return;
    }

    // Delete the object before erasing its pointer from the vector.
    delete books[index];
    books.erase(books.begin() + index);
    std::cout << "Book removed.\n";
}
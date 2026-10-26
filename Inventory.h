// Jareth Franco
// October 26, 2026
// Purpose: Define an inventory that owns dynamically allocated books.
#ifndef INVENTORY_H
#define INVENTORY_H

#include "Book.h"
#include <vector>

class Inventory {
private:
    std::vector<Book*> books;

public:
    Inventory() = default;
    ~Inventory();

    // Copying owning pointers would cause the same books to be deleted twice.
    Inventory(const Inventory&) = delete;
    Inventory& operator=(const Inventory&) = delete;

    // Ownership of a new, non-null book transfers to this inventory.
    void addBook(Book* bookPtr);
    void displayAll() const;
    void removeBook(int index);
};

#endif
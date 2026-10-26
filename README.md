# Pointers and Vectors Lab

Jareth Franco  
October 26, 2026

This is a menu-based book inventory for the pointers and RAII lab. You can add a book, display the inventory, remove a book by its index, or quit.

## Build and run

Use a C++17 compiler:

```sh
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp Book.cpp Inventory.cpp -o book_inventory
./book_inventory
```

On Windows, run `book_inventory.exe`. The project can also be opened in CLion using `CMakeLists.txt`.

## How it works

`Book` keeps its title, author, and price private. `Inventory` owns the book pointers in a `std::vector<Book*>`. Removing a book deletes it before erasing its pointer. When the inventory goes out of scope, its destructor deletes all remaining books. There is no manual cleanup in `main`.

Book indexes start at **0** and are shown when the inventory is displayed. Removing a book shifts later indexes down by one. Titles and authors can contain spaces, prices must be nonnegative, and invalid menu choices or indexes do not change the inventory. Ending input also exits normally and lets the destructor run.

Inventory copying is disabled because copying the raw pointers would make two inventories try to delete the same objects.
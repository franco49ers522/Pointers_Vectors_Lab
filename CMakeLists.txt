cmake_minimum_required(VERSION 3.16)
project(Pointers_Vectors_Lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(book_inventory main.cpp Book.cpp Inventory.cpp)
# Library Management System

This is a basic **Library Management System** implemented in C++ that allows users to:
- Add new books to the library
- Issue books by their unique ID
- Return issued books
- Check the availability of books
- Save and load library data to and from a file

This project demonstrates object-oriented programming (OOP) concepts such as classes, encapsulation, and file handling in C++. It can be easily extended with additional features like member management, fine calculation, etc.

## Features

- **Add Book**: Add a new book by specifying its ID, title, and author.
- **Issue Book**: Issue a book by its unique ID if it is available.
- **Return Book**: Return a previously issued book by its unique ID.
- **Check Availability**: Check whether a book is available or issued.
- **Data Persistence**: Save library data to a file (`library_data.txt`) and load it on program start.

## Getting Started

### Prerequisites
- C++ compiler (such as `g++` or `clang`)

### How to Run

1. Clone the repository:
    ```bash
    git clone https://github.com/anushreemehta6/library-management-system.git
    cd library-management-system
    ```

2. Compile the program:
    ```bash
    g++ -o library library_management.cpp
    ```

3. Run the executable:
    ```bash
    ./library
    ```

4. Follow the on-screen menu to interact with the Library Management System.

## Menu Options

When you run the program, you will be presented with the following options:

1. **Add Book**: Enter the book's ID, title, and author to add a new book to the library.
2. **Issue Book**: Provide the book's ID to issue a book. If it's already issued, you'll be notified.
3. **Return Book**: Provide the book's ID to return an issued book. If the book is not issued, you'll be notified.
4. **Check Availability**: Enter the book's ID to see if it’s issued or available.
5. **Exit**: Save the current library state to a file and exit the program.

## File Handling

- **Saving**: When exiting the program, all the books and their statuses (issued or available) are saved to a file (`library_data.txt`).
- **Loading**: When the program starts, it attempts to load the library data from `library_data.txt`. If no data is found, it starts with an empty library.

## Code Overview

### `Book` Class
Represents a book with attributes such as:
- `bookId`: Unique ID of the book
- `title`: Title of the book
- `author`: Author's name
- `isIssued`: Status of whether the book is issued or not

Key methods:
- `issuebook()`: Marks the book as issued if it's not already issued.
- `returnbook()`: Marks the book as returned.
- `displaydetails()`: Displays the book's details and current status.
- `saveToFile()` and `loadFromFile()`: File operations for persisting book data.

### `Library` Class
Handles the collection of books and provides operations such as:
- `addBook()`: Add a new book to the collection.
- `issuebook()`: Issue a book by its ID.
- `returnbook()`: Return a book by its ID.
- `check()`: Check a book's availability by its ID.
- `saveData()` and `loadData()`: Save and load the entire library collection to/from a file.



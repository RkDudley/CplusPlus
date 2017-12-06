//*********************************************************************
// Elienai Fasano
// BookStore - 11/14/2017
// This class specifies the basic operation with Inventory Data Members
// It is a Inventory Declaration Class
//		Using: ***Linked List***
//
//**********************************************************************


#ifndef INVENTORY_H
#define INVENTORY_H

#include "Book.h"

class Inventory
{
private:
	typedef struct node // create new name for node* as now nodePtr
	{
		Book data;		// data of the book
		int quantity;	// number of book
		node* next;		// pointer to next node of book inventory.
	}
	* nodePtr; // new name of node pointer

	nodePtr head;	// pointer to the first book node.

	nodePtr Search(const Book& searchBook) const;
	//	Helper function to find a node by the book object.
	//	Precondition:	searchBook is a Book ooect with valid ISBN.
	//	Postcondition:	Pointer of the node will be returned if found. 
	//					If the book is not found, NULL will be return.

public:	// Here we determine the functions of this class
	Inventory();	// Constructor

	void PrintList() const;
	//	Function to print all books details information.
	//	Precondition:	Inventory should have some book records.
	//	Postcondition:	isbn, title, author, publisher, category, price 
	//					and quantity will be print on the screen.

	Book* SearchBook(long long isbn) const;
	//	Function to find a book by ISBN.
	//	Precondition:	isbn should be a valid number (10-13 digits).
	//	Postcondition:	Pointer of the book will be returned if found. 
	//					If the book is not found, NULL will be return.

	void AddEditBooks(const Book& addBook, int numOfCopy);
	//	Function to Add books to the inventory.
	//	Precondition:	addBook is a book object with valid book details. 
	//					If add book to existing record, addBook should has a valid isbn (10-13 digits).
	//					numOfCopy is the quantity of this book to be added, must be greater than 0.
	//	Postcondition:	If book exist in inventory, quantity will be updated.
	//					If book doesn't exist, a new book record wil be insert in the order of ISBN.

	void RemoveBooks(const Book& rmBook, int numOfCopy);
	//	Function to Remove books from the inventory.
	//	Precondition:	rmBook should has a valid isbn (10-13 digits).
	//					numOfCopy is the quantity of this book to be added, must be greater than 0.
	//	Postcondition:	If book exist in inventory, quantity will be updated.
	//					If book quantity is out of stock, quantity will be 0 and book record will not be deleted.
	//					If numOfCopy is largest than quantity, error message will diplay and operation will not be completed.

	int getBookQty(const Book& lookupBook);
	//	Function to get current quantity of specific book.
	//	Precondition:	lookupBook should has a valid isbn (10-13 digits).
	//	Postcondition:	Quantity of book with the same isbn will be returned.
	//					If no book is found, error message will diplay.

	void loadInventoryFile();
	//	Function to read inventory books from a text file.
	//	Precondition:	"inventory.txt" must exist under BookStore folder with valid data.
	//	Postcondition:	Books in the file will be stored in the inventory .

	void saveInventoryFile();
	//	Function to write inventory books to a text file.
	//	Precondition:	Inventory has valid books records.
	//	Postcondition:	"inventory.txt" will be create or overwriten with books records.

};

#endif
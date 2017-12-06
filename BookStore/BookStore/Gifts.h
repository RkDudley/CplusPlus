//*********************************************************************
// Elienai Fasano
// BookStore - 11/14/2017
// This class specifies the basic operation with Gifts Data Members
// It is a Gifts Declaration Class
//		Using: ***Array Stack***
//
//**********************************************************************


#ifndef GIFTS_H
#define GIFTS_H

#include "Book.h"

class Gifts
{
private:

	Book giftBooks[100];
	int numOfBooks;

public:	// Here we determine the functions of this class
	Gifts();	// Constructor

	void PrintList() const;
	//	Function to print all books details information.
	//	Precondition:	Gifts should have some book records.
	//	Postcondition:	isbn, title, author, publisher, category, price 
	//					will be print on the screen.

	void push_back(const Book& addBook);
	//	Function to Add books to the inventory.
	//	Precondition:	addBook is a book object with valid book details. 
	//					If add book to existing record, addBook should has a valid isbn (10-13 digits).
	//	Postcondition:	A book record wil be insert in the gifts section.

	Book* top();
	//  Funciton to access next element
	//	Precondition:	gifts section should have some books
	//	Postcondition:	If book exist in gifts section, a pointer of the next book will be returned.				

	void pop_back();
	//	Function to remove top element
	//	Precondition:	gifts section should have some books
	//	Postcondition:	If book exist in gifts section, numOfBooks will be subtract by 1.				

	int size();
	//	Function to get current quantity of gifts book.
	//	Postcondition:	Number of books avaialbe to gift out will be returned.

	bool isEmpty();
	// Function to test whether container is empty.
	// Postcondition: Return true if gifts section has books, false if no book.

	void loadGiftsFile();
	//	Function to read gifts books from a text file.
	//	Precondition:	"gifts.txt" must exist under BookStore folder with valid data.
	//	Postcondition:	Books in the file will be stored in the gifts .

	void saveGiftsFile();
	//	Function to write gifts books to a text file.
	//	Precondition:	gifts has valid books records.
	//	Postcondition:	"gifts.txt" will be create or overwriten with books records.

};

#endif
//**********************************************************
// Elienai Fasano
// BookStore - 11/14/2017
// This class specifies the definition of the functions from 
//      Inventory declaration class
//  
//**********************************************************


#include <iostream> // for input and output
#include <fstream>	// for file IO
#include <sstream>	// for convert string

#include "Inventory.h"

// Constructor
Inventory::Inventory()
{
	head = NULL;
}
//	Helper function to find a node by the book object.
//	Precondition:	searchBook is a Book ooect with valid ISBN.
//	Postcondition:	Pointer of the node will be returned if found. 
//					If the book is not found, NULL will be return.
Inventory::nodePtr Inventory::Search(const Book& searchBook) const
{
	// Exit function when searchBook is NULL
	if (&searchBook == NULL)
		return NULL;

	// Start the search form the first Node.
	nodePtr searchPtr = head;

	// Exit the loop when reach the end of the linked-list,
	// or data in node match the searchBook object.
	while (searchPtr != NULL && searchPtr->data != searchBook)
	{
		searchPtr = searchPtr->next;
	}

	// searchPtr is NULL when book is not found in inventory.
	if (searchPtr == NULL)
	{
		return NULL;
	}
	else	// Book is found.
	{
		// return the reference of the book found.
		return searchPtr;		// & - reference of
	}
}
//	Function to print all books details information.
//	Precondition:	Inventory should have some book records.
//	Postcondition:	isbn, title, author, publisher, category, price 
//					and quantity will be print on the screen.
void Inventory::PrintList() const
{
	nodePtr curr = head;
	while (curr != NULL)
	{
		// Print book details by calling book's printDetails function.
		curr->data.printDetails();

		// Print quantity information.
		cout << "\t Qty: " << curr->quantity << endl;
		cout << "------------------------------------------" << endl;
		
		// Move to next loop.
		curr = curr->next;
	}
}
//	Function to find a book by ISBN.
//	Precondition:	isbn should be a valid number (10-13 digits).
//	Postcondition:	Pointer of the book will be returned if found. 
//					If the book is not found, NULL will be return.
Book* Inventory::SearchBook(long long isbn) const
{
	// Create a book oject with the ISBN we are searching for.
	Book lookupBook = Book();
	lookupBook.setIsbn(isbn);

	// Use the book object to search for the book.
	nodePtr bookPtr = Search(lookupBook);

	// bookPtr is NULL when book is not found in inventory.
	if (bookPtr == NULL)
	{
		cout << "Book was not in the list\n";
		return NULL;
	}
	else	// Book is found.
	{
		// return the reference of the book found.
		return &bookPtr->data;		// & - reference of
	}
}
//	Function to Add books to the inventory.
//	Precondition:	addBook is a book object with valid book details. 
//					If add book to existing record, addBook should has a valid isbn (10-13 digits).
//					numOfCopy is the quantity of this book to be added, must be greater than 0.
//	Postcondition:	If book exist in inventory, quantity will be updated.
//					If book doesn't exist, a new book record wil be insert in the order of ISBN.
void Inventory::AddEditBooks(const Book& addBook, int numOfCopy)
{
	// Exit function when lookupBook is NULL
	if (&addBook == NULL)
	{
		cout << "Incorrect Book information.\n";
		return;
	}

	// Exit function when numOfCopy is smaller than 0.
	if (numOfCopy < 0)
	{
		cout << "Incorrect number of books to add. Please try again.\n";
		return;
	}
	
	nodePtr currPtr = head;

	// Pointer to mark the location to put the Book Node, if Book is not found in inventory.
	nodePtr insertPtr = NULL;

	// Exit the loop when reach the end of the linked-list,
	// or data in node match the searchBook object.
	while (currPtr != NULL && currPtr->data != addBook)
	{
		// Move insertPtr to currPtr when addBook's ISBN is greater than currPtr's ISBN.
		if (currPtr->data < addBook)
		{
			insertPtr = currPtr;
		}

		// Move to next loop.
		currPtr = currPtr->next;
	}

	
	if (currPtr != NULL)
	{
		// Book with same ISBN existed, avoid duplicate book data, Update book infotmation.
		currPtr->data = addBook;
		currPtr->quantity = numOfCopy;
		cout << "Existing Book record found, updating book informations. Updated Quantity: " << currPtr->quantity << endl;
	}
	else	// currPtr is NULL when book is not exist in inventory.
	{
		// Create a new node for the new book.
		nodePtr newBookNode = new node;
		
		newBookNode->next = NULL;
		newBookNode->data = addBook;
		newBookNode->quantity = numOfCopy;

		
		if (head == NULL)
		{
			// The list is empty, newBookNode is the first node.
			head = newBookNode;
		}
		else if (insertPtr == NULL)
		{
			//newBookNode is the first node, connect the rest of list after newBookNode.
			newBookNode->next = head;
			head = newBookNode;
		}
		else
		{
			// newBookNode insert after the insertPtr, connect the rest of list after newBookNode.
			newBookNode->next = insertPtr->next;
			insertPtr->next = newBookNode;
		}
	}

}
//	Function to Remove books from the inventory.
//	Precondition:	rmBook should has a valid isbn (10-13 digits).
//					numOfCopy is the quantity of this book to be added, must be greater than 0.
//	Postcondition:	If book exist in inventory, quantity will be updated.
//					If book quantity is out of stock, quantity will be 0 and book record will not be deleted.
//					If numOfCopy is largest than quantity, error message will diplay and operation will not be completed.
void Inventory::RemoveBooks(const Book& rmBook, int numOfCopy)
{
	// Exit function when rmBook is NULL
	if (&rmBook == NULL)
	{
		cout << "Incorrect Book information.\n";
		return;
	}

	// Exit function when numOfCopy is smaller than 1.
	if (numOfCopy <= 0)
	{
		cout << "Incorrect number of books to remove. Please try again.\n";
		return;
	}

	// Use the book object to search for the book.
	nodePtr bookPtr = Search(rmBook);

	if (bookPtr != NULL)
	{
		// Book exist, check numOfCopy should not graeter than quantity. (avoid negative quantity)
		if (numOfCopy > bookPtr->quantity)
		{
			cout << "Not enough number of books in the inventory. Please try again.\n";
			return;
		}
		
		// Update quantity
		bookPtr->quantity -= numOfCopy;

		cout << numOfCopy << " book(s) was removed from inventory. Current quantity: "
			<< bookPtr->quantity << endl;

		// Warning of book is out of stock 
		if (bookPtr->quantity == 0)
			cout <<"This book is now out of stock.\n";
	}
	else	// Book is not found.
	{
		cout << "Book was not in the list\n";
	}
}
//	Function to get current quantity of specific book.
//	Precondition:	lookupBook should has a valid isbn (10-13 digits).
//	Postcondition:	Quantity of book with the same isbn will be returned.
//					If no book is found, error message will diplay.
int Inventory::getBookQty(const Book& lookupBook)
{
	// Exit function when lookupBook is NULL
	if (&lookupBook == NULL)
	{
		cout << "Incorrect Book information.\n";
		return 0;
	}

	// Use the book object to search for the book.
	nodePtr bookPtr = Search(lookupBook);

	// bookPtr is NULL when book is not found in inventory.
	if (bookPtr == NULL)
	{
		cout << "Book was not in the list\n";
		return 0;
	}
	else  // Book is found
	{
		return bookPtr->quantity;
	}
}
//	Function to read inventory books from a text file.
//	Precondition:	"inventory.txt" must exist under BookStore folder with valid data.
//	Postcondition:	Books in the file will be stored in the inventory .
void Inventory::loadInventoryFile()
{
	// Reading inventory book data from file.
	ifstream inventoryfile("inventory.txt");
	if (inventoryfile.is_open())
	{
		cout << "Loading inventory books data from \"inventory.txt.\"\n";

		// Clean up inventory linked list, delete all the nodes.
		nodePtr currPtr = head;
		nodePtr deletePtr;

		// Exit the loop when reach the end of the linked-list
		while (currPtr != NULL)
		{
			deletePtr = currPtr;
			currPtr = currPtr->next;
			delete deletePtr;
		}

		// Loop continue when it is not the end of file.
		while (!inventoryfile.eof())
		{
			Book newBook;
			// Call Book class method to read data.
			stringstream restOfSS = newBook.readFile(&inventoryfile);

			// Read quantity of the book.
			int quantity;
			// Converting stringstream to int.
			restOfSS >> quantity;

			// After book data read from file store the book to inventory. 
			AddEditBooks(newBook, quantity);
		}

		// Complete all lines of record, closing file.
		inventoryfile.close();
	}
	else
	{
		// File cannot open.
		cout << "Error: Unable to open inventory records file.";
	}
}
//	Function to write inventory books to a text file.
//	Precondition:	Inventory has valid books records.
//	Postcondition:	"inventory.txt" will be create or overwriten with books records.
void Inventory::saveInventoryFile()
{
	ofstream inventoryfile("inventory.txt");
	if (inventoryfile.is_open())
	{
		cout << "Saving inventory books into \"inventory.txt.\"\n";
		nodePtr currPtr = head;

		// Exit the loop when reach the end of the linked-list
		while (currPtr != NULL )
		{
			// write book data
			currPtr->data.writeFile(&inventoryfile);
			// add quantity at the back of the string.
			inventoryfile << "|" << currPtr->quantity;
			currPtr = currPtr->next;
			if (currPtr!=NULL)
				inventoryfile << endl;
		}
		
		inventoryfile.close();
	}
	else
	{
		cout << "Unable to open file";
	}
}


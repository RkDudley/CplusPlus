//**********************************************************
// Elienai Fasano
// BookStore - 11/14/2017
// This class specifies the definition of the functions from 
//      Gifts declaration class
//  
//**********************************************************


#include <iostream> // for input and output
#include <fstream>	// for file IO
#include <sstream>
#include "Gifts.h"

// Constructor
Gifts::Gifts()
{
	numOfBooks = 0;
}
//	Function to print all books details information.
//	Precondition:	Gifts should have some book records.
//	Postcondition:	isbn, title, author, publisher, category, price 
//					will be print on the screen.
void Gifts::PrintList() const
{
	
	for (int i = numOfBooks - 1; i >= 0; i--)
	{
		// Print book details by calling book's printDetails function.
		giftBooks[i].printDetails();

		cout << "\n------------------------------------------" << endl;
		
	}
}
//	Function to Add books to the inventory.
//	Precondition:	addBook is a book object with valid book details. 
//					If add book to existing record, addBook should has a valid isbn (10-13 digits).
//	Postcondition:	A book record wil be insert in the gifts section.
void Gifts::push_back(const Book& addBook)
{
	// Exit function when addBook is NULL
	if (&addBook == NULL)
	{
		cout << "Incorrect Book information.\n";
		return;
	}
	
	if (numOfBooks >= 100)
	{
		cout << "Not enough space on the self.\n";
		return;
	}

	giftBooks[numOfBooks] = addBook;
	numOfBooks++;
}
//  Funciton to access next element
//	Precondition:	gifts section should have some books
//	Postcondition:	If book exist in gifts section, a pointer of the next book will be returned.			
Book* Gifts::top()
{
	if (numOfBooks <= 0)
		return NULL;
	else
		return &giftBooks[numOfBooks - 1];
}
//	Function to remove top element
//	Precondition:	gifts section should have some books
//	Postcondition:	If book exist in gifts section, numOfBooks will be subtract by 1.	
void Gifts::pop_back()
{
	// Exit function when numOfBooks is smaller than 0.
	if (numOfBooks <= 0)
	{
		cout << "Gifts section is empty.\n";
		return;
	}

	numOfBooks--;

}
//	Function to get current quantity of gifts book.
//	Postcondition:	Number of books avaialbe to gift out will be returned.
int Gifts::size()
{
	return numOfBooks;
}
// Function to test whether container is empty.
// Postcondition: Return true if gifts section has books, false if no book.
bool Gifts::isEmpty()
{
	return (numOfBooks <= 0);
}
//	Function to read gifts books from a text file.
//	Precondition:	"gifts.txt" must exist under BookStore folder with valid data.
//	Postcondition:	Books in the file will be stored in the gifts .
void Gifts::loadGiftsFile()
{
	// Reading gift book data from file.
	ifstream giftsfile("gifts.txt");
	if (giftsfile.is_open())
	{
		cout << "Loading gifts books data from \"gifts.txt.\"\n";

		// Clean up all gift
		numOfBooks = 0;

		// Loop continue when it is not the end of file.
		while (!giftsfile.eof())
		{
			Book newBook;
			// Call Book class method to read data.
			newBook.readFile(&giftsfile);

			// After book data read from file store the book to gift. 
			push_back(newBook);
		}

		// Complete all lines of record, closing file.
		giftsfile.close();
	}
	else
	{
		// File cannot open.
		cout << "Error: Unable to open gifts record file.";
	}
}
//	Function to write gifts books to a text file.
//	Precondition:	gifts has valid books records.
//	Postcondition:	"gifts.txt" will be create or overwriten with books records.
void Gifts::saveGiftsFile()
{
	ofstream giftsfile("gifts.txt");
	if (giftsfile.is_open())
	{
		
		for (int i = 0; i < numOfBooks; i++)
		{
			// write book data
			giftBooks[i].writeFile(&giftsfile);

			if (i < numOfBooks-1)
				giftsfile << endl;
		}
		
		giftsfile.close();
	}
	else
	{
		cout << "Unable to open file";
	}
}

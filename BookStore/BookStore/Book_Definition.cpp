//*****************************************************
// Elienai Fasano
// BookStore - 11/14/2017
// This class specifies the definition of the functions 
//        from a book declaration class
//  
//*****************************************************


#include <iostream>
#include <iomanip>	// For setprecision()
#include <string>
#include <fstream>	// for file IO
#include <sstream>	// for convert string

#include "Book.h"

// Default Constuctor
Book::Book()
{
	Book(0, "None", "None", "None", "None", 0.0);
}

// Copy Constuctor takes all values at once.
Book::Book(long long theIsbn, const string& theTitle, const string& theAuthor,
	const string& thePublish, const string& theCategory, double thePrice)
{
	isbn = theIsbn;
	title = theTitle;
	author = theAuthor;
	publish = thePublish;
	category = theCategory;
	price = thePrice;
}

// Getter function to access book ISBN.
//	Precondition:	ISBN should be a valid long long int.
//	Postcondition:	Retrun ISBN as long long int.
long long Book::getIsbn() const
{
	return isbn;
}
// Getter function to access book title.
//	Precondition:	title should be a valid string.
//	Postcondition:	Retrun title as string.
string Book::getTitle() const
{
	return title;
}
// Getter function to access book author.
//	Precondition:	author should be a valid string.
//	Postcondition:	Retrun author as string.
string Book::getAuthor() const
{
	return author;
}
// Getter function to access book publisher.
//	Precondition:	publisher should be a valid string.
//	Postcondition:	Retrun publisher as string.
string Book::getPublish() const
{
	return publish;
}
// Getter function to access book category.
//	Precondition:	category should be a valid string.
//	Postcondition:	Retrun category as string.
string Book::getCategory() const
{
	return category;
}
// Getter function to access book price.
//	Precondition:	price should be a valid double value.
//	Postcondition:	Retrun price as double.
double Book::getPrice() const
{
	return price;
}
// Setter function to modify book ISBN.
//	Precondition:	newIsbn should be a valid long long int.
//	Postcondition:	isbn will be updated as newIsbn.
void Book::setIsbn(long long newIsbn)
{
	isbn = newIsbn;
}
// Setter function to modify book title.
//	Precondition:	newTitle should be a valid string.
//	Postcondition:	title will be updated as newTitle.
void Book::setTitle(const string& newTitle)
{
	title = newTitle;
}
// Setter function to modify book author.
//	Precondition:	newAuthor should be a valid string.
//	Postcondition:	author will be updated as newAuthor.
void Book::setAuthor(const string& newAuthor)
{
	author = newAuthor;
}
// Setter function to modify book publisher.
//	Precondition:	newPublish should be a valid string.
//	Postcondition:	publisher will be updated as newPublish.
void Book::setPublish(const string& newPublish)
{
	publish = newPublish;
}
// Setter function to modify book category.
//	Precondition:	newCategory should be a valid string.
//	Postcondition:	category will be updated as newCategory.
void Book::setCategory(const string& newCategory)
{
	category = newCategory;
}
// Setter function to modify book price.
//	Precondition:	newPrice should be a valid double.
//	Postcondition:	price will be updated as newPrice.
void Book::setPrice(double newPrice)
{
	price = newPrice;
}
//	Function overloads operator != to check 2 book objects is not equal by ISBN.
//	Precondition:	Both current and rightBook object should have valid ISBN
//	Postcondition:	Retrun true if current ISBN is NOT equal to rightBook's ISBN.
//					Else, return false.
bool Book::operator!= (const Book &otherBook) const
{
	return isbn != otherBook.isbn;
}
//	Function overloads operator < to compare 2 book objects by ISBN.
//	Precondition:	Both current and rightBook object should have valid ISBN
//	Postcondition:	Retrun true if current ISBN is greater than rightBook's ISBN.
//					Else, return false.
bool Book::operator< (const Book &rightBook) const
{
	return isbn < rightBook.getIsbn();
}
//	Function to print book details information.
//	Precondition:	book details should valid.
//	Postcondition:	isbn, title, author, publisher, category and price 
//					 will be print on the screen.
void Book::printDetails() const
{
	cout << "ISBN: " << isbn << "\t Title: " << title << "\nAuthor: " << author << "\t Publisher: " << publish << "\n"
		<< "Category: "<< category << "\t Price: " << setprecision(2) << fixed << price;
}
//	Helper Function to read books detail from a ifstream. Read in name and tokens form file through stream.
//	Precondition:	ifstream should already open the file and point to the line with books detail.
//	Postcondition:	Books detail will be store into current object, 
//					unread data on the same line will be return as stringstream.
stringstream Book::readFile(ifstream *inventoryfile)
{
	string line;
	// Read in the whole line of string.
	if (getline(*inventoryfile, line))
	{
		stringstream ss(line);
		string temp;

		// get the first string separate by "|", store it to temp.
		getline(ss, temp, '|');
		// Converting string to long long int.
		stringstream(temp) >> isbn;

		// get the next string separate by "|" and so on...
		getline(ss, title, '|');
		getline(ss, author, '|');
		getline(ss, publish, '|');
		getline(ss, category, '|');

		getline(ss, temp, '|');
		// Converting string to double.
		stringstream(temp) >> price;

		// Return unread stringstream.
		return ss;
	}
	else
	{
		cout << "Incorrect file format.\n";
		return stringstream();
	}
}
//	Helper Function to write books detail through ifstream. Write out name and tokens to file through stream.
//	Precondition:	ifstream should already open the file and point to a new line.
//	Postcondition:	Books detail will be write in the file as a single line.
void Book::writeFile(ofstream *inventoryfile)
{
	*inventoryfile << isbn << "|" << title << "|" << author << "|" << publish
		<< "|" << category << "|" << setprecision(2) << fixed << price;
}
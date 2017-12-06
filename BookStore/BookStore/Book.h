//****************************************************************
// Elienai Fasano
// BookStore - 11/14/2017
// This class specifies the basic operation with Book Data Members
// It is a Book Declaration Class and Declaration file.txt
// 
//****************************************************************


#ifndef BOOK_H
#define BOOK_H

using namespace std;

class Book
{
	public:
		// Default Constuctor
		Book();

		// Copy Constuctor takes all values at once.
		Book(long long theIsbn, const string& theTitle, const string& theAuthor,
		const string& thePublish, const string& theCategory, double thePrice);
		

		long long getIsbn() const;
		// Getter function to access book ISBN.
		//	Precondition:	ISBN should be a valid long long int.
		//	Postcondition:	Retrun ISBN as long long int.

		string getTitle() const;
		// Getter function to access book title.
		//	Precondition:	title should be a valid string.
		//	Postcondition:	Retrun title as string.

		string getAuthor() const;
		// Getter function to access book author.
		//	Precondition:	author should be a valid string.
		//	Postcondition:	Retrun author as string.

		string getPublish() const;
		// Getter function to access book publisher.
		//	Precondition:	publisher should be a valid string.
		//	Postcondition:	Retrun publisher as string.

		string getCategory() const;
		// Getter function to access book category.
		//	Precondition:	category should be a valid string.
		//	Postcondition:	Retrun category as string.

		double getPrice() const;
		// Getter function to access book price.
		//	Precondition:	price should be a valid double value.
		//	Postcondition:	Retrun price as double.

	
		void setIsbn(long long newIsbn);
		// Setter function to modify book ISBN.
		//	Precondition:	newIsbn should be a valid long long int.
		//	Postcondition:	isbn will be updated as newIsbn.

		void setTitle(const string& newTitle);
		// Setter function to modify book title.
		//	Precondition:	newTitle should be a valid string.
		//	Postcondition:	title will be updated as newTitle.

		void setAuthor(const string& newAuthor);
		// Setter function to modify book author.
		//	Precondition:	newAuthor should be a valid string.
		//	Postcondition:	author will be updated as newAuthor.

		void setPublish(const string& newPublish);
		// Setter function to modify book publisher.
		//	Precondition:	newPublish should be a valid string.
		//	Postcondition:	publisher will be updated as newPublish.

		void setCategory(const string& newCategory);
		// Setter function to modify book category.
		//	Precondition:	newCategory should be a valid string.
		//	Postcondition:	category will be updated as newCategory.

		void setPrice(double newPrice);
		// Setter function to modify book price.
		//	Precondition:	newPrice should be a valid double.
		//	Postcondition:	price will be updated as newPrice.


		bool operator!= (const Book &otherBook) const;
		//	Function overloads operator != to check 2 book objects is not equal by ISBN.
		//	Precondition:	Both current and rightBook object should have valid ISBN
		//	Postcondition:	Retrun true if current ISBN is NOT equal to rightBook's ISBN.
		//					Else, return false.

		bool operator< (const Book &rightBook) const;
		//	Function overloads operator < to compare 2 book objects by ISBN.
		//	Precondition:	Both current and rightBook object should have valid ISBN
		//	Postcondition:	Retrun true if current ISBN is greater than rightBook's ISBN.
		//					Else, return false.
	
		void printDetails() const;
		//	Function to print book details information.
		//	Precondition:	book details should valid.
		//	Postcondition:	isbn, title, author, publisher, category and price 
		//					 will be print on the screen.

		stringstream readFile(ifstream *inventoryfile);
		//	Helper Function to read books detail from a ifstream.
		//	Precondition:	ifstream should already open the file and point to the line with books detail.
		//	Postcondition:	Books detail will be store into current object, 
		//					unread data on the same line will be return as stringstream.

		void writeFile(ofstream *inventoryfile);
		//	Helper Function to write books detail through ifstream.
		//	Precondition:	ifstream should already open the file and point to a new line.
		//	Postcondition:	Books detail will be write in the file as a single line.

	private:
		long long isbn;
		string title;
		string author;
		string publish;
		string category;
		double price;
	
	}; 

#endif //BOOK_H
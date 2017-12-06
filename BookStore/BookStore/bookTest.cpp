//**********************************************************
// Elienai Fasano
// BookStore - 11/14/2017
// Tester class to test the function of Book Class
//  
//**********************************************************


#include <iostream>

#include "Book.h"

// Tester class 
class bookTest
{
public:

	void testingBook()
	{
		// Create book
		Book book1(9780399565038, "The Rooster Bar", "Grisham, John", "Random House", "Fiction", 25.70);
		Book book2(9780735224292, "Little Fires Everywhere", "Ng, Celeste", "Penguin Group USA", "Fiction", 16.20);
		// print book details
		book1.printDetails();
		book2.printDetails();
		// Test < operator
		cout << "book1 < book2: " << (book1 < book2) << endl;
		// Test != operator
		cout << "book1 != book2: " << (book1 != book2) << endl;
	};
};
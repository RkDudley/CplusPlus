//**********************************************************
// Elienai Fasano
// BookStore - 11/14/2017
// Tester class to test the function of gifts Class
//  
//**********************************************************

#include <iostream> // for input and output
#include "Gifts.h"

// Tester class 
class giftsTest
{
public:

	void testingGifts()
	{
		// create gifts object
		Gifts giftsSection;

		// load data from file
		giftsSection.loadGiftsFile();

		// Create book
		Book book1(9780399565038, "The Rooster Bar", "Grisham, John", "Random House", "Fiction", 25.70);
		Book book2(9780735224292, "Little Fires Everywhere", "Ng, Celeste", "Penguin Group USA", "Fiction", 16.20);
		Book book3(9781614489719, "Stop the Rain Dance", "e Stagl, John F., Dr", "Ingram Pub Services ", "Romance", 14.27);

		// Add book into gifts inventory
		giftsSection.push_back(book1);
		giftsSection.push_back(book2);
		giftsSection.push_back(book3);

		giftsSection.PrintList();

		// remove book
		Book* giftBook = giftsSection.top();
		giftsSection.pop_back();
		giftBook->printDetails();

		giftsSection.PrintList();

		// save record to file
		giftsSection.saveGiftsFile();
	};
};
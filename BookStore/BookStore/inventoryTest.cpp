//**********************************************************
// Elienai Fasano
// BookStore - 11/14/2017
// Tester class to test the function of Inventory Class
//  
//**********************************************************


#include <iostream> // for input and output
#include "Inventory.h"

// Tester class 
class inventoryTest
{
public:

	void testingInventory()
	{
		// create inventory object
		Inventory bookInventory;

		// load data from file
		bookInventory.loadInventoryFile();

		// Create book
		Book book1(9780399565038, "The Rooster Bar", "Grisham, John", "Random House", "Fiction", 25.70);
		Book book2(9780735224292, "Little Fires Everywhere", "Ng, Celeste", "Penguin Group USA", "Fiction", 16.20);
		Book book3(9781614489719, "Stop the Rain Dance", "e Stagl, John F., Dr", "Ingram Pub Services ", "Romance", 14.27);

		// Add book into inventory
		bookInventory.AddEditBooks(book2, 3);
		bookInventory.AddEditBooks(book1, 5);
		bookInventory.AddEditBooks(book3, 20);

		// search and remove book
		Book* bookToGet = bookInventory.SearchBook(9780399565038);
		bookInventory.RemoveBooks(*bookToGet, 1);
		bookInventory.PrintList();

		// save record to file
		bookInventory.saveInventoryFile();
	};
};
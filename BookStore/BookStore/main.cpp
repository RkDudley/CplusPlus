//**************************************************************
// Dhruvi Bharatbhai Thakkar - Elienai Fasano - Rattikarn Dudley
// BookStore - 12/4/2017
// Project: BookStore
//  
//**************************************************************


#include <iostream>
#include <cstdlib>
#include <string>
#include "Inventory.h"
#include "customerList.h"
#include "customerFunction.h"
#include "previousOrders.h"
#include "gifts.h"

using namespace std;

Inventory bookInventory;
Gifts giftsSection;
previousOrders pO;

void inventoryMenu();
void orderMenu();

int main()
{
	// Loading books data from the file.
	bookInventory.loadInventoryFile();
	giftsSection.loadGiftsFile();

	int choice = 0;
	
	do
	{

		cout << "\nWelcome to TURNPAGE BOOK STORE\n\n" << endl;
		cout << "BOOKSTORE MANAGEMENT" << endl;
		cout << "=====================";
		cout << "\n\n";
		cout << "Main Menu: (Please select a number option).\n";
		cout << "\t1. Inventory" << endl;
		cout << "\t2. Client Orders" << endl;
		cout << "\t3. Client Information" << endl;
		cout << "\t4. Exit" << endl;

		cout << "Enter Choice: ";
		cin >> choice;
		
		// Clear up cin and choice when letter entered.
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			choice = 0;
		}

		switch (choice)
		{
		case 1:
			cout << "Inventory was selected\n\n";
			//call a function to display the inventory option
			inventoryMenu();
			break;
		case 2:
			cout << "Client Orders was selected" << endl;
			orderMenu();
			break;
		case 3:
			cout << "Client Information was selected" << endl;			
			//call a function customer to display the option
			customer();
			break;
		case 4:
			cout << "Program Ending" << endl;
			break;
		default:
			cout << "Invalid menu choice" << endl;
		}
	} while (choice != 4);
	
	system("pause");

	return 0;
}


/* 
 * Function to handle menu option to display inventory menu and options.
 */
void inventoryMenu()
{
	long long isbn;
	string title;
	string author;
	string publisher;
	string category;
	int quantity;

	Book newBook;
	Book* foundBook;

	int choice = 0;
	do {
		cout << "INVENTORY" << endl;
		cout << "=====================";
		cout << "\n\n";
		cout << "Inventory Menu: (Please select a number option).\n";
		cout << "\t1. List All Book" << endl;
		cout << "\t2. Search for Book" << endl;
		cout << "\t3. Add/Edit New Books" << endl;
		cout << "\t4. Remove Books" << endl;
		cout << "\t5. List all Books to Gifts Section" << endl;
		cout << "\t6. Add Gift Book to Gifts Section" << endl;
		cout << "\t7. Go Back to Main Menu" << endl;
		cout << "Enter Choice: ";
		cin >> choice;

		// Clear up cin and choice when letter entered.
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			choice = 0;
		}

		switch (choice)
		{
		case 1:
			cout << "List All Book was selected\n\n";
			cout << "List All BOOK" << endl;
			cout << "=====================";
			cout << "\n\n";
			bookInventory.PrintList();
			break;

		case 2:
			cout << "Search for Book was selected\n\n";
			cout << "SEARCH FOR BOOK" << endl;
			cout << "=====================";
			cout << "\n\n";
			cout << "Enter the ISBN: ";
			cin >> isbn;
			foundBook = bookInventory.SearchBook(isbn);
			if (foundBook != NULL)
			{
				cout << "Book found:\n";
				foundBook->printDetails();
				cout << "\t Qty: " << bookInventory.getBookQty(*foundBook) << endl;
				cout << "\n\n";
			}
			break;

		case 3:
			cout << "Add/Edit Books was selected\n\n";
			cout << "ADD/Edit NEW BOOK" << endl;
			cout << "=====================";
			cout << "\n\n";

			cout << "Enter the ISBN: ";
			cin >> isbn;

			// Clear up cin and exit to menu when letter entered.
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invaild isbn.\n";
				break;
			}

			// remove the \n from the buffer.
			getline(cin, title);

			cout << "Enter the Title: ";
			getline(cin, title);
			cout << "Enter the Author: ";
			getline(cin, author);
			cout << "Enter the Publisher: ";
			getline(cin, publisher);
			cout << "Enter the Category: ";
			getline(cin, category);

			cout << "Enter the Price: ";
			double price;
			cin >> price;

			// Clear up cin and exit to menu when letter entered.
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invaild price.\n";
				break;
			}

			cout << "Enter the Total Quantity: ";
			cin >> quantity;

			// Clear up cin and exit to menu when letter entered.
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invaild quantity.\n";
				break;
			}

			newBook = Book(isbn, title, author, publisher, category, price);
			bookInventory.AddEditBooks(newBook, quantity);

			cout << "Book record updated to inventory.\n";

			// Save Book inventory to file before exit.
			bookInventory.saveInventoryFile();

			break;

		case 4:

			cout << "Remove Books was selected\n\n";
			cout << "REMOVE BOOK" << endl;
			cout << "=====================";
			cout << "\n\n";

			cout << "Enter the ISBN: ";
			cin >> isbn;
			cout << "Enter the number of book to be removed: ";
			cin >> quantity;

			foundBook = bookInventory.SearchBook(isbn);
			if (foundBook != NULL)
			{
				bookInventory.RemoveBooks(*foundBook, quantity);
			}

			// Save Book inventory to file before exit.
			bookInventory.saveInventoryFile();

			break;

		case 5:
			cout << "List all Books to Gifts Section was selected\n\n";
			cout << "List all Books to Gifts Section" << endl;
			cout << "=====================";
			cout << "\n\n";
			giftsSection.PrintList();
			break;

		case 6:
			cout << "Add Gift Book to Gifts Section was selected\n\n";
			cout << "Add Gift Book to Gifts Section" << endl;
			cout << "=====================";
			cout << "\n\n";

			cout << "Enter the ISBN: ";
			cin >> isbn;

			// Clear up cin and exit to menu when letter entered.
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invaild isbn.\n";
				break;
			}

			// remove the \n from the buffer.
			getline(cin, title);
			cout << "Enter the Title: ";
			getline(cin, title);
			cout << "Enter the Author: ";
			getline(cin, author);
			cout << "Enter the Publisher: ";
			getline(cin, publisher);
			cout << "Enter the Category: ";
			getline(cin, category);

			newBook = Book(isbn, title, author, publisher, category, 0);
			giftsSection.push_back(newBook);
			giftsSection.saveGiftsFile();
			cout << "New Book has added to gifts section.\n";
			break;

		case 7:
			break;

		default:
			cout << "Invalid menu choice" << endl;
		}
	} while (choice != 7);
}

void orderMenu()
{
	long long isbn;
	int quantity;
	Book* wantedBook;
	Book* giftBook;
	Order order;
	double totalPrice;

	int choice = 0;
	do {
		cout << "ORDER" << endl;
		cout << "=====================";
		cout << "\n\n";
		cout << "Order Menu: (Please select a number option).\n";
		cout << "\t1. List All Orders" << endl;
		cout << "\t2. Add a New order" << endl;
		cout << "\t3. Checkout the next order" << endl;
		cout << "\t4. Go Back to Main Menu" << endl;
		cout << "Enter Choice: ";
		cin >> choice;

		// Clear up cin and choice when letter entered.
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			choice = 0;
		}

		switch (choice)
		{
		case 1:
			cout << "List All Orders was selected\n\n";
			cout << "List All Orders" << endl;
			cout << "=====================";
			cout << "\n\n";
			pO.display();
			break;

		case 2:
			cout << "Add a New order was selected\n\n";
			cout << "Add a New order" << endl;
			cout << "=====================";
			cout << "\n\n";

			cout << "Enter the ISBN of the book to order: ";
			cin >> isbn;
			wantedBook = bookInventory.SearchBook(isbn);
			if (wantedBook == NULL)
			{
				cout << "Book not found.\n";
				break;
			}

			cout << "Enter the Quantity to order: ";
			cin >> quantity;

			// Clear up cin and exit to menu when letter entered.
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invaild quantity.\n";
				break;
			}

			order = Order(*wantedBook, quantity);
			pO.push_back(order);
			cout << "\n\n";
			break;

		case 3:
			cout << "Checkout the next order was selected\n\n";
			cout << "Checkout the next order" << endl;
			cout << "=====================";
			cout << "\n\n";

			if (pO.isEmpty())
			{
				cout << "Order list is empty.\n";
				break;
			}

			order = *pO.front();
			pO.pop_front();
			bookInventory.RemoveBooks(order.getBookOrdered(), order.getQuantity());

			// print receipt
			cout << "\nPrinting receipt: \n\n";
			order.getBookOrdered().printDetails();
			
			// Caculate total price.
			totalPrice = order.getBookOrdered().getPrice() * order.getQuantity();
			cout << "\nQuantity: " << order.getQuantity() << "\tTotal Price: " << totalPrice << endl;

			if (!giftsSection.isEmpty())
			{
				giftBook = giftsSection.top();
				giftsSection.pop_back();
				cout << "You receive a free gift book!\n";
				giftBook->printDetails();
				cout << endl;
				giftsSection.saveGiftsFile();
			}

			cout << "Thanks for shopping with TURNPAGE BOOK STORE.\n";
			cout << "=====================";
			cout << "\n\n";

			break;

		default:
			cout << "Invalid menu choice" << endl;
		}

	} while (choice != 4);
}
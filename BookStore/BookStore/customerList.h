//Rattikarn Dudley
#ifndef H_CustomerList
#define H_CustomerList

#include <iostream>
#include <string>
#include "Book.h"
#include "unorderedLinkedList.h"
#include "CustomerType.h"

using namespace std;

class CustomerList :public unorderedLinkedList<CustomerType>
{
public:
	bool searchCustomerId(int cusId);
	//Function to search if a customer is a membership
	// function return true if the search found

	void deleteCusInfo(int id, string last);
	//Function to delete a customer information
	//Postcondition: the function delele a node
	//the been select

	void addCusInfo(string other, int max);
	//Function to add customer information
	//Precondition: If the id is not found and the id is not the same id
	//Postcondition; the customer is added

	void editCusinfo(int id, string fname, string lname, string addr);
	//Function to edit customer information
	//Precondition: If the id is found
	//Postcondition; the customer is added
	
	int  getNoOfBook(int id);
	//Function to get a number of user buy a book
	//Postcondition: the number of book returned

	void checkoutBookInfo();
	//Function to check how many book has been bought
	//Postcondition: the number of book returned

private:
	void searchCustomer(int id, bool& found,
		nodeType<CustomerType> *current); // node to found the customer in the list
};

#endif
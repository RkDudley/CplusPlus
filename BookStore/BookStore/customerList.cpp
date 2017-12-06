// The definition of a class customerList
// the implementation of node of customers in a link list
// Rattikarn Dudley
#include <iostream>
#include <string>
#include "CustomerType.h"
#include "customerList.h"
#include <fstream>
#include <sstream>

using namespace std;

void CustomerList::searchCustomer(int id, bool& found,
	nodeType<CustomerType> *current)
{
	found = false;

	if (first == NULL)
	{
		cout << "Cannot search an empty list." << endl;
	}
	else
	{
		current = first;
		found = false;
		while (!found && current != NULL)
		{
			if (current->info.getCustomerId() == id)
			{
				found = true;
			}
			else
			{
				current = current->link;
			}
		}

	}
}

bool CustomerList::searchCustomerId(int id)
{
	bool found;
	nodeType<CustomerType> *current = NULL;

	searchCustomer(id, found, current);

	return found;
}
void CustomerList::addCusInfo(string other, int id)
{
	bool found;
	nodeType<CustomerType> *current = NULL;
	searchCustomer(id, found, current);
	current->info.addCustomer(other);
}

void CustomerList::deleteCusInfo(int id, string lastname)
{
	bool found;
	nodeType<CustomerType> *current = NULL;
	nodeType<CustomerType> *temp = NULL;
	
	// Create dummy cus object with the id
	CustomerType deleteCustomer(id, "", "", "");
	// Pass the cus object to delete the node using function in unorderedLinkedList
	deleteNode(deleteCustomer);

	//searchCustomer(id, found, current);
	//current->info.deleteCustome(lastname);
}

void CustomerList::editCusinfo(int id, string fname, string lname, string addr)
{
	if (first == NULL)
	{
		cout << "Cannot search an empty list." << endl;
	}
	else
	{
		nodeType<CustomerType> *current = first;
		nodeType<CustomerType> *prev = first;
		while (current != NULL)
		{
			if (current->info.getCustomerId() == id)
			{
				CustomerType cust(id, fname, lname, addr);

				nodeType<CustomerType> *newNode = new nodeType<CustomerType>; //create the new node
				newNode->info = cust;  //store the new item in the node
				newNode->link = current->link;
				prev->link = newNode;

				break;
			}
			else
			{
				prev = current;
				current = current->link;
			}
		}

	}
}

int CustomerList::getNoOfBook(int id)
{
	bool found;
	nodeType<CustomerType> *current = NULL;

	searchCustomer(id, found, current);

	return current->info.getNumOfCheckOut();
}
void CustomerList::checkoutBookInfo()
{
	nodeType<CustomerType> *current;
	current = first;

	cout << " ######## CheckOut Info ########"
		<< endl << endl;

	while (current != NULL)
	{
		if (current->info.getNumOfCheckOut() > 0)
		{
			cout << "Customer ID: " << current->info.getCustomerId()
				<< endl;
			cout << "Book Checkout: ";
			current->info.printBookBought();
			cout << "*****************" << endl << endl;
		}

		current = current->link;
	}
}

//Rattikarn Dudley
#ifndef H_CustomerType
#define H_CustomerType

#include <iostream>
#include <string>
#include "unorderedLinkedList.h"
#include "Book.h"

using namespace std;

class CustomerType
{
	friend ostream& operator<<(ostream&, CustomerType&);
	// overload stream insertion operator
public:
	void setInfoCustomer(int id, string first, string last, string addressP);
	//Fucntion to set customer informationa according to parameter
	//Postcondition: customer information will be set

	void setCustomerId(int Cusid);
	//Fucntion to set customer id according to parameter
	//Postcondition  id = CusId

	void setLastname(string last);

	int getCustomerId() const;
	//Function to return customer id
	//Postcondition return id

	string getFirstName() const;
	//Function to return customer first name
	//Postcondition return fName;

	string getLastName() const;
	//Function to return customer last name
	//Postcondition return lName;

	string getAddress() const;
	//Function to return customer address
	//Postcondition return address

	void printCustomerInfo() const;
	//Function to display a customer information
	//Postcondition: customer information will be printed

	void addCustomer(string other);
	//Function to add a new customer

	void deleteCustome(string other);
	//Function to delete customer

	int getNumOfCheckOut();
	//Function to tell how many customers bought a book

	void printBookBought();
	//Function to print a particular customer

	CustomerType();
	//default constructor

	CustomerType(int id, string first, string last, string addressP);
	//constructor with parameter
	//set all the info according to parameter

	// overload operators for comparisons
	bool operator==(CustomerType);
	bool operator!=(CustomerType);

private:
	string fName;
	string lName;
	string address;
	int gift;
	int id;
	unorderedLinkedList<string> orderedList;
};


#endif


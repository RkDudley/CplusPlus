// The definition of a class customer
//Rattikarn Dudley
#include <iostream>
#include <string>
#include "CustomerType.h"
#include "customerList.h"
#include <fstream>
#include <sstream>

using namespace std;

CustomerType::CustomerType()
{
	fName = "";
	lName = "";
	address = "";
	id = 000000;
}
CustomerType::CustomerType(int cusId, string first, string last, string addressP)
{
	setInfoCustomer(cusId, first, last, addressP);
}
void CustomerType::setInfoCustomer(int Cusid, string first, string last, string addressP)
{
	fName = first;
	lName = last;
	address = addressP;
	id = Cusid;
}
void CustomerType::setCustomerId(int cusId)
{
	id = cusId;
}

void CustomerType::setLastname(string last)
{
	lName = last;
}
string CustomerType::getFirstName() const
{
	return fName;
}
string CustomerType::getLastName() const
{
	return lName;
}
string CustomerType::getAddress() const
{
	return address;
}

void CustomerType::printCustomerInfo() const
{
	cout << "Customer No: " << getCustomerId();
	cout << "First Name: " << getFirstName();
	cout << "Last Name: " << getLastName();
	cout << "Address: " << getAddress();
	cout << "Book checkout: " << orderedList.length() << "books" << endl;
}

int CustomerType::getCustomerId() const
{
	return id;
}
void CustomerType::addCustomer(string other)
{
	orderedList.insertFirst(other);
}
void CustomerType::deleteCustome(string other)
{
	orderedList.deleteNode(other);
}
int CustomerType::getNumOfCheckOut()
{
	return orderedList.length();
}
void CustomerType::printBookBought()
{
	orderedList.print();
	cout << endl;
}
bool CustomerType::operator==(CustomerType other)
{
	return(id == other.id);
}

bool CustomerType::operator!=(CustomerType other)
{
	return(id != other.id);
}
ostream& operator<<(ostream& os, CustomerType& cust)
{
	int id = cust.getCustomerId();
	string fname = cust.getFirstName();
	string lname = cust.getLastName();
	string addressCust = cust.getAddress();
	os << "-----------Customer Information------------" << endl;
	os << " Customer Id: " << id << endl;
	os << " Customer first name: " << fname << endl;
	os << " Customer last name: " << lname << endl;
	os << " Customer address: " << addressCust << endl;
	os << endl;
	return os;
}

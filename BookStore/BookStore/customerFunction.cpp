
#include <iostream>
#include "customerList.h"
#include "CustomerType.h"
#include "linkedList.h"
#include "customerFunction.h"
#include <fstream>
#include <sstream>

using namespace std;
void displayMenu()
{
	cout << "Select one of the following: " << endl;
	cout << "\t1: To see if a particular person is a member" << endl;
	cout << "\t2: Add a customer membership" << endl;
	cout << "\t3: Delete a customer membership" << endl;
	cout << "\t4: Edit a customer membership " << endl;
	//cout << "\t5: Book Purchased " << endl;
	cout << "\t8: Print all list of customers" << endl;
	cout << "\t9: To exit" << endl;
};

void loadCustomerList(ifstream &infile, CustomerList& custList)
{
	string fname;
	string lname;
	string address;
	int id = 0;

	CustomerType cust(id, fname, lname, address);

	string line;

	while (getline(infile, line))
	{
		stringstream ss(line);
		string temp;

		getline(ss, temp, '|');
		// Converting string to long long int.
		stringstream(temp) >> id;

		// get the next string separate by "|" and so on...
		getline(ss, fname, '|');
		getline(ss, lname, '|');
		getline(ss, address, '|');

		cust.setInfoCustomer(id, fname, lname, address);
		custList.insertFirst(cust);
	}
};

void addMember(ofstream& outfile, ifstream &infile, CustomerList& cusList)
{
	loadCustomerList(infile, cusList);

	string fname;
	string lname;
	string address;
	int id = 0;

	//create a customer information
	cout << "Create a customer ID: ";
	cin >> id;
	// Check if customer already added.
	if (cusList.searchCustomerId(id))
	{
		cout << "Customer existed with ID: " << id << endl;
		cout << "Create a unique customer ID: ";
		cin >> id;
	}

	cout << "Enter a custumer first name: ";
	cin >> fname;
	cout << "Enter a custumer last name: ";
	cin >> lname;
	cin.ignore();
	cout << "Enter a custumer address: ";
	getline(cin, address);


	outfile << id << "|" << fname << "|" << lname << "|" << address << endl;

	CustomerType cust(id, fname, lname, address);
	cust.setInfoCustomer(id, fname, lname, address);
	cusList.insertLast(cust);
};

void deleteMember(int id, ofstream& outfile, ifstream &infile, CustomerList& cusList)
{
	// delete cus record in the CustomerList
	cusList.deleteCusInfo(id, "");

	// open file with overwrite mode
	outfile.open("customer.txt", ios::out);

	// Use Iterator to go through every record in the linked list
	linkedListIterator<CustomerType> iter = cusList.begin();
	while (iter != NULL)
	{
		// write cus info into the file
		outfile << (*iter).getCustomerId() << "|" << (*iter).getFirstName() << "|" << (*iter).getLastName() << "|" << (*iter).getAddress() << endl;
		++iter;
	}
	outfile.close();

	/*
	ifstream read("customer.txt");
	ofstream write("tmp.txt", ios::in);
	string line;

	if (read.is_open())
	{
	while (getline(read, line))
	{
	}

	}
	else
	{
	cerr << "Error: coudn't open file\n";
	/* additional handle */

	/*
	}
	read.close();
	write.close();
	remove("customer.txt");
	rename("tmp.txt", "customer.txt");
	*/
};
void EditCustomer(int id, ofstream& outfile, ifstream &infile, CustomerList& cusList)
{
	loadCustomerList(infile, cusList);

	string fname;
	string lname;
	string address;

	//create a customer information
	cout << "Enter a custumer first name: ";
	cin >> fname;
	cout << "Enter a custumer last name: ";
	cin >> lname;
	cin.ignore();
	cout << "Enter a custumer address: ";
	getline(cin, address);



	// Check if customer already added.
	if (cusList.searchCustomerId(id))
	{
		cout << "Updating Customer infomation: " << id << endl;

		cusList.editCusinfo(id, fname, lname, address);

		// open file with overwrite mode
		outfile.open("customer.txt", ios::out);

		// Find the matched id customer and replace the cus with the new cus object.
		linkedListIterator<CustomerType> iter = cusList.begin();
		while (iter != NULL)
		{
			// write cus info into the file

			// rewrite info into file
			outfile << (*iter).getCustomerId() << "|" << (*iter).getFirstName() << "|" << (*iter).getLastName() << "|" << (*iter).getAddress() << endl;

			++iter;
		}

		outfile.close();

	}
	// Cus is not in the list, add as new customer
	else
	{
		outfile.open("customer.txt", ios::app);

		outfile << id << "|" << fname << "|" << lname << "|" << address << endl;

		CustomerType cust(id, fname, lname, address);
		cust.setInfoCustomer(id, fname, lname, address);
		cusList.insertLast(cust);
		outfile.close();
	}
};
void customer()
{
	int choice, id;
	int idL = 0;
	//declare a customer list to store customer date
	CustomerList custList;
	CustomerType cuslast;// get to work in a function

	//read and write file
	ifstream infile;
	ofstream outfile;

	infile.open("customer.txt");

	if (infile.fail())
	{
		cout << "Input file does not exist" << endl;
	}
	loadCustomerList(infile, custList);

	infile.close();

	displayMenu();
	cout << "Enter choice: ";
	cin >> choice;
	cout << endl;

	while (choice != 9)
	{
		switch (choice)
		{
		case 1:
			cout << "Enter customer id: ";
			cin >> id;
			cout << endl;

			if (custList.searchCustomerId(id))
			{
				cout << id << " is a member" << endl;
			}
			else
			{
				cout << "Not a customer" << endl;
				cout << "Do you want to add membership Y/N ?" << endl;
				char mem = ' ';
				if (mem == 'Y' || mem == 'y')
				{
					outfile.open("customer.txt", ios::app);
					if (outfile.fail())
					{
						cout << "Input file does not exist" << endl;
					}
					else
					{
						addMember(outfile, infile, custList);
						outfile.close();
					}
				}
				else
				{
					break;
				}
			}
			break;
		case 2:
			outfile.open("customer.txt", ios::app);
			if (outfile.fail())
			{
				cout << "Input file does not exist" << endl;
			}
			else
			{
				addMember(outfile, infile, custList);
				outfile.close();
			}
			break;
		case 3:
			cout << "Enter customer id: ";
			cin >> idL;
			if (custList.searchCustomerId(idL))
			{
				//stringstream ss;
				//ss << idL;
				//string idStr = ss.str();
				deleteMember(idL, outfile, infile, custList);
			}
			else
			{
				cout << "No customer found" << endl;
			}
			break;
		case 4:
			cout << "Enter customer id: ";
			cin >> id;

			if (custList.searchCustomerId(id))
			{
				EditCustomer(id, outfile, infile, custList);
			}
			else
			{
				cout << "No customer found" << endl;
			}
			break;
		case 8:
			loadCustomerList(infile, custList);
			cout << " ";
			custList.print();
			break;

		default:
			cout << "Bad Selection" << endl;
		}

		displayMenu();
		cout << "Enter choice: ";
		cin >> choice;
		cout << endl;
	}//end while

	infile.close();

};
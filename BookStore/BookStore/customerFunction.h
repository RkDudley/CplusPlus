//Rattikarn Dudley
#ifndef Add_H_INCLUDED
#define ADD_H_INCLUDED

#include <iostream>
#include "customerList.h"
#include "CustomerType.h"
#include "linkedList.h"
#include <fstream>
#include <sstream>

using namespace std;

void displayMenu();
//Function a display a customer menu
//Postcondtion: The customer information will display

void loadCustomerList(ifstream &infile, CustomerList& custList);
//Function to load  all customer list into a file
//Postdition: The file will add after call this function

void addMember(ofstream& outfile, ifstream &infile, CustomerList& cusList);
//Function to add a customer membership
//Postcondition: The customer information will be added to the file and
//in a linklist

void deleteMember(int id, ofstream& outfile, ifstream &infile, CustomerList& cusList);
//Function to delete a customer member
//Postcondition: the member will be delete based on an id search found

void EditCustomer(int id, ofstream& outfile, ifstream &infile, CustomerList& cusList);
//Function to edit a customer information member
//Postcondition: the customer information will be edit 
//Validate by the id search, if id found the information can be edit

void customer();
//Function to call the customer class and implementation to the main function
//Postcondition: the customer function and call and show a menu
//for use to select

#endif
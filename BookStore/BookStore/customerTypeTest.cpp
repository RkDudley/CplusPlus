//Function to test a function class customerType and customerList
//Rattikarn Dudley

#include <iostream> // for input and output
#include "CustomerType.h"
#include "customerList.h"

// Tester class 
class customerTest
{
public:

	void CustomerTest()
	{
		//declare a variable to add for customer information
		int cusId = 123456;
		string first = "Rattikarn";
		string last = "Dudley";
		string address = " 30 fox st Quincy MA";

		// pass information to customerType
		CustomerType CusOne(cusId,first,last,address);
		// declare to customer list to CustomerList store as a linklist
		CustomerList Listone;
		Listone.searchCustomerId(cusId);
		//add customerType to customerList
		Listone.addCusInfo(last, cusId);
		//delete the customer
		Listone.deleteCusInfo(cusId, last);
		//Display a list
		Listone.print();
		
	};
};
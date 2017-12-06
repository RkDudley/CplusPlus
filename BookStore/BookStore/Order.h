/*
? Dhruvi Thakkar
*/

#ifndef ORDER_H
#define ORDER_H

#include "Book.h";

using namespace std;

class Order
{
public:
	// Default Constuctor
	Order();
	// Copy Constuctor takes all values at once.
	Order(const Book& theBook, const int& theQuantity);

	int getOrderId() const;
	// Getter function to access orderID. 
	// 	Precondition:	orderID should be a valid int.
	//	Postcondition:	Retrun orderID as an int.
	
	int getQuantity() const;
	// Getter function to access book quantity. 
	// 	Precondition:	quantity should be a valid int.
	//	Postcondition:	Retrun quantity as an int.

	Book getBookOrdered() const;
	// Getter function to access book ordered. 
	// 	Precondition:	book should be a valid Book object.
	//	Postcondition:	Retrun Book as an Bookobject.

	int setQuantity(int newQuantity);
	// Setter function to modify book quantity. 
	// 	Precondition:	newQuantity should be a valid int.
	//	Postcondition:	newQuantity assigned to quantity.

private:
	int orderId;
	int quantity;
	Book bookOrdered;
};

#endif
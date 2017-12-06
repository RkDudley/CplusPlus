/*
/ Dhruvi Thakkar
 */
#include <iostream>
#include <iomanip>	// For setprecision()
#include <string>
#include <fstream>	// for file IO
#include <sstream>	// for convert string
#include "Book.h"
#include "Order.h"
#include "CustomerType.h"
#include "customerList.h"

//Default Constructor
Order::Order()
{

}
//Copy COnstructor
Order::Order(const Book& theBook, const int & theQuantity)
{
	bookOrdered = theBook;
	quantity = theQuantity;
}

int Order::getOrderId() const
{
	return orderId;
}



int Order::getQuantity() const
{
	return quantity;
}

Book Order::getBookOrdered() const
{
	return bookOrdered;
}

int Order::setQuantity(int newQuantity)
{
	return newQuantity;
}


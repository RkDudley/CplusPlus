/*
 * Dhruvi Thakkar
 * Using: ***Linked List Queue***
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include"order.h"

using namespace std;

/*
 Node Declaration
 */
typedef struct node
{
	Order info;
	node *next;
} *orderNodePtr;// *start;

/*
 Class Declaration
 */
class previousOrders
{
public:
	node* create(Order);

	int size();
	//  Return size
	//  Postcondition:	Number of orders will be returned.

	void push_back(const Order& newOrder);
	//  Insert element
	//	Precondition:	newOrder is a Order object with valid data. 
	//	Postcondition:	A order wil be insert at the back of the list.

	Order* front();
	//  Access next Order 
	//	Precondition:	order should have some orders
	//	Postcondition:	A pointer of the next order will be returned.	

	void pop_front();
	//  Remove next Order
	//	Precondition:	order should have some orders
	//	Postcondition:	The next order wil be removed.	

	bool isEmpty();
	// Test whether order list is empty
	// Postcondition: Return true if the list has orders, false if no order.

	void display();
	// Print all orders.
	// Postcondition: All orders details will be printed.

	void insert_begin(Order newOrder);
	void insert(Order newOrder);
	void del();
	void sort();
	void search();
	void update(Order newOrder);
	void reverse();
	previousOrders()
	{
		start = NULL;
		numOfOrders = 0;
	};

private:
	orderNodePtr start;
	int numOfOrders;
};


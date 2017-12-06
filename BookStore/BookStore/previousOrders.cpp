/*
Dhruvi Thakkar
 */
#include<iostream>
#include "previousOrders.h"
using namespace std;
/*
Creating Node
 */
node *previousOrders::create(Order value)
{
	struct node *temp, *s;
	temp = new(struct node);
	if (temp == NULL)
	{
		cout << "Memory not allocated " << endl;
		return 0;
	}
	else
	{
		numOfOrders++;
		temp->info = value;
		temp->next = NULL;
		return temp;
	}
}

// Return current size of the linked list.
//  Postcondition:	Number of orders will be returned.
int previousOrders::size()
{
	return numOfOrders;
}

/*
Inserting order at last
*/
//	Precondition:	newOrder is a Order object with valid data. 
//	Postcondition:	A order wil be insert at the back of the list.
void previousOrders::push_back(const Order& newOrder)
{
	struct node *temp, *s;
	temp = create(newOrder);
	temp->next = NULL;
	s = start;
	if (s == NULL)
	{
		start = temp;
	}
	else
	{
		while (s->next != NULL)
		{
			s = s->next;
		}
		s->next = temp;
	}
	cout << "Order added at last" << endl;
}

// Access next Order 
//	Precondition:	order should have some orders
//	Postcondition:	A pointer of the next order will be returned.	
Order* previousOrders::front()
{
	if (start == NULL)
	{
		return NULL;
	}
	else
	{
		return &start->info;
	}
}

//Remove next Order
//	Precondition:	order should have some orders
//	Postcondition:	The next order wil be removed.	
void previousOrders::pop_front()
{ 
	if (start != NULL)
	{
		start = start->next;
		numOfOrders--;
	}
}

// Test whether order list is empty
// Postcondition: Return true if the list has orders, false if no order.
bool previousOrders::isEmpty()
{
	return start == NULL;
}

/*
Display Elements of a link list
*/
// Postcondition: All orders details will be printed.
void previousOrders::display()
{
	struct node *temp;
	if (start == NULL)
	{
		cout << "The List is Empty" << endl;
		return;
	}
	temp = start;
	cout << "List of ordered Books: " << endl;
	while (temp != NULL)
	{
		temp->info.getBookOrdered().printDetails();
		cout << "\nOrdered Qty: " << temp->info.getQuantity() << endl << endl;
		temp = temp->next;
	}
	cout << endl;
}


/*
Inserting order in beginning
 */
void previousOrders::insert_begin(Order newOrder)
{
	struct node *temp, *p;
	temp = create(newOrder);
	if (start == NULL)
	{
		start = temp;
		start->next = NULL;
	}
	else
	{
		p = start;
		start = temp;
		start->next = p;
	}
	cout << "Order at beginning" << endl;
}


/*
Insertion of order at a given position
 */
void previousOrders::insert(Order newOrder)
{
	int pos, counter = 0;

	struct node *temp, *s, *ptr;
	temp = create(newOrder);
	cout << "Enter the postion at which Order to be inserted: ";
	cin >> pos;
	int i;
	s = start;
	while (s != NULL)
	{
		s = s->next;
		counter++;
	}
	if (pos == 1)
	{
		if (start == NULL)
		{
			start = temp;
			start->next = NULL;
		}
		else
		{
			// start = temp?
			ptr = start;
			start = temp;
			start->next = ptr;
		}
	}
	else if (pos > 1 && pos <= counter)
	{
		s = start;
		ptr = s;
		for (i = 1; i < pos; i++)
		{
			ptr = s;
			s = s->next;
		}
		ptr->next = temp;
		temp->next = s;
	}
	else
	{
		cout << "Positon out of range" << endl;
	}
}

/*
Sorting Link List
 */
void previousOrders::sort()
{
	struct node *ptr, *s;
	Order value;
	if (start == NULL)
	{
		cout << "The List is empty" << endl;
		return;
	}
	ptr = start;
	while (ptr != NULL)
	{
		for (s = ptr->next; s != NULL; s = s->next)
		{
			if (ptr->info.getOrderId() > s->info.getOrderId())
			{
				value = ptr->info;
				ptr->info = s->info;
				s->info = value;
			}
		}
		ptr = ptr->next;
	}
}

/*
Delete order at a given position
 */
void previousOrders::del()
{
	int pos, i, counter = 0;
	if (start == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	cout << "Enter the position of book to be deleted: ";
	cin >> pos;
	struct node *s, *ptr;
	s = start;
	if (pos == 1)
	{
		start = s->next;
	}
	else
	{
		while (s != NULL)
		{
			s = s->next;
			counter++;
		}
		if (pos > 0 && pos <= counter)
		{
			s = start;
			ptr = s;
			for (i = 1; i < pos; i++)
			{
				ptr = s;
				s = s->next;
			}
			ptr->next = s->next;
		}
		else
		{
			cout << "Position out of range" << endl;
		}
		free(s);
		cout << "Book Deleted" << endl;
	}
}

/*
Update a given order
 */
void previousOrders::update(Order newOrder)
{
	int pos, i;
	if (start == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	cout << "Enter the book postion to be updated: ";
	cin >> pos;
	struct node *s, *ptr;
	s = start;
	if (pos == 1)
	{
		start->info = newOrder;
	}
	else
	{
		for (i = 0; i < pos - 1; i++)
		{
			if (s == NULL)
			{
				cout << "There are less than " << pos << " elements";
				return;
			}
			s = s->next;
		}
		s->info = newOrder;
	}
	cout << "Book Updated" << endl;
}

/*
Searching an element
 */
void previousOrders::search()
{
	int value, pos = 0;
	bool flag = false;
	if (start == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	cout << "Enter the order ID to be searched: ";
	cin >> value;
	struct node *s;
	s = start;
	while (s != NULL)
	{
		pos++;
		if (s->info.getOrderId() == value)
		{
			flag = true;
			cout << "Book " << value << " is found at position " << pos << endl;
		}
		s = s->next;
	}
	if (!flag)
		cout << "Book " << value << " not found in the list" << endl;
}

/*
Reverse Link List
 */
void previousOrders::reverse()
{
	struct node *ptr1, *ptr2, *ptr3;
	if (start == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	if (start->next == NULL)
	{
		return;
	}
	ptr1 = start;
	ptr2 = ptr1->next;
	ptr3 = ptr2->next;
	ptr1->next = NULL;
	ptr2->next = ptr1;
	while (ptr3 != NULL)
	{
		ptr1 = ptr2;
		ptr2 = ptr3;
		ptr3 = ptr3->next;
		ptr2->next = ptr1;
	}
	start = ptr2;
}

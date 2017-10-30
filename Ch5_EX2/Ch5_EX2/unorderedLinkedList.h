#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of an unordered linked list. This class is
// derived from the class linkedListType. 
//***********************************************************

#include "linkedList.h"

using namespace std;

template <class Type>
class unorderedLinkedList: public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the list,
      //    otherwise the value false is returned.

    void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //    inserted at the beginning of the list, last points to
      //    the last node, and count is incremented by 1.
      //               

    void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem is
      //    inserted at the end of the list, last points to the
      //    last node, and count is incremented by 1.

    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing deleteItem
      //    is deleted from the list. first points to the first 
      //    node, last points to the last node of the updated 
      //    list, and count is decremented by 1.

	void deleteSmall();
	//Function to delete the smallest info in the list
	//Precondition: if the list is not empty
	//Postcondition:Otherwise, seaching for the node that containing the smallest info,
	// if found delete from the list;first points to the first node, current point to 
	// the next node

	void deleteAll();
	//Function to delete all the info from the list
	//Precondition: if the list is not empty
	//Postcondition: delete all the nodes from one by one

	linkedListType<Type> findNth(int kthElement);
	//Function to find the info of the kth element;
	//Precondition: if the list is empty, then terminate a program
	//Postcondition: find the info at a kth position

};


template <class Type>
bool unorderedLinkedList<Type>::
                   search(const Type& searchItem) const
{
    nodeType<Type> *current; //pointer to traverse the list
    bool found = false;
    
    current = first; //set current to point to the first 
                     //node in the list

    while (current != NULL && !found)    //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->link; //make current point to
                                     //the next node
    return found; 
}//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem;    //store the new item in the node
    newNode->link = first;      //insert newNode before first
    first = newNode;            //make first point to the
                                //actual first node
    count++;                    //increment count

    if (last == NULL)   //if the list was empty, newNode is also 
                        //the last node in the list
        last = newNode;
}//end insertFirst

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem;  //store the new item in the node
    newNode->link = NULL;     //set the link field of newNode
                              //to NULL

    if (first == NULL)  //if the list is empty, newNode is 
                        //both the first and last node
    {
        first = newNode;
        last = newNode;
        count++;        //increment count
    }
    else    //the list is not empty, insert newNode after last
    {
        last->link = newNode; //insert newNode after last
        last = newNode; //make last point to the actual 
                        //last node in the list
        count++;        //increment count
    }
}//end insertLast


template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;

    if (first == NULL)    //Case 1; the list is empty. 
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        if (first->info == deleteItem) //Case 2 
        {
            current = first;
            first = first->link;
            count--;
            if (first == NULL)    //the list has only one node
                last = NULL;
            delete current;
        }
        else //search the list for the node with the given info
        {
            found = false;
            trailCurrent = first;  //set trailCurrent to point
                                   //to the first node
            current = first->link; //set current to point to 
                                   //the second node

            while (current != NULL && !found)
            {
                if (current->info != deleteItem) 
                {
                    trailCurrent = current;
                    current = current-> link;
                }
                else
                    found = true;
            }//end while

            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->link = current->link;
                count--;

                if (last == current)   //node to be deleted 
                                       //was the last node
                    last = trailCurrent; //update the value 
                                         //of last
                delete current;  //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }//end else
    }//end else
}//end deleteNode

template <class Type>
void unorderedLinkedList<Type>::deleteSmall()
{
	nodeType<Type> *current = NULL; // a pointer to a current value
	nodeType<Type> *lineCurrent = NULL; //keep track for a current pointer

	nodeType<Type> *small= NULL; // a pointer to a small value 
	nodeType<Type> *lineSmall = NULL; // keep track for a small value

	if (first == NULL)    //the list is empty. 
	{
		cout << "Cannot delete from an empty list."
			<< endl;
	}
	else
	{
		small = first; // a small pointer point to a first node
		lineCurrent = first; // a lineCurrent point to a first node
		current = first->link; // a current pointer point to the next node

		//search for the smallest info
		while (first != NULL && current != NULL)
		{
			if (small->info > current->info)
			{
				lineSmall = lineCurrent; //switch track to a lineSmall pointer
				small = current; //switch a pointer to a small pointer
			}

			lineCurrent = current;// point to a current track
			current = current->link; // advance to the next node
		}
		// if the first node is the smallest value
		if (first->info == small->info)
		{
			small = first;
			first = first->link;
			count--;
				//if the first node is the only node
				if (first == NULL)
					last = NULL;
			delete small;
		}
		else if (first->info != small->info)
		{
			lineSmall->link = small->link;
			count--;
			if (last == small) //if the last node equal to small
				last = lineSmall;
			delete small;
		}
		else
		{
			cout << "The item to be delete is not in"
				<< "the list. " << endl;
		}//end else
	}//end else			
}//end delete small

template <class Type>
void unorderedLinkedList<Type>::deleteAll()
{
	nodeType<Type> *deleteAll = NULL; // set a delete pointer
	nodeType<Type> *trialDelete = NULL; // set a trialDelete pointer

	if (first == NULL)
	{
		cout << "The list is empty." << endl;
	}

	else
	{
		deleteAll = first; // set a deleteAll point to a first node 
		trialDelete = first->link; // set trailDelete point to a first node

		while (first != NULL && deleteAll != NULL)
		{
			if (first->info == deleteAll->info)
			{
				// set the link advance to the next node
				first = first->link; 
				count--;

				//set trialDelete advance to the next node
				trialDelete = deleteAll->link;

				//delete info
				delete deleteAll;

				//assign trialDelete to deleteAll
				deleteAll = trialDelete;
			}
			// if a first node is NULL, the last node will be NULL
			if (first == NULL)
				last = NULL;
		}//end while
	}//end else
}//end deleteAll

template <class Type>
linkedListType<Type> unorderedLinkedList<Type>::findNth(int kthElement)
{
	nodeType<Type> *findKth = NULL;
	nodeType<Type> *trailFindKth = NULL;

	//set findKth to first
	findKth = first;

	if (first == NULL)
	{
		cout << "The list is empty" << endl;
	}

	while (first != NULL)
	{	
		if (kthElement == count)
		{
			findKth->info = first->info;
		}
		else if (!count) // if no element exist
		{
			break;  // terminate
		}
		count++;
		findKth = findKth->link;
	}
	return findKth;
}

#endif

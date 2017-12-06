#ifndef H_MilkListType
#define H_MilkListType

#include <string>
#include "milkType.h"
#include "unorderedLinkList.h"

using namespace std;

class MilkListType:public unorderedLinkedList<MilkType>
{
public: 
	bool MilkSearch(string title) const;
	//Function to search the list to see whether a
	//particular title, specified by the parameter title,
	//is in the store.
	//Postcondition: Returns true if the title is found, and 
	//    false otherwise.

	bool milkCheckVender(string title) const;
	//Function to determine whether a particular milk is in 
	//the store.
	//Postcondition: Returns true if the milk’s title is the
	//    same as title, and false otherwise.

	void MilkUpdateStock(string title, int num);
	//Function to update the number of milk cartons
	//by adding the value of the parameter num. The 
	//parameter title specifies the name of the milk for
	
	void MilkPrintTitle() const;
	//Function to print the titles of all the milk in the store.
private:
	void searchMilkList(string title, bool& found,
		nodeType<MilkType>* &current) const;
	//This function searches the video list for a particular
	//video, specified by the parameter title. 
	//Postcondition: If the video is found, the parameter found is
	//    set to true, otherwise it is set to false. The parameter
	//    current points to the node containing the video.
};

void MilkListType::searchMilkList(string vender, bool& found,
	nodeType<MilkType>* &current) const
{
	found = false;   //set found to false

	current = first; //set current to point to the first node
					 //in the list

	while (current != NULL && !found)     //search the list
		if (current->info.checkManufacturer(vender)) //the item is found
			found = true;
		else
			current = current->link; //advance current to 
									 //the next node    
}//end searchMilkList


bool MilkListType::MilkSearch(string title) const
{
	bool found = false;
	nodeType <MilkType> *location;

	searchMilkList(title, found, location);

	return found;
	
}//end MilkSearch()

bool MilkListType::milkCheckVender(string title) const
{
	bool found = false;
	nodeType <MilkType> *location;

	searchMilkList(title, found, location);

	return found;

}

void MilkListType::MilkPrintTitle() const
{
	nodeType<MilkType>* current;

	current = first;
	while (current != NULL)
	{
		current->info.printInfo();
		current = current->link;
	}
}


#endif 


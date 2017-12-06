// Rattikarn Dudley

#include <iostream>
#include <string>
#include "queueAsArray.h"
#include "milkType.h"
#include "arrayList.h"


void addInfo(MilkType in[]); // prototype of function addInfo

int main()
{
	
	queueType<MilkType> listQueue;
	MilkType milkArray[10];
	MilkType queueRack[10];
	MilkType curDate;
	int day;
	string date;
	
	//declare array object milk to 10 elements
	MilkType milk[10];

	// add data and milk from function
	addInfo(milk);
	//check milk if the date is expired
	//add only a good milk

	//user input
	cout << "Today date" << endl;
	cin >> date;
	cout << "Spoilage Date" << endl;
	cin >> day;
	curDate.setDate(date);

	// check if the milk cartons is more than spoilage
	//if it more than spolage date, remove from the list 
	int count = 9;
	int track = 0; // track to keep how many of good milk
	for (int i = count; i >= 0; i--)
	{
		//if the milk cartons is less than the spoilage age
		//add milk to the list
		if (milk[i].getSumDate(curDate)< day)
		{
			track += 1;
			//start to assign the value at index 0
			milkArray[track-1] = milk[i];		
		}
	}
	
	for (int i = 0; i < track-1; i++)
	{
		for (int j = 0; j < track-i-1; j++)
		{
			//check old date if it the item found old swap to first
			if (milkArray[j].parseDate() > milkArray[j+1].parseDate())
			{
				swap(milkArray[j], milkArray[j+1]);
			}
		}
	}
	// add sort milk list to the queue
	for (int i = 0; i < track; i++)
	{
		listQueue.addQueue(milkArray[i]);
	}
		
	//display list from the oldest to the newest date milk cartons
	cout << "List of a sorted milk cartons " << endl;
	while (!listQueue.isEmptyQueue())
	{
		cout << listQueue.front() << endl;
		listQueue.deleteQueue();
	}

	return 0;
}

void addInfo(MilkType in[])
{
	string vender;
	double price;
	string date;

	int i;
	for (i = 0; i < 10; i++)
	{
		cout << "Enter a product manufacturer" << endl;
		cin>> vender;
		cout << "Enter a price" << endl;
		cin >> price;
		cout << "Enter a date to put in a shelf" << endl;
		cout << "Format mmddyyyy example 01032017 " << endl;
		cin >> date;
		//set price and vender by method setMilkInfo
		 in[i].setMilkInfo(vender, price);	
		 in[i].setDate(date);
		//add date
		cout << endl;
	}
}




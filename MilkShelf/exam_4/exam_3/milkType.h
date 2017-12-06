// Header file MilkType.h
//author Rattikarn Dudley
#ifndef H_MilkType
#define H_MilkType

#include <iostream>
#include "queueAsArray.h"
#include <sstream>
#include "arrayList.h"

class MilkType
{
	friend ostream& operator<<(ostream&, const MilkType&);
	//Overloads the stream insertion operator

public:
	MilkType();
	//defalut constructor
	//automaticly call when create an object

	MilkType(string vender, double price);
	//construtor with parameter
	//Sets manufacturer and cost according to the parameters.
	//Postcondition: fmanufacturer = vender cost = price

	void setMilkInfo(string vender, double price);
	//Function to set details of milk information
	//milk informations are set according to the parameters.
	//Postcondition: manufacturer = vender, cost = price

	void setDate(string date);
	//Function to set date according to the parameters.
	//Postcondition: sellByDate = date

	string getDate();	
	//Function to return the sellByDate.
	//Postcondition: The value of sellByDate is returned.

	double getPrice();	
	//Function to return the cost.
	//Postcondition: The value cost is returned.

	string getManufactuere();
	//Function to return the manufacturer.
	//Postcondition: The value manufacturer is returned.

	int parseDate();
	//Fucntion to converse string sellBydate to interger date1
	//use function call sscanf_s to convert string to integer
	//Postcondition return integer of date1

	int monthExtract();
	//Function to convert month string from list type to integer.
	//Postcondition: The int month return

	int dayExtract();
	//Function to convert day string from list type to integer.
	//Postcondition: The int day return

	int yearExtract();
	//Function to convert year string from list type to integer.
	//Postcondition: The int year return

	bool isLeapYear();
	//Function check a leap year.
	//Postcondition: if it is a leap year, return true

	int getDayInMonth(int month);
	//Function get a day of each month.
	//Postcondition: a number of month choice return

	int getSumDate(MilkType other);
	//Function to get a sum of date
	//Postcondition: a sum of date return

	int countLeapYears();
	// This function counts number of leap years before the
	// given date
	//Postcondition: a number of leap year return

	
	//overload operator
	bool operator==(const MilkType&) const;
	bool operator!=(const MilkType&) const;
	bool operator<(const MilkType&) const;

private:
	
	string sellBydate;   // variable to store sell date
	string manufacturer; // variable to store a manufacturer
	double cost;		 // varaible to store a price of milk

};

MilkType::MilkType()
{
	string sellBydate = "";
	string manufacturer = "";
	double cost = 0.0;
}
MilkType::MilkType(string vender, double price)
{
	setMilkInfo(vender, price);
}
void MilkType::setMilkInfo(string vender, double price)
{
	manufacturer = vender;
	cost = price;
}

void MilkType::setDate(string date)
{
	sellBydate = date;
}

string MilkType::getDate()
{
	return sellBydate;
}

string MilkType::getManufactuere()
{
	return manufacturer;
}

double MilkType::getPrice()
{
	return cost;
}

int MilkType::parseDate()
{
	string sday, smonth, syear;
	int date,month,day,year;

	//get date from function getDate()
	string temp = getDate();
	//get date  in integers
	month = monthExtract();
	day = dayExtract();
	year = yearExtract();

	//calculate
	date = year * 1000 + month * 100 + day;

	return date;
}

int MilkType::monthExtract()
{
	string month;
	int iMonth = 0;
	string temp = getDate();
	//extract month
	month = temp.substr(0, 2);
	stringstream mm(month);
	mm >> iMonth;

	return iMonth;	
}

int MilkType::dayExtract()
{
	string days;
	int iDay = 0;
	string temp = getDate();
	//extract day
	days = temp.substr(2, 2);
	stringstream dd(days);
	dd >> iDay;

	return iDay;
}

int MilkType::yearExtract()
{
	string years;
	int iYear = 0;
	string temp = getDate();
	//extract year
	years = temp.substr(4, 8);
	stringstream yy(years);
	yy >> iYear;

	return iYear;
}
bool MilkType::isLeapYear()
{
	int years = yearExtract();
	
	return (years % 4 == 0 && years % 100 != 0 || years % 400 == 0);
}
int MilkType::countLeapYears()
{
	int years = yearExtract();
	int months = monthExtract();
	// Check if the current year needs to be considered
	// for the count of leap years or not
	if (months <= 2)
		years--;

	// An year is a leap year if it is a multiple of 4,
	// multiple of 400 and not a multiple of 100.
	return years / 4 - years / 100 + years / 400;
}

int MilkType::getDayInMonth(int month)
{

	int day = 0;
	//use case month to identify the right days of month
	switch (month)
	{
	case 1: day = 31; break;
	case 2: 
			if (isLeapYear())
			{
				day = 29;
				break;
			}
			else
			{
				day = 28;
				break;
			}
			break;
	case 3: day = 31; break;
	case 4: day = 30; break;
	case 5: day = 31; break;
	case 6: day = 30; break;
	case 7: day = 31; break;
	case 8: day = 31; break;
	case 9: day = 30; break;
	case 10: day = 31; break;
	case 11: day = 30; break;
	case 12: day = 31; break;	
	default:
		cout << "an error occurs " << endl;
		break;
	}
	return day;
}

int MilkType::getSumDate(MilkType other)
{
	const int monthDays[12] = { 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };
	//first extract all the date from the array list
	int day, year, month, day_other, month_other, year_other;

	//from the date from the milk cartons
	day = dayExtract();
	month = monthExtract();
	year = yearExtract();
	int getMonth = getDayInMonth(month);

	//from the date from current date
	day_other = other.dayExtract();
	month_other = other.monthExtract();
	year_other = other.yearExtract();
	int getMonth_other = other.getDayInMonth(month_other);
	
	long int listDay = year * 365 + day;
	// Add days for months in given date
	for (int i = 0; i < month - 1; i++)
		listDay += monthDays[i];
	listDay += countLeapYears();

	// SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE day_other

	long int currentDay = year_other * 365 + day_other;
	for (int i = 0; i < month_other - 1; i++)
		currentDay += monthDays[i];
	currentDay += countLeapYears();
	
	// return difference between two counts
	if (listDay > currentDay)
	{
		return (listDay - currentDay);
	}
	else
	{
		return (currentDay - listDay);
	}

}
	
bool MilkType::operator==(const MilkType& other) const
{
	return (manufacturer == other.manufacturer);
}

bool MilkType::operator!=(const MilkType& other) const
{
	return (manufacturer != other.manufacturer);
}
bool MilkType::operator<(const MilkType& other) const
{
	return (sellBydate < other.sellBydate);
}

ostream& operator<<(ostream& osObJect, const MilkType& milkType)
{
	osObJect << "Date: " << milkType.sellBydate << " " ;
	osObJect << "Manufacturer: " << milkType.manufacturer << " ";
	osObJect << "Price: " << milkType.cost << " ";

	return osObJect;
}

#endif

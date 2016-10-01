#include <iostream>

int main()
{

	int count;
	float num, total,num2,average;

	std::cout << " Please type in the total number of data values to be average: " << std::endl;
	std::cin >> num;
	total = 0;
	count = 1;

	while (count <= num)
	{
		std::cout << " \n enter a number: ";
		std::cin >> num2;
		total = total + num2;
		std::cout << " The total is now: " << total;
		count++;
	}

	average = total / count;
	std::cout << "\n\n the average of the data value are  " << average << std::endl;

	return 0;
}
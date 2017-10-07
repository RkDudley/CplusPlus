#include <iostream>
#include <string>

// Program to searching how many same letter in a string name 
int search(const std::string &array, char character);

int main()
{
	std::string array = "Rattikarn";
	char a = 'a';

	std::cout << search(array, a);

	return 0;

}

int search(const std::string &array, char character)
{
	int i;
	int index;

	for (i = 0; i < array.size(); i++)
	{
		if (array[i] == character)
		{
			index = i;
		}
		else
		{
			-1;
		}
	}
	return index;
}

#include <iostream>
#include <cmath>

int main()
{
	float number = 0.0f;
	char choices;
	float sum = 0.0f;

	std::cout << "Enter a number: ";
	std::cin >> number;
	std::cout << "Enter your options: ";
	std::cin >> choices;

	switch (choices) {
	case 'c':
	case 'C':
		sum = cos(number);
		std::cout <<"cos "<< number <<" = "<< sum;
		break;
	case 's':
	case 'S':
		sum = sin(number);
		std::cout << "sin " << number << " = " << sum;
		break;
	case 'f':
	case 'F':
		sum = floor(number);
		std::cout << "floor " << number << " = " << sum;
		break;
	case 'r':
	case'R':
		sum = round(number);
		std::cout << "round " << number << " = " << sum;
		break;
	case 'p':
	case 'P':
		sum = number + 1;
		std::cout  << number << " + 1 = " << sum;
		break;
	case 'm':
	case 'M':
		sum = number -1;
		std::cout << number << " - 1 = " << sum;
		break;
	case 't':
	case 'T':
		sum = tan(number);
		std::cout << "tan " << number << " = " << sum;
		break;
	default:
		std::cout << " error occur: ";
		break;
	}

	return 0;

}
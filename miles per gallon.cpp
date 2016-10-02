#include <iostream>

int main()
{

	float mileage = 0;
	float gallon = 0;
	float mpg = 0;
	float Miles = 0;
	float previousMiles = 0;
	float totalGallon = 0;
	float totalMiles = 0;


	while (gallon != -1) {

		std::cout << "Enter gallon to be used\n"
			<< "press -1 to exit\n";
		std::cin >> gallon;

		if (gallon > 0) {
			std::cout << "Enter a previous miles" << std::endl;
			std::cin >> previousMiles;
			std::cout << "Enter a current mileage" << std::endl;
			std::cin >> mileage;

			Miles = mileage - previousMiles;
			std::cout << "driven miles " << Miles << std::endl;

			mpg = Miles / gallon;
			std::cout << "miles per gallon " << mpg << std::endl;

			totalGallon += gallon;
			std::cout << "total used gallon " << totalGallon << std::endl;

			totalMiles += Miles;
			std::cout << "total driven mileage " << totalMiles << std::endl;
		}
	}
	return 0;
}
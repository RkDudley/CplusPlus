#include <iostream>
#include <iomanip>

int main() {
	float x1 = 3.0;
	float x2 = 7.0;
	float y1 = 7.0;
	float y2 = 12.0;
	float slope = 0;
	// assignment statement
	slope = (y2 - y1) / (x2 - x1);

	std::cout << std::setw(5) 
		      << std::setprecision(2) 
		      << std::fixed
		      << " The value of slope is " << slope << std::endl;

	return 0;
}
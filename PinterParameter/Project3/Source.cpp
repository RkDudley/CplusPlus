#include <iostream>
// program to output array value by passing pointer as parameter 
// Output from function show

void show(double *val, int numels);

int main() {
	int const SIZE = 10;
	double rates[SIZE] = { 6.5,7.2,7.5,8.3,8.6,9.4,9.6,9.8,10 };

	show(rates, SIZE);

	return 0;
}

void show(double *val, int numels) {
	int i;

	for (i = 0; i < numels; i++) {
		std::cout << *(val + i) << std::endl;
	}
}
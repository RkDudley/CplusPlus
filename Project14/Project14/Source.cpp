
#include <iostream>
int main()
{

	int a = 3;
	int b = 4;
	int temp = 0;
    
	temp = b;
	b = a;
	a = temp;

	std::cout << " a " << b << " b " << a;

	return 0;
}

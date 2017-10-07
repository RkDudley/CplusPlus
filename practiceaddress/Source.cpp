#include <iostream>
#include <string>
using namespace std;

int main() {

	const int SIZE = 16;
	int i;
	char *samPtr; //declare a pointer to int
	char samtest[SIZE] = { 'T','h','i','s',' ', 'i', 's',' ', 'a',' ', 's','a','m','p','l','e' };

	samPtr = &samtest[0]; // store the starting array address
	for (i = 0; i < SIZE; i++) {
		cout << *(samPtr + i);
	}

	return 0;


}
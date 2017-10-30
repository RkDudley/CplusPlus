#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	int intArray[] = { 5,6,8,3,40,36,98,29,75 };

	vector <int> vecList(9);

	ostream_iterator<int> screen (cout, " ");

	cout << "Line 11: intArray: ";
	copy(intArray, intArray + 9, screen);
	cout << endl;

	copy(intArray, intArray + 9, vecList.begin());

	cout << "Line 15: vecList: ";
	copy(vecList.begin(), vecList.end(), screen);
	cout << endl;

	copy(intArray + 1, intArray + 9, intArray);
	cout << "Line 19: After shifting the element one "
		<< "position to the left, intArray: " << endl;
	copy(intArray, intArray + 9, screen);
	cout << endl;

	copy(vecList.rbegin() + 2, vecList.rend(),vecList.rbegin());

	cout << "Line 23: After shifting the elements down"
		<< "by two positions, VecList: " << endl;
	copy(vecList.begin(), vecList.end(), screen);
	cout << endl;

	return 0;

}

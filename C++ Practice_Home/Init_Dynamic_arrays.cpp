#include <iostream>
using namespace std;

// Dynamic array initialization could not be performed in earlier versions of C++. But according to C++20 standard, we CAN initialize dynamically allocated arrays. However, all of the compilers have not implemented this yet.

int main(void) {

	int x; 

	// int *array{ new int[5]{ 10, 7, 15, 3, 11 } };
	int *array = new int[5]{ 10, 7, 15, 3, 11 };

	cout << "Array elements: " << endl;

	for (x = 0; x < 5; x++) {

		cout << array[x] << endl;
	}

	return 0;
}
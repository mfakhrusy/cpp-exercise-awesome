// (Arithmetic, Smallest, and Largest) Write a program that inputs three integers
// from the keyboard and prints the sum, average, product, smallest, and largest 
// of these numbers.

#include <iostream>

using namespace std;

int main() {

	int num1, num2, num3;
	cout << "Input three different integers: ";
	cin >> num1 >> num2 >> num3;

	// calculate sum
	int sum = num1 + num2 + num3;
	cout << "Sum is " << sum << endl;

	// calculate average
	double average = static_cast<double>(sum)/3;
	cout << "Average is " << average << endl;

	// calculate product
	int product = num1 * num2 * num3;
	cout << "Product is " << product << endl;

	// calculate smallest
	int smallest = 0;
	if ( num1 > num2 ) {
		if (num2 > num3 ) {
			cout << "Smallest is " << num3;
		} else {
			cout << "Smallest is " << num2;
		}
	} else {
		if ( num1 > num3 ) {
			cout << "Smallest is " << num3;
		} else {
			cout << "Smallest is " << num1;
		}
	}

	cout << endl;

	// calculate largest
	int largest = 0;
	if ( num1 > num2 ) {
		if (num1 > num3 ) {
			cout << "Largest is " << num1;
		} else {
			cout << "Largest is " << num3;
		}
	} else {
		if ( num2 > num3 ) {
			cout << "Largest is " << num2;
		} else {
			cout << "Largest is " << num3;
		}
	}
	cout << endl;
	return 0;
}

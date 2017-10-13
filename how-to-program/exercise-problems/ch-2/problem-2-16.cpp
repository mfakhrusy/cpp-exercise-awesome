// 2.16 (Arithmetic) Write a program that asks the user to enter three numbers, 
// obtains the two numbers from the user and prints the sum, product of the three numbers

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

	int num1, num2, num3;

	cout << "Insert number 1: ";
	cin >> num1;
	cout << "Insert number 2: ";
	cin >> num2;
	cout << "Insert number 3: ";
	cin >> num3;
	cout << endl;

	cout << "Sum of all three numbers: " << num1 + num2 + num3 << endl;
	
	return 0;
	
}

// (Digits of an Integer) Write a programthat inputs a five-digit integer, 
// separates the integer into its digits and prints them separated by three 
// spaces each.

#include <iostream>

using namespace std;

int main() {

	int num;
	cout << "Enter exactly 5 digit number: ";
	cin >> num;
	
	// 1st digit
	int digit_1 = num / 10000;
	cout << digit_1 << " ";

	// renew num
	num = num - digit_1 * 10000;

	// 2nd digit
	int digit_2 = num / 1000;
	cout << digit_2 << " ";

	// renew num
	num = num - digit_2 * 1000;

	// 3rd digit
	int digit_3 = num / 100;
	cout << digit_3 << " ";

	// renew num
	num = num - digit_3 * 100;
	
	// 4th digit
	int digit_4 = num / 10;
	cout << digit_4 << " ";

	// renew num
	num = num - digit_4*10;

	//5th digit
	cout << num << endl;
	return 0;
}

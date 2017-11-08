#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// change array to long long int array
std::vector<long long> arrayToLongLongInt( std::string, int );

int main() {

	int arraySize;
	(std::cin >> arraySize).get();
	
	// input big number
	std::string bigNumberArrayString;
	std::getline(std::cin, bigNumberArrayString);

	// convert it to array of big number
	std::vector<long long> bigNumberArray = arrayToLongLongInt( bigNumberArrayString, arraySize );

	// sum vector element
	long long bigNumberSum = 0;	
	std::for_each(bigNumberArray.begin(), bigNumberArray.end(), [&] (long long n) {
		bigNumberSum += n;
	});

	std::cout << bigNumberSum << std::endl;

	return 0;
}

// implementation of arrayToLongLongInt
std::vector<long long> arrayToLongLongInt( std::string bigNumberArrayString, int arraySize ) {

	std::vector<long long> bigResult(arraySize);
	std::istringstream iss(bigNumberArrayString);
	long long tempNumber;
	int i = 0;
	while (iss >> tempNumber) {
		bigResult[i] = tempNumber;
		i++;
	}

	return bigResult;
};

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<int> stringToVector( std::string, int);

int main() {

	// input arraySize
	int arraySize;
	(std::cin >> arraySize).get();

	// input string of array of integer and split to array of integer
	std::string stringArrayInt;
	std::getline( std::cin, stringArrayInt );

	std::vector<int> arrayInt = stringToVector( stringArrayInt, arraySize);

	// check how many negative, how many positive, and how many zero number
	int countPositive = 0;
	int countNegative = 0;
	int countZero = 0;
	for ( auto i = 0; i < arraySize; i++ ) {
		if ( arrayInt[i] > 0 ) {
			countPositive++;
		} else if ( arrayInt[i] < 0) {
			countNegative++;
		} else {
			countZero++;
		}
	}

	// calculate the fraction
	double fractionPositive = static_cast<double>(countPositive)/static_cast<double>(arraySize);
	double fractionNegative = static_cast<double>(countNegative)/static_cast<double>(arraySize);
	double fractionZero = static_cast<double>(countZero)/static_cast<double>(arraySize);


	std::cout << fractionPositive << std::endl;
	std::cout << fractionNegative << std::endl;
	std::cout << fractionZero << std::endl;

	return 0;
}

// stringToVector
std::vector<int> stringToVector( std::string inputParameters, int vectorSize ) {
	std::vector<int> result( vectorSize );
	
	std::istringstream iss( inputParameters );
	int tempNumber = 0;

	int i = 0;
	while ( iss >> tempNumber ) {
		result[i] = tempNumber;
		i++;
	}

	return result;
}

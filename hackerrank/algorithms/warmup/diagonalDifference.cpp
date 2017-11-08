#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

std::vector<int> stringToVector( std::string, int);

int main () {

	// input line number
	int matrixSize;
	(std::cin >> matrixSize).get();

	// input each line and calculate difference depending to line number.
	
	int diffTotal = 0;
	for (auto i = 0; i < matrixSize; i++) {
		// input from user
		std::string inputMatrixRow;
		std::getline( std::cin, inputMatrixRow );

		// change it to vector
		std::vector<int> tempRowVector = stringToVector( inputMatrixRow, matrixSize );

		// calculate difference
		int tempDiff = 0;
		tempDiff = tempRowVector[i] - tempRowVector[matrixSize - 1 - i];
		
		// append to diffTotal
		diffTotal += tempDiff;
	}
	// absolute value
	diffTotal = abs(diffTotal);

	std::cout << diffTotal;

	return 0;
}

// function definition
// stringToArray
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
};

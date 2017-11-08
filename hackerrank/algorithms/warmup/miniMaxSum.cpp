#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

std::vector<long long> stringToVector( std::string, int);

int main() {

	// input string and change to vector of integer
	std::string stringVectorInt;
	std::getline(std::cin, stringVectorInt);
	static const int vectorSize = 5; // because it's stated as const
	std::vector<long long> vectorInt = stringToVector( stringVectorInt, vectorSize );

	// erase each vector, and sum it
	// declare new vector containing summation
	std::vector<long long> sumVectorInt(vectorSize);
	for (auto i = 0; i < vectorSize; i++) {
		// copy vectorInt to tempVector because vector::erase modifies the container
		std::vector<long long> tempVector = vectorInt;
		tempVector.erase( tempVector.begin() + i );

		long long tempSumVector = 0;
		for ( auto n : tempVector ) {
			tempSumVector += n;
		}

		// append the result to a new vector containing each summation
		sumVectorInt[i] = tempSumVector;
	}

	// compute min and max element
	auto minMaxElem = std::minmax_element(sumVectorInt.begin(), sumVectorInt.end());

	std::cout << sumVectorInt[minMaxElem.first - sumVectorInt.begin()] << " " << sumVectorInt[minMaxElem.second - sumVectorInt.begin()] << std::endl;

}

// stringToArray
std::vector<long long> stringToVector( std::string inputParameters, int vectorSize ) {
	std::vector<long long> result( vectorSize );
	
	std::istringstream iss( inputParameters );
	long long tempNumber = 0;

	int i = 0;
	while ( iss >> tempNumber ) {
		result[i] = tempNumber;
		i++;
	}

	return result;
}

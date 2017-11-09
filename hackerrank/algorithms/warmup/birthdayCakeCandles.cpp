#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<int> stringToVector( std::string, int );
int countDuplicatedInt( std::vector<int>, int );

int main() {

	// insert number of candles
	int candleNumber;
	(std::cin >> candleNumber).get();

	// insert candle heights
	std::string stringCandleHeightsVector;
	std::getline(std::cin, stringCandleHeightsVector);
	
	// convert to vector
	std::vector<int> candleHeightsVector = stringToVector(stringCandleHeightsVector, 
			candleNumber);

	// check maximum candle height
	std::vector<int>::iterator candleMaxHeightPosition;
	candleMaxHeightPosition = std::max_element(candleHeightsVector.begin(), 
		   candleHeightsVector.end());

	int candleMaxHeight = candleHeightsVector[std::distance(candleHeightsVector.begin(),
			candleMaxHeightPosition)];

	// calculate duplicated max height
	int countCandleMaxHeight = countDuplicatedInt(candleHeightsVector, 
			candleMaxHeight);

	std::cout << countCandleMaxHeight << std::endl;


	return 0;
}

std::vector<int> stringToVector( std::string stringVectorInt, int vectorSize ) {
	
	std::vector<int> result(vectorSize);

	std::istringstream iss(stringVectorInt);

	int tempNumber;
	int i = 0;
	while (iss >> tempNumber) {
		result[i] = tempNumber;
		i++;
	}

	return result;
};

int countDuplicatedInt( std::vector<int> vectorOfInt, int baseInt ) {

	int duplicatedInt = 0;

	for (size_t i = 0; i < vectorOfInt.size(); i++) {
		if (vectorOfInt[i] == baseInt) {
			duplicatedInt++;
		}
	}

	return duplicatedInt;
};

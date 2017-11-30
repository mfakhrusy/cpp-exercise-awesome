#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<int> strToVector(std::string, int);
int calcFruit(int treeLocation, int fruitNumber, int houseInit, int houseFinal, 
		std::vector<int> distanceFruit);

int main() {

	// input from user and save it to each respective variables
	int houseInit, houseFinal;
	int locationAppleTree, locationOrangeTree;
	int appleNumber, orangeNumber;

	(std::cin >> houseInit >> houseFinal).get();
	(std::cin >> locationAppleTree >> locationOrangeTree).get();
	(std::cin >> appleNumber >> orangeNumber).get();

	// input distance of apple and orange from the tree, use vector
	std::string strDistanceApple;
	std::string strDistanceOrange;
	std::getline(std::cin, strDistanceApple);
	std::getline(std::cin, strDistanceOrange);

	std::vector<int> distanceApple = strToVector(strDistanceApple, appleNumber);
	std::vector<int> distanceOrange = strToVector(strDistanceOrange, orangeNumber);

	// calculate number of apple and orange fall to house region
	int calcApple = calcFruit(locationAppleTree, appleNumber, houseInit, houseFinal, 
			distanceApple);

	int calcOrange = calcFruit(locationOrangeTree, orangeNumber, houseInit, houseFinal, 
			distanceOrange);

	std::cout << calcApple << std::endl << calcOrange << std::endl;


	return 0;
}

std::vector<int> strToVector(std::string stringValue, int vectorSize) {

	std::vector<int> result(vectorSize);
	
	std::istringstream iss(stringValue);
	int tempNumber;
	int i = 0;
	while (iss >> tempNumber) {
	
		result[i] = tempNumber;
		i++;
	}

	return result;
}

int calcFruit(int treeLocation, int fruitNumber, int houseInit, int houseFinal, 
		std::vector<int> distanceFruit) {

	int result = 0;

	for (auto distance : distanceFruit) {
		int fruitRelativeDistance = treeLocation + distance;

		if (fruitRelativeDistance >= houseInit 
				&& fruitRelativeDistance <= houseFinal ) {
			
			result++;
		
		}
	}

	return result;
}

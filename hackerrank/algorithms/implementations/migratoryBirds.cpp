#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <array>

std::vector<int> strToVector(std::string, int);

int main() {

	int birdsNumber;
	(std::cin >> birdsNumber).get();

	std::string stringBirdsType;
	std::getline(std::cin, stringBirdsType);
	std::vector<int> vecBirdsType = strToVector(stringBirdsType, birdsNumber);
	
	//int countType1, countType2, countType3, countType4, countType5;
	std::array<int, 5> countBirdType = {0, 0, 0, 0, 0};
	for (auto birdsType : vecBirdsType) {
		
		switch(birdsType) {
			case 1:
				countBirdType[0]++;
				break;
			case 2:
				countBirdType[1]++;
				break;
			case 3:
				countBirdType[2]++;
				break;
			case 4:
				countBirdType[3]++;
				break;
			case 5:
				countBirdType[4]++;
				break;
			default:
				std::cout << "Bird type is wrong!\n";
		}
	}

	// check maximum
	int mostType = 1;
	int tempMostBirdType = countBirdType[0];
	for (auto i = 0; i < countBirdType.size(); i++) {
		if (countBirdType[i] > tempMostBirdType) {
			mostType = i + 1;
			tempMostBirdType = countBirdType[i];
		}
	}

	std::cout << mostType << std::endl;
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

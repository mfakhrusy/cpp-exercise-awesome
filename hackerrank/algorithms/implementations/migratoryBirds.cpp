#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<int> strToVector(std::string, int);

int main() {

	int birdsNumber;
	(std::cin >> birdsNumber).get();

	std::string stringBirdsType;
	std::getline(std::cin, stringBirdsType);
	std::vector<int> vecBirdsType = strToVector(stringBirdsType, birdsNumber);
	
	for ()
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

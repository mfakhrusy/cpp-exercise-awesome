#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

std::vector<int> strToVector(std::string, int);

int main() {

	// input
	int arraySize;
	(std::cin >> arraySize).get();

	std::string stringInt;
	std::getline(std::cin, stringInt);
	std::vector<int> vectorInt = strToVector(stringInt, arraySize);

	// reverse vector with std::reverse in algorithm
	std::reverse(vectorInt.begin(), vectorInt.end());

	for (auto n : vectorInt)
		std::cout << n << " ";
	std::cout << std::endl;

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



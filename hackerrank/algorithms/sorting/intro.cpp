#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<int> stringToVector(std::string, int);

int main () {

	// input from user
	int numberToSearch;
	int vectorSize;
	(std::cin >> numberToSearch).get();
	(std::cin >> vectorSize).get();

	std::string stringVector;
	std::getline(std::cin, stringVector);
	std::vector<int> intVector = stringToVector(stringVector, vectorSize);

	int result = 0;
	int count = 0;
	for (auto n : intVector) {
	
		if (numberToSearch == n) {
			result = count;
			break;
		}

		count++;
	}

	std::cout << result << std::endl;

	return 0;
}

std::vector<int> stringToVector(std::string stringVector, int vectorSize) {

	std::vector<int> resultVector(vectorSize);
	std::istringstream iss(stringVector);

	int tempNumber;
	int count = 0;
	while (iss >> tempNumber) {
	
		resultVector[count] = tempNumber;
		count++;
	}

	return resultVector;
}

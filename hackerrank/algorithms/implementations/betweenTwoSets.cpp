#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<int> strToVector(std::string, int);

int main() {

	// input number of nA and nB
	int nA, nB;
	(std::cin >> nA >> nB).get();

	// input set of A and save it to vector
	std::string stringA;
	std::string stringB;

	std::getline(std::cin, stringA);
	std::getline(std::cin, stringB);

	std::vector<int> vectorA = strToVector(stringA, nA);
	std::vector<int> vectorB = strToVector(stringB, nB);
	
	// get the lowest value and highest value to check
	// lowest is on the last value of A and highest is on the first value of B
	int lowest = vectorA[vectorA.size() - 1];
	int highest = vectorB[0];

	int countBetween = 0;
	for (auto n = lowest; n <= highest; n++) {
		
		int countA = 0;
		for (auto j : vectorA) {
			
			if (n % j == 0) {
				countA++;
			}
		}

		int countB = 0;
		for (auto j : vectorB) {
		
			if (j % n == 0) {
				countB++;
			}
		}
	
		if (countA == nA && countB == nB) {
			countBetween++;
		}
	}

	std::cout << countBetween << std::endl;

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

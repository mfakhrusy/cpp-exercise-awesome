#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<int> strToVector(std::string, int);

int main() {

	int n, k;
	(std::cin >> n >> k).get();

	std::string stringN;
	std::getline(std::cin, stringN);
	std::vector<int> vectorN = strToVector(stringN, n);


	int countDivisablePair = 0;
	for (auto i = 0; i <= (n - 2); i++) { // n - 2 because we want a pair to be accumulated

		// j = i + 1 because i is not included in the following loop
		for (auto j = i + 1; j <= (n - 1); j++) { // try until the last index (n - 1)
			int tempSum = vectorN[i] + vectorN[j];
			if (tempSum % k == 0) {
				countDivisablePair++;
			}
		}	
	}
	std::cout << countDivisablePair << std::endl;

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

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric> // for std::accumulate

std::vector<int> strToVector(std::string, int);
int main() {

	int chocolateBar;
	(std::cin >> chocolateBar).get();

	std::string stringChocolateBar;
	std::getline(std::cin, stringChocolateBar);
	std::vector<int> vecChocolateBar = strToVector(stringChocolateBar, chocolateBar);

	int birthDay, birthMonth;
	(std::cin >> birthDay >> birthMonth);

	int countSumChocolate = 0;
	for (auto i = 0; i <= (chocolateBar - birthMonth); i++ ) {
		auto iteratorBegin = vecChocolateBar.begin() + i;
		auto iteratorEnd = vecChocolateBar.begin() + i + birthMonth;
		int tempSum = std::accumulate(iteratorBegin, iteratorEnd, 0);
		
		if (tempSum == birthDay) {
			countSumChocolate++;
		}
	}

	std::cout << countSumChocolate << std::endl;
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

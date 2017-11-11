#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<int> strToVector(std::string, int);

int main() {

	int nGame;
	(std::cin >> nGame).get();

	std::string stringScore;
	std::getline(std::cin, stringScore);
	std::vector<int> vectorScore = strToVector(stringScore, nGame);

	// save the lowest and highest score 
	int lowestScore = vectorScore[0];
	int highestScore = vectorScore[0];

	// iterate the vector and count each increment and decrement
	int countBest = 0;
	int countWorst = 0;

	int oldLowestScore = lowestScore;
	int oldHighestScore = highestScore;
	for (auto score : vectorScore) {
		
		if (score > oldHighestScore) {
			countBest++;
			oldHighestScore = score;
		} else if (score < oldLowestScore) {
			countWorst++;
			oldLowestScore = score;
		}

	}

	std::cout << countBest << " " << countWorst << std::endl;

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

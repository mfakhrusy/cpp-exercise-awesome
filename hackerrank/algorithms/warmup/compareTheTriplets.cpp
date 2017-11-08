#include <iostream>
#include <array>
#include <string>
#include <sstream>

// make function for split string to array
std::array<int, 3> stringToArray( std::string );


int main() {

	// input A and B parameters as an array
	std::array<int, 3> aParam;
	std::array<int, 3> bParam;

	// input from user, with getline
	std::string inputAParam;
	std::string inputBParam;
	std::getline(std::cin, inputAParam);
	std::getline(std::cin, inputBParam);

    // split string into array
	aParam = stringToArray( inputAParam );
	bParam = stringToArray( inputBParam );

	// compare the integers
	int aPoint = 0;
	int bPoint = 0;

	for (auto i = 0; i < 3; i++) {
		if (aParam[i] == bParam[i]) {
			continue;
		}
		aParam[i] > bParam[i] ? aPoint++ : bPoint++;
	}

	std::cout << aPoint << " " << bPoint << std::endl;
 
	return 0;
}

// function definition
// stringToArray
std::array<int, 3> stringToArray( std::string inputParameters ) {
	std::array<int, 3> arrayResult;
	
	std::istringstream iss(inputParameters);
	int tempNumber = 0;

	int i = 0;
	while ( iss >> tempNumber ) {
		arrayResult[i] = tempNumber;
		i++;
	}

	return arrayResult;
};

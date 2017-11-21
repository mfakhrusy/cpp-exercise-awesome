#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "OilRent.hpp"

// default constructor without file input
OilRent::OilRent() {

}

// constructor definition
OilRent::OilRent( std::string oilFileName ) {
	// the constructor read from file (filename as parameter) and add that to
	// the variable	oilPotencyMap
	
	std::ifstream inputFileStream(oilFileName);

	if ( inputFileStream.is_open() ) {

		// first, add the size of oilMap fron firstLine
		std::string oilMapSizeString;
		std::getline(inputFileStream, oilMapSizeString);
		std::istringstream issOilMapSizeString(oilMapSizeString);
		issOilMapSizeString >> oilMapSize[0] >> oilMapSize[1];

		// resize the vector
		oilPotencyMap.resize(oilMapSize[0]);
		for (auto i = 0; i < oilPotencyMap.size(); i++) {
			oilPotencyMap[i].resize(oilMapSize[1]);
		}

		// read the oil potency map
		for (auto i = 0; i < oilMapSize[0]; i++) {
			std::string oilPotencyLine;
			std::getline(inputFileStream, oilPotencyLine);

			// use delimiter space for parse each string
			std::string delimiter = " ";
			size_t pos = 0;
			auto j = 0;
			std::string token;
				
			while (( pos = oilPotencyLine.find(delimiter)) != 
					std::string::npos ) {

				token = oilPotencyLine.substr(0, pos);
				oilPotencyMap[i][j] = std::stoi(token);
				oilPotencyLine.erase(0, pos + delimiter.length());			

				j++;
			}
			// for last instance
			oilPotencyMap[i][j] = std::stoi(oilPotencyLine);

		}
	} else {
		std::cout << "Input File Wrong\n";
	}
}

// print function
void OilRent::printOilMap() {

	for (auto i = 0; i < oilPotencyMap.size(); i++) {
		for (auto j = 0; j < oilPotencyMap[i].size(); j++) {

			std::cout << oilPotencyMap[i][j] << " ";
		
		}
		std::cout << std::endl;
	}

}

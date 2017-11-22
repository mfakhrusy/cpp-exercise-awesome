#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "OilRent.hpp"

// default constructor without file input
OilRent::OilRent() {

}

// constructor definition
OilRent::OilRent( std::string oilFileName, std::string rentFileName ) {
	// the constructor read from file (filename as parameter) and add that to
	// the variable	oilPotencyMap
	
	// PROCESS OIL POTENCY MAP
	std::ifstream inputFileStream;
	inputFileStream.open(oilFileName);

	if ( inputFileStream.is_open() ) {

		// first, add the size of oilMap fron firstLine
		std::string oilMapSizeString;
		std::getline(inputFileStream, oilMapSizeString);
		std::istringstream issOilMapSizeString(oilMapSizeString);
		issOilMapSizeString >> oilMapSize[0] >> oilMapSize[1];

		unsigned int oilMapRow = oilMapSize[0];
		unsigned int oilMapCol = oilMapSize[1];

		// resize the vector
		oilPotencyMap.resize(oilMapRow);
		for (size_t i = 0; i < oilPotencyMap.size(); i++) {
			oilPotencyMap[i].resize(oilMapCol);
		}

		// read the oil potency map
		for (size_t i = 0; i < oilMapRow; i++) {
			std::string oilPotencyLine;
			std::getline(inputFileStream, oilPotencyLine);

			// use delimiter space for parse each string
			std::string delimiter = " ";
			size_t pos = 0;
			size_t j = 0;
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
		std::cout << "Input filenameMap Wrong!" << std::endl;
	}

	inputFileStream.close();

	// PROCESS RENT INFORMATION
	inputFileStream.open(rentFileName);
	if ( inputFileStream.is_open() ) {
		
		std::string oilRentSizeString;
		std::getline(inputFileStream, oilRentSizeString);
		oilRentSize = std::stoi(oilRentSizeString);


	} else {
		std::cout << "Input filenameRent wrong!" << std::endl;
	}
}

// print function for map
void OilRent::printOilMap() {

	for (size_t i = 0; i < oilPotencyMap.size(); i++) {
		for (size_t j = 0; j < oilPotencyMap[i].size(); j++) {

			std::cout << oilPotencyMap[i][j] << " ";
		
		}
		std::cout << std::endl;
	}

}

// print function for rent info
void OilRent::printOilRent() {
	static const unsigned int INFOCOUNT = 4;
	std::array<std::string, INFOCOUNT> infoOilRent = {
		"Kembali ke Menu Utama",
		"Nama Perusahaan",
		"Sisa Jangka Waktu Penyewaan",
		"Tingkat Potensi Minyak"
	};

	std::cout << "-- Tampilkan Informasi Penyewaan --";
	std::cout << std::endl << std::endl;
	std::cout << "Terurut Berdasarkan:";
	std::cout << std::endl;

	for (size_t i = 1; i < INFOCOUNT; i++) {
		std::cout << i << ".\t" << infoOilRent[i] << std::endl;
	}
	std::cout << "0.\t" << infoOilRent[0] << std::endl;

	// input from user
	int userInputRent;
	std::cout << "Pilihan : ";
	std::cin >> userInputRent;

}

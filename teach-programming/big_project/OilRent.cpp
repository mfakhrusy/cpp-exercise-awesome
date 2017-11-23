#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "OilRent.hpp"
#define EMPTY NONE

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
		mapRentData.resize(oilMapRow);
		for (size_t i = 0; i < oilPotencyMap.size(); i++) {
			oilPotencyMap[i].resize(oilMapCol);
			mapRentData[i].resize(oilMapCol);
		}

		// initialize mapRentData.companyName and companyType with NONE
		for (size_t i = 0; i < mapRentData.size(); i++) {
			for (size_t j = 0; j < mapRentData[i].size(); j++) {
				mapRentData[i][j].companyName = "NONE";
				mapRentData[i][j].companyType = "NONE";
			}
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

		// read each company
		for (size_t i = 0; i < oilRentSize; i++) {
			std::string mapDataString;
			std::getline(inputFileStream, mapDataString);
			std::istringstream issRentData(mapDataString);

			unsigned int tempRow, tempCol, tempWeek;
			std::string tempCompanyName, tempCompanyType;
			issRentData >> tempRow >> tempCol >> tempCompanyName >> tempCompanyType >> tempWeek;

			mapRentData[tempRow][tempCol].mapRow = tempRow;
			mapRentData[tempRow][tempCol].mapCol = tempCol;
			mapRentData[tempRow][tempCol].companyName = tempCompanyName;
			mapRentData[tempRow][tempCol].companyType = tempCompanyType;
			mapRentData[tempRow][tempCol].week = tempWeek;

		}

	} else {
		std::cout << "Input filenameRent wrong!" << std::endl;
	}

	inputFileStream.close();
}

// print function for map
void OilRent::printOilMap() {

	unsigned int unrentedMap = 0;
	for (size_t i = 0; i < oilPotencyMap.size(); i++) {
		for (size_t j = 0; j < oilPotencyMap[i].size(); j++) {

			std::cout << oilPotencyMap[i][j] << "," << mapRentData[i][j].companyName << " ";
			
			if ( mapRentData[i][j].companyName == "NONE" ) {
				
				// increase unrented map if NONE is appear in company name
				unrentedMap += 1;
			}
		
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Jumlah area belum disewa : " << unrentedMap << std::endl << std::endl;

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

	bool EXITOPTION4 = false;

	while (!EXITOPTION4) {
		
		std::cout << "-- Tampilkan Informasi Penyewaan --";
		std::cout << std::endl << std::endl;
		std::cout << "Terurut Berdasarkan:";
		std::cout << std::endl;

		for (size_t i = 1; i < INFOCOUNT; i++) {
			std::cout << i << ".\t" << infoOilRent[i] << std::endl;
		}
		std::cout << "0.\t" << infoOilRent[0] << std::endl;

		// input from user
		unsigned int userInputRent;
		std::cout << "Pilihan : ";
		std::cin >> userInputRent;
		
		if ( userInputRent == 0) {

			EXITOPTION4 = true;

		} else if ( userInputRent == 1 ) {
			
			const unsigned int tempMapRow = oilMapSize[0];
			const unsigned int tempMapCol = oilMapSize[1];
			
			for (size_t i = 0; i < tempMapRow; i++) {
				for (size_t j = 0; j < tempMapCol; j++) {
					if ( mapRentData[i][j].companyName != "NONE" ) {

						std::cout << i << " " << j << " ";
						std::cout << mapRentData[i][j].companyName << " ";
						std::cout << mapRentData[i][j].companyType << " ";
						std::cout << mapRentData[i][j].week << " ";
						std::cout << oilPotencyMap[i][j] << std::endl;
						
					}
				}
			}
		
		} else if ( userInputRent == 2 ) {

		} else if ( userInputRent == 3 ) {

		} else {
			std::cout << "Input Wrong!" << std::endl;
		}

	}
}

// save function
void OilRent::saveOilInfo(std::string outputFileName) {

	std::ofstream outputFile(outputFileName);

	// save how many rent
	outputFile << oilRentSize << std::endl;

	// save everything
	const unsigned int tempMapRow = oilMapSize[0];
	const unsigned int tempMapCol = oilMapSize[1];

	for (size_t i = 0; i < tempMapRow; i++) {
		for (size_t j = 0; j < tempMapCol; j++) {
			if ( mapRentData[i][j].companyName != "NONE" ) {

				outputFile << i << " " << j << " ";
				outputFile << mapRentData[i][j].companyName << " ";
				outputFile << mapRentData[i][j].companyType << " ";
				outputFile << mapRentData[i][j].week << " ";
				outputFile << oilPotencyMap[i][j] << std::endl;

			}
		}
	}
}

// for add data to mapRentData
std::vector<std::vector<RentData>> OilRent::addRentData(std::vector<std::vector<RentData>> mapRentData) {

	std::cout << std::endl;
	std::cout << "-- Tambah Penyewaan --" << std::endl;
	
	// input from user
	std::string tempCompanyName, tempCompanyType;
	unsigned int tempWeek, tempRow, tempCol;
	
	std::cout << "> Masukkan nama perusahaan : ";
	std::cin >> tempCompanyName;

	std::cout << "> Masukkan jenis perusahaan : ";
	std::cin >> tempCompanyType;

	std::cout << "> Masukkan jangka waktu penyewaan : ";
	std::cin >> tempWeek;

	std::cout << "> Masukkan baris area : ";
	std::cin >> tempRow;

	std::cout << "> Masukkan kolom area : ";
	std::cin >> tempCol;

	// input to our mapRentData object
	// first, check if the col and row whether it exist already
	// if ( mapRentData[tempRow][tempCol].companyName != "NONE" ) {
	// 	std::cout << "DATA EXIST!!!" ;
	// } 

	return mapRentData;
}

// void OilRent::addRentData() {

//	mapRentData = addRentData(mapRentData);

//}

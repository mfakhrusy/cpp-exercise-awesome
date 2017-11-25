#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <array>

class OilRent {

	private:

		// struct
		struct RentData {
			unsigned int mapRow;
			unsigned int mapCol;
			std::string companyName;
		 	std::string companyType;
			unsigned int week;
		};

		std::vector<std::vector<RentData>> mapRentData;
		std::vector<std::vector<int>> oilPotencyMap;
		std::array<int, 2> oilMapSize;
		unsigned int oilRentSize;

		//misc function
		// the following function compute addition of rent data (private)
		std::vector<std::vector<OilRent::RentData>> addRentData(std::vector<std::vector<OilRent::RentData>>);

		// the following, do a deletion of data
		std::vector<std::vector<OilRent::RentData>> deleteRentData(std::vector<std::vector<OilRent::RentData>>);

		// alteration of oilPotencyMap
		std::vector<std::vector<int>> changeOilPotency(std::vector<std::vector<int>>);

	public:

		// default constructor
		OilRent();

		// constructor
		OilRent( std::string, std::string );

		// method
		void printOilMap();
		void printOilRent();
		void saveOilInfo(std::string);
		void addRentData();
		void deleteRentData();
		void changeOilPotency();

};

int main() {

	static const int MENUCOUNT = 10;
	std::array<std::string, MENUCOUNT> menuChoice = {"Exit", 
		"Load Data", 
		"Save Data", 
		"Tampilkan Peta", 
		"Tampilkan Informasi Penyewaan", 
		"Tambah Penyewaan", 
		"Hapus Penyewaan",
		"Ubah Tingkat Potensi Minyak", 
		"Cari Informasi Penyewaan", 
		"Majukan Waktu"
	};

	// bool EXIT will change to true if user want to quit program
	bool EXIT = false;

	std::cout << "----- PROGRAM SEWA LAHAN MINYAK -----";
	std::cout << std::endl << std::endl;

	// generate a dummy OilRent object for save the instance
	OilRent tempOil;

	//initialize class and file name
	while(!EXIT) {

		// print menu
		std::cout << "-- MENU --" << std::endl;
		for (size_t i = 1; i < MENUCOUNT; i++) {
			std::cout << i << ".\t" << menuChoice[i] << std::endl;
		}
		std::cout << "0.\t" << menuChoice[0] << std::endl;
		
		int menuInput = 0;
		std::cout << "Pilihan : ";
		std::cin >> menuInput;
		std::string mapFileName;
		std::string rentFileName;

		if ( menuInput == 0 ) {
		
			// case 0 -> exit, change EXIT into true and break the loop
			EXIT = true;

		} else if ( menuInput == 1) {
			// "Load Data", 

			// construct the OilRent class here
			std::cout << "\nMasukkan nama file peta: ";
			std::cin >> mapFileName;

			std::cout << "\nMasukkan nama file data sewa: ";
			std::cin >> rentFileName;

			// call constructor
			OilRent oil(mapFileName, rentFileName);
			
			// copy constructor to tempOil;
			tempOil = oil;
			
		} else if ( menuInput == 2 ) {

			// "Save Data", 
			std::string outputFileName;
			std::cout << "Nama File: ";
			std::cin >> outputFileName;

			tempOil.saveOilInfo(outputFileName);
		
		} else if ( menuInput == 3 ) {

			// "Tampilkan Peta", 
			tempOil.printOilMap();
		
		} else if ( menuInput == 4 ) {

			// "Tampilkan Informasi Penyewaan", 
			tempOil.printOilRent();
			
		} else if ( menuInput == 5 ) {

			// "Tambah Penyewaan", 
			tempOil.addRentData();

		} else if ( menuInput == 6 ) {

			// "Hapus Penyewaan",
			tempOil.deleteRentData();

		} else if ( menuInput == 7 ) {

			// "Ubah Tingkat Potensi Minyak", 
		} else if ( menuInput == 8 ) {

			// "Cari Informasi Penyewaan", 
		} else if ( menuInput == 9 ) {
			
			// "Majukan Waktu"
		} else {
			std::cout << "Input Wrong!" << std::endl;
		}
	}

	return 0;
}

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

// for add data to mapRentData
std::vector<std::vector<OilRent::RentData>> OilRent::addRentData(std::vector<std::vector<OilRent::RentData>> mapRentData) {

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
	if ( mapRentData[tempRow][tempCol].companyName != "NONE" ) {

		std::cout << "Penyewaan gagal! Area sudah disewa!" << std::endl << std::endl;

	} else {

		mapRentData[tempRow][tempCol].mapRow = tempRow;
		mapRentData[tempRow][tempCol].mapCol = tempCol;
		mapRentData[tempRow][tempCol].companyName = tempCompanyName;
		mapRentData[tempRow][tempCol].companyType = tempCompanyType;
		mapRentData[tempRow][tempCol].week = tempWeek;

		std::cout << "Penyewaan berhasil!" << std::endl << std::endl << std::endl;

	}

	return mapRentData;
}

// deleteRentData implementation
std::vector<std::vector<OilRent::RentData>> OilRent::deleteRentData(std::vector<std::vector<OilRent::RentData>> mapRentData) {
	
	std::cout << "-- Hapus Penyewaan --" << std::endl << std::endl;

	unsigned int tempRow, tempCol;
	std::cout << "Masukkan baris area : ";
	std::cin >> tempRow;

	std::cout << "Masukkan kolom area : ";
	std::cin >> tempCol;

	// delete according to tempRow and tempCol
	// first, check if the col and row whether it exist already
	if ( mapRentData[tempRow][tempCol].companyName != "NONE" ) {

		std::cout << "Penghapusan penyewaan gagal! Tidak ada penyewaan pada area ini" << std::endl << std::endl;

	} else {

		mapRentData[tempRow][tempCol].mapRow = 0;
		mapRentData[tempRow][tempCol].mapCol = 0;
		mapRentData[tempRow][tempCol].companyName = "NONE";
		mapRentData[tempRow][tempCol].companyType = "NONE";
		mapRentData[tempRow][tempCol].week = 0;

		std::cout << "Penyewaan berhasil!" << std::endl << std::endl << std::endl;

	}

	return mapRentData;
}

// changeOilPotency private implementation
std::vector<std::vector<int>> OilRent::changeOilPotency(std::vector<std::vector<int>> oilPotencyMap) {

	std::cout << "-- Ubah Tingkat Potensi Minyak --" << std::endl << std::endl;
	

	return oilPotencyMap;
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


// the public version of addRentData (this one get into main)
void OilRent::addRentData() {

	mapRentData = addRentData(mapRentData);

}

// delete data
void OilRent::deleteRentData() {

	mapRentData = deleteRentData(mapRentData);

}

// change oilPotencyMap
void OilRent::changeOilPotency() {

	oilPotencyMap = changeOilPotency(oilPotencyMap);
}

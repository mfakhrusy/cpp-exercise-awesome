#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
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

	// to check all file is opened succesfully
	// if it is there, counter should have a value of 2
	// one of each file
	int fileCounter = 0;

	if ( inputFileStream.is_open() ) {

		// add the counter
		fileCounter++;

		// first, add the size of oilMap fron firstLine
		std::string oilMapSizeString;
		std::getline(inputFileStream, oilMapSizeString);
		std::istringstream issOilMapSizeString(oilMapSizeString);
		issOilMapSizeString >> oilMapSize[0] >> oilMapSize[1];

		unsigned int oilMapRow = oilMapSize[0];
		unsigned int oilMapCol = oilMapSize[1];

		// resize the vector
		oilPotencyMap.resize(oilMapRow);
		oilPriceMap.resize(oilMapRow);
		mapRentData.resize(oilMapRow);

		for (size_t i = 0; i < oilPotencyMap.size(); i++) {
			oilPotencyMap[i].resize(oilMapCol);
			oilPriceMap[i].resize(oilMapCol);
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

		// compute oil price on each map cell
		for (size_t i = 0; i < oilMapRow; i++) {
			for (size_t j = 0; j < oilMapCol; j++) {
				oilPriceMap[i][j] = oilPotencyMap[i][j] * OIL_PRICE_PER_POTENCY;
			}
		}

	} else {
		std::cout << "Nama file potensi minyak tidak ditemukan!" << std::endl;
	}

	inputFileStream.close();

	// PROCESS RENT INFORMATION
	inputFileStream.open(rentFileName);
	if ( inputFileStream.is_open() ) {

		// add the counter
		fileCounter++;

		std::string oilRentSizeString;
		std::getline(inputFileStream, oilRentSizeString);
		oilRentSize = std::stoi(oilRentSizeString);

		// read each company
		for (size_t i = 0; i < oilRentSize; i++) {
			std::string mapDataString;
			std::getline(inputFileStream, mapDataString);
			std::istringstream issRentData(mapDataString);

			unsigned int tempRow, tempCol, tempYear;
			std::string tempCompanyName, tempCompanyType;
			issRentData >> tempRow >> tempCol >> tempCompanyName >> tempCompanyType >> tempYear;

			mapRentData[tempRow][tempCol].mapRow = tempRow;
			mapRentData[tempRow][tempCol].mapCol = tempCol;
			mapRentData[tempRow][tempCol].companyName = tempCompanyName;
			mapRentData[tempRow][tempCol].companyType = tempCompanyType;
			mapRentData[tempRow][tempCol].yearLeft = tempYear;

			//std::cout << mapRentData[tempRow][tempCol].companyName << " " << mapRentData[tempRow][tempCol].mapCol << std::endl;
		}

	} else {
		std::cout << "Nama file data sewa tidak ditemukan!" << std::endl;
	}

	inputFileStream.close();

	// confirm the user that every file is opened successfully
	if ( fileCounter == 2) {
		std::cout << "Kedua file berhasil dibuka!" << std::endl << std::endl;
	}
}

// for add data to mapRentData
std::vector<std::vector<OilRent::RentData>> OilRent::addRentData(std::vector<std::vector<OilRent::RentData>> mapRentData) {

	std::cout << std::endl;
	std::cout << "-- Tambah Penyewaan --" << std::endl;
	
	// input from user
	std::string tempCompanyName, tempCompanyType;
	unsigned int tempYear, tempRow, tempCol;
	
	std::cout << "> Masukkan nama perusahaan : ";
	std::cin >> tempCompanyName;

	std::cout << "> Masukkan jenis perusahaan : ";
	std::cin >> tempCompanyType;

	std::cout << "> Masukkan jangka waktu penyewaan : ";
	std::cin >> tempYear;

	std::cout << "> Masukkan baris area : ";
	std::cin >> tempRow;

	std::cout << "> Masukkan kolom area : ";
	std::cin >> tempCol;
	std::cout << std::endl;

	// input to our mapRentData object
	// first, check if the col and row whether it exist already
	if ( mapRentData[tempRow][tempCol].companyName != "NONE" ) {

		std::cout << "Penyewaan gagal! Area sudah disewa!";
		std::cout << std::endl << std::endl;

	} else {

		mapRentData[tempRow][tempCol].mapRow = tempRow;
		mapRentData[tempRow][tempCol].mapCol = tempCol;
		mapRentData[tempRow][tempCol].companyName = tempCompanyName;
		mapRentData[tempRow][tempCol].companyType = tempCompanyType;
		mapRentData[tempRow][tempCol].yearLeft = tempYear;

		std::cout << "Penyewaan berhasil!";
		std::cout << std::endl << std::endl;

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
	if ( mapRentData[tempRow][tempCol].companyName == "NONE" ) {

		std::cout << "Penghapusan penyewaan gagal! Tidak ada penyewaan pada area ini" << std::endl << std::endl;

	} else {

		mapRentData[tempRow][tempCol].mapRow = 0;
		mapRentData[tempRow][tempCol].mapCol = 0;
		mapRentData[tempRow][tempCol].companyName = "NONE";
		mapRentData[tempRow][tempCol].companyType = "NONE";
		mapRentData[tempRow][tempCol].yearLeft= 0;

		std::cout << "Penghapusan berhasil!" << std::endl << std::endl << std::endl;

	}

	return mapRentData;
}

// changeOilPotency private implementation
std::vector<std::vector<unsigned int>> OilRent::changeOilPotency(std::vector<std::vector<unsigned int>> oilPotencyMap) {

	std::cout << "-- Ubah Tingkat Potensi Minyak --" << std::endl << std::endl;
	
	// user input
	unsigned int tempRow, tempCol, tempOilPotency;

	std::cout << "> Masukkan baris area : ";
	std::cin >> tempRow;

	std::cout << "> Masukkan kolom area : ";
	std::cin >> tempCol;

	std::cout << "> Masukkan tingkat potensi minyak baru : ";
	std::cin >> tempOilPotency;

	// change oilPotencyMap
	oilPotencyMap[tempRow][tempCol] = tempOilPotency;

	return oilPotencyMap;
}

// printData
void OilRent::printData(unsigned int row, unsigned int col) {

	std::cout << mapRentData[row][col].mapRow << " ";
	std::cout << mapRentData[row][col].mapCol << " ";
	std::cout << mapRentData[row][col].companyName << " ";
	std::cout << mapRentData[row][col].companyType << " ";
	std::cout << mapRentData[row][col].yearLeft << " ";
	std::cout << oilPotencyMap[row][col] << std::endl;

}

// printDetailArea
void OilRent::printDetailArea(unsigned int counter, unsigned int row, unsigned int col) {

	std::cout << "Area " << counter;
	std::cout << std::endl;

	std::cout << "Posisi " << mapRentData[row][col].mapRow;
	std::cout << "-" << mapRentData[row][col].mapCol;
	std::cout << std::endl;

	std::cout << "Nama Perusahaan : " << mapRentData[row][col].companyName;
	std::cout << std::endl;

	std::cout << "Jenis Perusahaan : " << mapRentData[row][col].companyType;
	std::cout << std::endl;

	std::cout << "Sisa Jangka Waktu Penyewaan : " << mapRentData[row][col].yearLeft;
	std::cout << std::endl;
	
	std::cout << "Harga : ";
	if (mapRentData[row][col].companyType == "Swasta") {
		std::cout << oilPriceMap[row][col];
	} else { // negara
		std::cout << oilPriceMap[row][col] - oilPriceMap[row][col] * DISCOUNT_FACTOR;
	}
	std::cout << std::endl << std::endl;

}

// print function for map
void OilRent::printOilMap() {

	// check each column max company name size
	const unsigned int tempMapRow = oilMapSize[0];
	const unsigned int tempMapCol = oilMapSize[1];
	std::vector<unsigned int> maxNameSizeCol(tempMapCol);

	for (size_t j = 0; j < tempMapCol; j++) {
		for (size_t i = 0; i < tempMapRow; i++) {

			std::string tempString = mapRentData[i][j].companyName;

			if (tempString.size() > maxNameSizeCol[j]) {
				// tempSize = tempString.size();
				maxNameSizeCol[j] = tempString.size();
			}
		}
	}

	// save the value of unrented map
	// increase the variable if companyName == "NONE"
	// because it means no company currently owns it
	unsigned int unrentedMap = 0;
	
	std::cout << std::endl;
	for (size_t i = 0; i < tempMapRow; i++) {
		for (size_t j = 0; j < tempMapCol; j++) {

			// std::cout << std::left;
			std::cout << oilPotencyMap[i][j] << ",";
			std::cout << std::setw(maxNameSizeCol[j] + 1);
			std::cout << std::left << mapRentData[i][j].companyName;
			
			// increase unrented map if NONE is appear in company name
			if (mapRentData[i][j].companyName == "NONE") {
				
				unrentedMap++;

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

	bool EXIT_OPTION_4 = false;

	while (!EXIT_OPTION_4) {
		
		std::cout << std::endl;
		std::cout << "-- Tampilkan Informasi Penyewaan --";
		std::cout << std::endl << std::endl;
		std::cout << "Terurut Berdasarkan : ";
		std::cout << std::endl;

		for (size_t i = 1; i < INFOCOUNT; i++) {
			std::cout << i << ".\t" << infoOilRent[i] << std::endl;
		}
		std::cout << "0.\t" << infoOilRent[0] << std::endl;

		// input from user
		std::string userInputRent;
		std::cout << std::endl;
		std::cout << "> Pilihan : ";
		std::cin >> userInputRent;
		std::cout << std::endl;
		
		const unsigned int tempMapRow = oilMapSize[0];
		const unsigned int tempMapCol = oilMapSize[1];
		
		if (userInputRent == "0") {

			EXIT_OPTION_4 = true;

		} else if (userInputRent == "1") {
			
			std::vector<OilRent::RentData> tempData;
			
			for (size_t i = 0; i < tempMapRow; i++) {
				for (size_t j = 0; j < tempMapCol; j++) {
					if ( mapRentData[i][j].companyName != "NONE" ) {

						// add to tempData
						tempData.push_back(mapRentData[i][j]);
						
					}
				}
			}
		
			// sort tempData
			for (size_t i = 0; i < tempData.size() - 1; i++) {
				for (size_t j = 0; j < tempData.size() - 1; j++) {
					if (tempData[j].companyName > tempData[j + 1].companyName) {

						OilRent::RentData tempSort = tempData[j + 1];
						tempData[j + 1] = tempData[j];
						tempData[j] = tempSort;

					}
				}
			}


			// print sorted tempData
			for (auto data : tempData) {

				std::cout << data.mapRow << " ";
				std::cout << data.mapCol << " ";
				std::cout << data.companyName << " ";
				std::cout << data.companyType << " ";
				std::cout << data.yearLeft << " ";
				std::cout << oilPotencyMap[data.mapRow][data.mapCol] << std::endl;

			}

		} else if (userInputRent == "2") {

			std::vector<OilRent::RentData> tempData;
			
			for (size_t i = 0; i < tempMapRow; i++) {
				for (size_t j = 0; j < tempMapCol; j++) {
					if (mapRentData[i][j].companyName != "NONE") {

						// add to tempData
						tempData.push_back(mapRentData[i][j]);
						
					}
				}
			}
		
			// sort tempData
			for (size_t i = 0; i < tempData.size() - 1; i++) {
				for (size_t j = 0; j < tempData.size() - 1; j++) {
					if (tempData[j].yearLeft > tempData[j + 1].yearLeft) {

						OilRent::RentData tempSort = tempData[j + 1];
						tempData[j + 1] = tempData[j];
						tempData[j] = tempSort;

					}
				}
			}


			// print sorted tempData
			for (auto data : tempData) {

				std::cout << data.mapRow << " ";
				std::cout << data.mapCol << " ";
				std::cout << data.companyName << " ";
				std::cout << data.companyType << " ";
				std::cout << data.yearLeft << " ";
				std::cout << oilPotencyMap[data.mapRow][data.mapCol] << std::endl;

			}

		} else if (userInputRent == "3") {

			std::vector<OilRent::RentData> tempData;
			
			for (size_t i = 0; i < tempMapRow; i++) {
				for (size_t j = 0; j < tempMapCol; j++) {
					if ( mapRentData[i][j].companyName != "NONE" ) {

						// add to tempData
						tempData.push_back(mapRentData[i][j]);
						
					}
				}
			}
		
			// sort tempData
			for (size_t i = 0; i < tempData.size() - 1; i++) {
				for (size_t j = 0; j < tempData.size() - 1; j++) {

					// we need to extract the oilPotencyMap from each particular
					// tempData.mapRow and tempData.mapCol
					// and we need to sort that with bubble sort
					unsigned int row1 = tempData[j].mapRow;
					unsigned int col1 = tempData[j].mapCol;

					unsigned int row2 = tempData[j + 1].mapRow;
					unsigned int col2 = tempData[j + 1].mapCol;
					if (oilPotencyMap[row1][col1] > oilPotencyMap[row2][col2]) {

						OilRent::RentData tempSort = tempData[j + 1];
						tempData[j + 1] = tempData[j];
						tempData[j] = tempSort;

					}
				}
			}

			// print sorted tempData
			for (auto data : tempData) {

				std::cout << data.mapRow << " ";
				std::cout << data.mapCol << " ";
				std::cout << data.companyName << " ";
				std::cout << data.companyType << " ";
				std::cout << data.yearLeft << " ";
				std::cout << oilPotencyMap[data.mapRow][data.mapCol] << std::endl;

			}
		} else {
			std::cout << "Input salah!";
			std::cout << std::endl;
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

	if (outputFile.is_open()) {
		for (size_t i = 0; i < tempMapRow; i++) {
			for (size_t j = 0; j < tempMapCol; j++) {
				if ( mapRentData[i][j].companyName != "NONE" ) {

					outputFile << mapRentData[i][j].mapRow << " ";
					outputFile << mapRentData[i][j].mapCol << " ";
					outputFile << mapRentData[i][j].companyName << " ";
					outputFile << mapRentData[i][j].companyType << " ";
					outputFile << mapRentData[i][j].yearLeft<< " ";
					outputFile << oilPotencyMap[i][j] << std::endl;

				}
			}
		}

		std::cout << "Penyimpanan berhasil dengan nama file : " << outputFileName;
		std::cout << std::endl;
	} else {
		std::cout << std::endl;
		std::cout << "File tidak bisa disimpan!";
		std::cout << std::endl;
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

// findOilRent implementation
void OilRent::findOilRent() {

	static const unsigned int INFOCOUNT = 3;
	std::array<std::string, INFOCOUNT> infoOilRent = {
		"Kembali ke Menu Utama",
		"Nama Perusahaan",
		"Posisi Area"
	};

	bool EXIT_OPTION_8 = false;

	// define temp oil map size
	unsigned int oilMapRow = oilMapSize[0];
	unsigned int oilMapCol = oilMapSize[1];

	while (!EXIT_OPTION_8) {
		
		std::cout << "-- Cari Informasi Penyewaan --";
		std::cout << std::endl << std::endl;
		std::cout << "Berdasarkan:";
		std::cout << std::endl;

		for (size_t i = 1; i < INFOCOUNT; i++) {
			std::cout << i << ".\t" << infoOilRent[i] << std::endl;
		}
		std::cout << "0.\t" << infoOilRent[0] << std::endl;

		// input from user
		std::string userInputRent;
		std::cout << std::endl;
		std::cout << "> Pilihan : ";
		std::cin >> userInputRent;
		std::cout << std::endl;
		
		// find the vector where dwells the input of user
		
		unsigned int countArea = 0;
		if (userInputRent == "0") {

			EXIT_OPTION_8 = true;

		} else if (userInputRent == "1") {

			std::string inputCompanyName;
			std::cout << "Masukkan nama perusahaan : ";
			std::cin >> inputCompanyName;
			std::cout << std::endl;
		
			for (size_t i = 0; i < oilMapRow; i++) {
				for (size_t j = 0; j < oilMapCol; j++) {
					if ( mapRentData[i][j].companyName == inputCompanyName ) {

						// add countArea by 1
						countArea++;

						printData(i, j);
						std::cout << std::endl;

						printDetailArea(countArea, i, j);
						
					}
				}
			}

			if ( countArea == 0) {
				
				std::cout << "Nama perusahaan tidak ditemukan!";
				std::cout << std::endl << std::endl;
			
			}

		} else if (userInputRent == "2") {

			unsigned int inputRow, inputCol;
			std::cout << "Masukkan baris area : ";
			std::cin >> inputRow;

			std::cout << "Masukkan kolom area : ";
			std::cin >> inputCol;

			if (inputRow > oilMapRow || inputCol > oilMapCol) {
				std::cout << std::endl;
				std::cout << "Lahan tersebut tidak tersedia, silahkan ulangi kembali!";
				std::cout << std::endl;
			}

			for (size_t i = 0; i < oilMapRow; i++) {
				for (size_t j = 0; j < oilMapCol; j++) {
					if ( i == inputRow && j == inputCol && mapRentData[i][j].companyName != "NONE" ) {

						// add countArea by 1
						countArea++;

						printData(i, j);
						std::cout << std::endl;

						printDetailArea(countArea, i, j);
						
					}
				}
			}

			if ( countArea == 0) {
				
				std::cout << std::endl;
				std::cout << "Lahan masih kosong!";
				std::cout << std::endl << std::endl;
			
			}

		} else {

			std::cout << "Input salah!";
			std::cout << std::endl << std::endl;

		}

	}
}

// decrease time (year) of rent
void OilRent::increaseYear() {

	std::cout << "-- Majukan Waktu --";
	std::cout << std::endl << std::endl;

	unsigned int tempAddYear;
	std::cout << "Majukan waktu (dalam tahun) : ";
	std::cin >> tempAddYear;

	unsigned int oilMapRow = oilMapSize[0];
	unsigned int oilMapCol = oilMapSize[1];

	for (size_t i = 0; i < oilMapRow; i++) {
		for (size_t j = 0; j < oilMapCol; j++) {

			// if yearLeft is equal to zero then the land is unrented
			if ( mapRentData[i][j].yearLeft != 0) {

				// check if the difference of year is zero or less, then delete the rent info
				// if not, just decrease the yearLeft value of mapRentData
				// need to cast to int because unsigned int can't be negative
				int diff = static_cast<int>(mapRentData[i][j].yearLeft) - static_cast<int>(tempAddYear);
				if ( diff > 0 ) {
					mapRentData[i][j].yearLeft = static_cast<unsigned int>(diff);
				} else {

					// initialize value to 0 and "NONE"
					mapRentData[i][j].mapCol = 0;
					mapRentData[i][j].mapRow = 0;
					mapRentData[i][j].companyName = "NONE";
					mapRentData[i][j].companyType = "NONE";
					mapRentData[i][j].yearLeft = 0;

				}
			} 
		}
	}
}

#include <iostream>
#include <array>
#include <string>
#include "OilRent.hpp"

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

// recursive input function


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
		for (auto i = 1; i < MENUCOUNT; i++) {
			std::cout << i << "\t" << menuChoice[i] << std::endl;
		}
		std::cout << "0\t" << menuChoice[0] << std::endl;
		
		int menuInput = 0;
		std::cin >> menuInput;
		std::string filename;

		if ( menuInput == 0 ) {
		
			// case 0 -> exit, change EXIT into true and break the loop
			EXIT = true;

		} else if ( menuInput == 1) {

			// construct the OilRent class here
			std::cout << "\nMasukkan nama file: ";
			std::cin >> filename;

			// call constructor
			OilRent oil(filename);
			
			// copy constructor to tempOil;
			tempOil = oil;
			
		} else if ( menuInput == 2) {
		
		} else if ( menuInput == 3) {

			// print the data
			tempOil.printOilMap();
		
		} else {
			std::cout << "Input Wrong!" << std::endl;
		}
	}

	return 0;
}

// recursive input function


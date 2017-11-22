#include <string>
#include <vector>
#include <array>

class OilRent {

	public:

		// default constructor
		OilRent();
		// constructor
		OilRent( std::string, std::string );

		// method
		void printOilMap();
		void printOilRent();
	private:

		std::vector<std::vector<int>> oilPotencyMap;
		std::vector<std::vector<std::string>> oilMapRented;
		std::array<int, 2> oilMapSize;
		std::vector<std::vector<std::string>> companyOilMap;

		unsigned int oilRentSize;

};

#include <string>
#include <vector>
#include <array>

class OilRent {

	public:

		// default constructor
		OilRent();
		// constructor
		explicit OilRent( std::string );

		// method
		void printOilMap();

		std::vector<std::vector<int>> oilPotencyMap;
	private:

		std::array<int, 2> oilMapSize;
		std::vector<std::vector<std::string>> companyOilMap;
		

};

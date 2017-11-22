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

		// struct
		struct RentData {
			std::string companyName;
		 	std::string companyType;
			unsigned int week;
		};

		std::vector<std::vector<RentData>> mapRentData;

		std::vector<std::vector<int>> oilPotencyMap;
		std::array<int, 2> oilMapSize;
		unsigned int oilRentSize;

		//misc function
};

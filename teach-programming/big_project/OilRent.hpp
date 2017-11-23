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
		void saveOilInfo(std::string);
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
};

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

};

// Header file of HeartRates class
#include <string>

class HeartRates {
	private:
		std::string first_name;
		std::string last_name;
		unsigned int birth_day;
		unsigned int birth_month;
		unsigned int birth_year;

	public:
		HeartRates( std::string first_name,
				std::string last_name,
				unsigned int birth_day,
				unsigned int birth_month,
				unsigned int birth_year );

		// get functions
		std::string getFirstName() const;
		std::string getLastName() const;
		int getBirthDay() const;
		int getBirthMonth() const;
		int getBirthYear() const;
		int getAge() const;
		int getMaximumHeartRate() const;
		int getTargetHeartRate() const;

		// set functions
		void setFirstName( std::string );
		void setLastName( std::string );
		void setBirthDay( unsigned int );
		void setBirthMonth( unsigned int);
		void setBirthYear( unsigned int );

		// display info function
		void displayInfo() const;
};

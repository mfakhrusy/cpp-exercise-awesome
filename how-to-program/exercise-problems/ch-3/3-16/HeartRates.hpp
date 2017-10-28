// Header file of HeartRates class
#include <string>

class HeartRates {
	private:
		unsigned int CONST_MAX_HEART_RATE = 220;

		std::string first_name;
		std::string last_name;
		unsigned int birth_day;
		unsigned int birth_month;
		unsigned int birth_year;

		// just some functions for easiness
		unsigned int calc_day( unsigned int day,
			   unsigned int month,
			   unsigned int year);

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
		unsigned int getAge(unsigned int current_day,
				unsigned int current_month,
				unsigned int current_year);
		unsigned int getMaximumHeartRate(unsigned int age) const;
		unsigned int getTargetHeartRate(unsigned int maxHeartRate) const;

		// set functions
		void setFirstName( std::string );
		void setLastName( std::string );
		void setBirthDay( unsigned int );
		void setBirthMonth( unsigned int);
		void setBirthYear( unsigned int );

		// display info function
		void displayInfo();
};

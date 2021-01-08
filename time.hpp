//header file time.hpp to declare your class
#include <iostream>
using namespace std;
#ifndef TIMERANGE
#define TIMERANGE
class TimeRange {
public:
	
	TimeRange(); // default constructor
	bool isValid(int beginningHour, int beginningMinute, int endingHour, int endingMinute);
	//function prototypes of set functions for each variable read from user
	void setbeginHour(int beginningHour); 
	void setbeginMinute(int beginningMinute);
	void setendHour(int endingHour);
	void setendMinute(int endingMinute);
	
	void output(int beginningHour, int beginningMinute, int endingHour, int endingMinute);

	//function prototypes of get functions to return the value in each variable
	int getbeginHour();
	int getbeginMinute();
	int getendHour();
	int getendMinute();

private:
	int beginHour;
	int beginMinute;
	int endHour;
	int endMinute;


};

#endif // TIMERANGE


//time.cpp to implement  class
#include "time.hpp"
#include <iostream>

//header file time.hpp to declare your class

TimeRange::TimeRange() {
	// Default is the first available time slot in the day
	beginHour = 0;
	beginMinute = 0;
	endHour = 0;
	endMinute = 30;
}

bool TimeRange::isValid(int beginningHour, int beginningMinute, int endingHour, int endingMinute)
{
	
	if (beginningHour < 0 || beginningHour > 24|| endingHour<0||endingHour>24)
	{
		cout << "This time of day does not exist!\n";
		return false;
	}
	if (beginningMinute != 0 && beginningMinute != 30 )
	{
		cout << "Unfortunately, we only book appointments every half an hour, starting from 00:00 to 00:30 and onwards. \nPlease input a valid time.\n";
		return false;
	}
	if (endingMinute != 0 && endingMinute != 30)
	{
		cout << "Unfortunately, we only book appointments every half an hour, starting from 00:00 to 00:30 and onwards. \nPlease input a valid time.\n";
		return false;
	}
	if (beginningHour > endingHour)
	{
		cout << "Invalid entry. Your start time is after your end time! Please input a valid time.\n";
		return false;
	}
	if (beginningHour == endingHour && beginningMinute >= endingMinute)
	{
		cout << "Invalid entry. Your start time is after your end time, or you entered the same time twice! Please input a valid time.\n";
		return false;
	}
	else
	{
		
		return true;
	}
}

void TimeRange::output(int beginningHour, int beginningMinute, int endingHour, int endingMinute)
{
	if (isValid(beginningHour, beginningMinute, endingHour, endingMinute)==0)
	{
		cout << "The appointment you are trying to book is from ";
		cout << beginningHour << ":";
		if (beginningMinute != 30){
			cout<<"00";
		}
		else{
		cout<<beginMinute;
		}
		cout<< " to " << endingHour << ":";
		if (endingMinute != 30){
			cout<<"00";
		}
		else{
		cout<<beginMinute;
		}
		cout<<"\n";
		cout << "This is an invalid appointment.\n";
	}
	else
	{
		cout << beginningHour << ":";
		if (beginningMinute != 30){
			cout<<"00";
		}
		else{
		cout<<beginMinute;
		}
		cout<< " to " << endingHour << ":";
		if (endingMinute != 30){
			cout<<"00";
		}
		else{
		cout<<beginMinute;
		}
		cout<<"\n";
		cout << "This is a valid appointment.\n";

	}
}

// function definitions of set and get functions


void TimeRange::setbeginHour(int beginningHour)
{ beginHour = beginningHour; }
void TimeRange::setbeginMinute(int beginningMinute) 
{beginMinute = beginningMinute;}
void TimeRange::setendHour(int endingHour)
{endHour = endingHour;}
void TimeRange::setendMinute(int endingMinute) 
{ endMinute = endingMinute; }

int TimeRange::getbeginHour() { return beginHour; }
int TimeRange::getbeginMinute() { return beginMinute; }
int TimeRange::getendHour() { return endHour; }
int TimeRange::getendMinute() { return endMinute; }


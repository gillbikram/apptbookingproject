#include "calendar.hpp"
#include "date.hpp"
#include "time.hpp"
#include <iostream>
using namespace std;

calendar::calendar(){
    cal_month = 9; //fall semester starts from Sep
    cal_day = 1; //first day of class starts on 12th
    cal_year = 2020;
}

void calendar::setMonth(int input_month){//set functions
    cal_month = input_month;
}
void calendar::setday(int input_day){
    cal_day = input_day;
}
void calendar::setyear(int input_year){
    cal_year = input_year;
}
int calendar::getMonth(){return cal_month;} //get functions
int calendar::getday(){return cal_day;}
int calendar::getyear(){return cal_year;}

int calendar::dayNumber(int input_day, int input_month, int input_year){
static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 
					4, 6, 2, 4 }; 
	input_year -= input_month < 3; 
	return ( input_year + input_year/4 - input_year/100 + 
			input_year/400 + t[input_month-1] + input_day) % 7; 
 }

string calendar::getMonthName (int input_month){
    string months[] = {"January", "February", "March", 
					"April", "May", "June", 
					"July", "August", "September", 
					"October", "November", "December"
					}; 

	return (months[input_month]); 
}

int calendar::numberOfDays (int input_month){
	// September 
	if (input_month == 8) 
		return (30); 

	// October 
	if (input_month == 9) 
		return (31); 

	// November 
	if (input_month == 10) 
		return (30); 

	// December 
	if (input_month == 11) 
		return (31); 
}

void calendar::printcalendar(int input_year){
    printf ("		 Calendar - %d\n\n", input_year); 
	int days; 
	int current = dayNumber (1, 9, 2020); 
	for (int i = 8; i < 12; i++) 
	{ 
		days = numberOfDays (i); 
		printf("\n ------------%s-------------\n", 
			getMonthName (i).c_str()); 
		printf("   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n"); 
		int k; 
		cout<<"   ";
		for (k = 0; k < current; k++)
			printf("    ");
		for (int j = 1; j <= days; j++) 
		{ int rst = j                                                     
		+ ((153 * ((i+1) + 12 * ((14 - (i+1)) / 12) - 3) + 2) / 5) 
		+ (365 * (2020 + 4800 - ((14 - (i+1)) / 12)))
		+ ((2020 + 4800 - ((14 - (i+1)) / 12)) / 4)
		- ((2020 + 4800 - ((14 - (i+1)) / 12)) / 100)
		+ ((2020 + 4800 - ((14 - (i+1)) / 12)) / 400)
		- 32045;
		int result = (rst+1)%7;

		if (i == 8 && j <= 7 || result == 0 || result ==6 ||i == 9 && j == 12 ||i == 10 && j == 11 ){
        cout<<"   X ";      }
      else
      printf("%5d", j); 
			if (++k > 6) 
			{ 
				k = 0; 
				printf("\n"); 
			} 
		} 
		if (k) 
			printf("\n"); 
		current = k; 
	} 
	return; 
}

const string slot[48] ={//timeslot print
 "00:00 - 00:30","00:30 - 01:00","01:00 - 01:30","01:30 - 02:00","02:00 - 02:30"
,"02:30 - 03:00","03:00 - 03:30","03:30 - 04:00","04:00 - 04:30","04:30 - 05:00"
,"05:00 - 05:30","05:30 - 06:00","06:00 - 06:30","06:30 - 07:00","07:00 - 07:30"
,"07:30 - 08:00","08:00 - 08:30","08:30 - 09:00","09:00 - 09:30","09:30 - 10:00"
,"10:00 - 10:30","10:30 - 11:00","11:00 - 11:30","11:30 - 12:00","12:00 - 12:30"
,"12:30 - 13:00","13:00 - 13:30","13:30 - 14:00","14:00 - 14:30","14:30 - 15:00"
,"15:00 - 15:30","15:30 - 16:00","16:00 - 16:30","16:30 - 17:00","17:00 - 17:30"
,"17:30 - 18:00","18:00 - 18:30","18:30 - 19:00","19:00 - 19:30","19:30 - 20:00"
,"20:00 - 20:30","20:30 - 21:00","21:00 - 21:30","21:30 - 22:00","22:00 - 22:30"
,"22:30 - 23:00","23:00 - 23:30","23:30 - 24:00"};



bool calendar::book(Date date, TimeRange time){//test
	date.printFreeTimeSlots(date.getMonth(), date.getDate());
	int start_index = 0;
    int end_index = 0;
    if (date.getStartTime_min() != 30){//calculation for the slot index number
        start_index = (date.getStartTime_min() * 2);
    }
    else if (date.getStartTime_min() == 30){
        start_index = (date.getStartTime_min() * 2) + 1;
    }
    if (date.getEndTime_min() == 30){
        end_index = (date.getEndTime_min() * 2) + 1;
    }
    else if (date.getEndTime_min() != 30){
        end_index = date.getEndTime_min() * 2;
    }
    int print_index = 0;

	if(date.isValid(date.getMonth(), date.getDate()) == 0){
		cout<<"Appointment cannot be booked! Wrong month/date is given!\n";
		return false;
	}
	else if (time.isValid(time.getbeginHour(),time.getbeginMinute(),time.getendHour(),time.getendMinute() == 0)){
		cout<<"Appointment cannot be booked! Wrong time is given!\n";
		return false;
	}
	else if (date.appointed[print_index] = true){
		cout<<"Your desired appointment time slot is taken, please choice a different day or time slot!\n";
		return false;
	}
	else cout<<"Appointment has been successfully booked!\n";
    for (print_index = start_index; print_index < end_index; print_index++){
        cout<<slot[print_index]<<"\n";
		date.appointed[print_index] = true;
    }
	cout << "This is the newly updated calendar: \n";
	date.printFreeTimeSlots(date.getMonth(), date.getDate());
	return true;
}

bool calendar::query(Date date, TimeRange time){//not working yet
int month = date.getMonth();
	int day = date.getDate();
	int start_hr = date.getStartTime_hr();
	int start_min = date.getStartTime_min();
	int end_hr = date.getEndTime_hr();
	int end_min = date.getEndTime_min();
	int start_index = 0;
    int end_index = 0;
	Date dateObject;
    if (start_min != 30){//calculation for the slot index number
        start_index = (start_hr * 2);
    }
    else if (start_min == 30){
        start_index = (start_hr * 2) + 1;
    }
    if (start_min == 30){
        end_index = (start_hr * 2) + 1;
    }
    else if (end_min != 30){
        end_index = end_hr * 2;
    }
    int print_index = 0;
    int counter  = 0;
    for (print_index = start_index; print_index < end_index; print_index++){
       if( dateObject.appointed[print_index] != 0)
	   {  
	   	break;
	   	
	   	
	   for (counter = print_index; counter<end_index; counter++){
		if (dateObject.appointed[counter]==0)
	   	break;
	   	return false;
	   	}
	   	// find array element that is not 0, then save it as an integer to begin next search that stops when array is 0 again.
	   }
	   
	
	   }
	}


bool calendar::Delete(Date date, TimeRange time){
	int month = date.getMonth();
	int day = date.getDate();
	int start_hr = date.getStartTime_hr();
	int start_min = date.getStartTime_min();
	int end_hr = date.getEndTime_hr();
	int end_min = date.getEndTime_min();
	int start_index = 0;
    int end_index = 0;
    if (date.getStartTime_min() != 30){//calculation for the slot index number
        start_index = (date.getStartTime_min() * 2);
    }
    else if (date.getStartTime_min() == 30){
        start_index = (date.getStartTime_min() * 2) + 1;
    }
    if (date.getEndTime_min() == 30){
        end_index = (date.getEndTime_min() * 2) + 1;
    }
    else if (date.getEndTime_min() != 30){
        end_index = date.getEndTime_min() * 2;
    }
    int print_index = 0;
    for (print_index = start_index; print_index < end_index; print_index++){
        if(date.appointed[print_index] = true){
			cout<<"Something is Wrong! Failed deleting\n";
			return false;
		}
    }
	cout<<"Appointment deleted!\n";
	return true;

}

void calendar::DeleteApp(Date date, TimeRange time){
	int month = date.getMonth();
	int day = date.getDate();
	int start_hr = date.getStartTime_hr();
	int start_min = date.getStartTime_min();
	int end_hr = date.getEndTime_hr();
	int end_min = date.getEndTime_min();
	int start_index = 0;
    int end_index = 0;
    if (date.getStartTime_min() != 30){//calculation for the slot index number
        start_index = (date.getStartTime_min() * 2);
    }
    else if (date.getStartTime_min() == 30){
        start_index = (date.getStartTime_min() * 2) + 1;
    }
    if (date.getEndTime_min() == 30){
        end_index = (date.getEndTime_min() * 2) + 1;
    }
    else if (date.getEndTime_min() != 30){
        end_index = date.getEndTime_min() * 2;
    }
    int print_index = 0;
	cout<<"appointment information recorded!\n";
    for (print_index = start_index; print_index < end_index; print_index++){
        cout<<slot[print_index]<<"\n";
		date.appointed[print_index] = false;
    }
	cout<<"Deleting...\n";
}


void calendar::printFreeTimeSlots_days(Date date, TimeRange time){
    int year = 2020;
	printcalendar(year);

}



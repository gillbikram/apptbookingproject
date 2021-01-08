//date.cpp to implement your class
#include "date.hpp"
#include <iostream>
using namespace std;

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

Date::Date(){
    month = 9; //fall semester starts from Sep
    day = 12; //first day of class starts on 12th
}
void Date::setMonth(int input_month){//set functions
    month = input_month;
}
void Date::setDate(int input_date){
    day = input_date;
}
void Date::setStartTime_hr(int time_start_hr){
    start_hr = time_start_hr;
}
void Date::setStartTime_min(int time_start_min){
    start_min = time_start_min;
}
void Date::setEndTime_hr(int time_end_hr){
    end_hr = time_end_hr;
}
void Date::setEndTime_min(int time_end_min){
    end_mins = time_end_min;
}

int Date::getMonth(){return month;} //get functions
int Date::getDate(){return day;}
int Date::getStartTime_hr(){return start_hr;}
int Date::getStartTime_min(){return start_min;}
int Date::getEndTime_hr(){return end_hr;}
int Date::getEndTime_min(){return end_mins;}

bool Date::isHoliday (int input_month, int input_date){
    int choice_month;
    int choice_date;
    choice_month = input_month;
    choice_date = input_date;
    if (choice_month == 10 && choice_date == 12){//both of these are holidays
        return true;
    }
    else if (choice_month == 11 && choice_date == 11){
        return true;
    }
    else
    {
        return false;//not a holiday
    }
}


int Date::GetWeekday(int input_month, int input_date){
    //formula for finding the date of the week
    // 0 - sunday to 6 saturday
    int rst =                                                     
		input_date                                                      
		+ ((153 * (input_month + 12 * ((14 - input_month) / 12) - 3) + 2) / 5) 
		+ (365 * (2020 + 4800 - ((14 - input_month) / 12)))
		+ ((2020 + 4800 - ((14 - input_month) / 12)) / 4)
		- ((2020 + 4800 - ((14 - input_month) / 12)) / 100)
		+ ((2020 + 4800 - ((14 - input_month) / 12)) / 400)
		- 32045;
	return (rst+1)%7;
}

bool Date::isWeekend(int input_month, int input_date){
    int day_week = GetWeekday(input_month,input_date);// 0 - sunday to 6 saturday
    if (day_week == 0 || day_week == 6){
        return true;//yes weekend
    }
    else
    {
        return false;//not weekend
    }
}

bool Date::isValid(int input_month, int input_date){
    if (isWeekend(input_month,input_date) == 1){
    cout<<"Please pick a different day, we are unavailable on weekends. \n";
        return false;
    }
    if (isHoliday(input_month,input_date) == 1){
    cout<<"Please pick a different day, we are unavailable on holidays.\n";
        return false;
    }
    if (input_month < 9 || input_month > 12){
    cout<<"Please enter a valid month, only dates within fall semester can be booked\n";
        return false;
    }
    if (input_month == 9 && input_date > 30){
    cout<<"Only 30 days in this month!\n";
        return false;
    }
    if (input_month == 11 && input_date > 30){
    cout<<"Only 30 days in this month!\n";
        return false; 
    }
    if (input_month == 10 && input_date > 31){
    cout<<"Only 31 days in this month!\n";
        return false;
    }
    if (input_month == 12 && input_date > 31){
    cout<<"Only 31 days in this month!\n";
        return false;   
    }
    if (input_month == 9 && input_date < 11){
    cout<<"School opens on Sep 11th!\n";
        return false;
    }
    if (input_date == 0){
    cout<<"Invalid number!\n";
        return false;
    }//all invalid
    else
    {
    cout<<"Date recorded successfully\n";
        return true;//yes its valid
    }
}

void Date::output(int input_month, int input_date){
    cout <<"Information about your appointment booking process\n";
    if (isValid(input_month,input_date) == 0){
        cout<<"Failed to process the appointment, please double check your appointment date\n";
        cout<<"The appointment you are attempted to book is:\n";
        if (input_month == 9){
            cout<<"September ";
        }
        else if(input_month == 10){
            cout<<"October ";
        }
        else if(input_month == 11){
            cout<<"November ";
        }
        else if(input_month == 12){
            cout<<"December ";
        }
        cout<<input_date<<"\n";
        if (isWeekend(input_month, input_date) == 1){
            cout<<"It's a weekend, please select a different date.\n";
        }
        if (isHoliday(input_month, input_date) == 1){
            cout<<"It's a holiday, please select a different date.\n";
        }
    }
    else
    {
        cout<<"Your appointment is booked at ";
        if (input_month == 9){
            cout<<"September ";
        }
        else if(input_month == 10){
            cout<<"October ";
        }
        else if(input_month == 11){
            cout<<"November ";
        }
        else if(input_month == 12){
            cout<<"December ";
        }
        cout<<input_date<<"\n";
        cout<<"It is a regular workday\n";
    }
}
void Date::printAppointedTimeSlots (int input_month, int input_date, int time_start_hr, int time_start_min, int time_end_hr, int time_end_min){
    cout<<"Appointed time slot on ";
    if (input_month == 9){
            cout<<"September ";
        }
        else if(input_month == 10){
            cout<<"October ";
        }
        else if(input_month == 11){
            cout<<"November ";
        }
        else if(input_month == 12){
            cout<<"December ";
        }
    cout << input_date<<" is:\n";
    int start_index = 0;
    int end_index = 0;
    if (time_start_min != 30){//calculation for the slot index number
        start_index = (time_start_hr * 2);
    }
    else if (time_start_min == 30){
        start_index = (time_start_hr * 2) + 1;
    }
    if (time_end_min == 30){
        end_index = (time_end_hr * 2) + 1;
    }
    else if (time_end_min != 30){
        end_index = time_end_hr * 2;
    }
    int print_index = 0;
    for (print_index = start_index; print_index < end_index; print_index++){
        cout<<slot[print_index]<<"\n";
        appointed[print_index] = true;
    }
    cout<<"-----------------------------------\n\n";
}

void Date::printFreeTimeSlots (int input_month, int input_date){
    cout<<"Free time slot on ";
    if (input_month == 9){
            cout<<"September ";
        }
        else if(input_month == 10){
            cout<<"October ";
        }
        else if(input_month == 11){
            cout<<"November ";
        }
        else if(input_month == 12){
            cout<<"December ";
        }
        cout << input_date<<" is:\n";
        for (int i = 1;i < 48; i++ ){//print everything when the appointed array is false
            if (appointed[i] == false){
                cout<<slot[i]<<"\n";
            }
        }
        cout<<"-----------------------------------\n\n";
}
bool equal(Date data1, Date data2){
    return (data1.month == data2.month && data1.day == data2.day);
}

void Date::errorprinting(int input_month, int input_date){//printing the error messages
    if (isValid(input_month,input_date) == 0){
        cout<<"Failed to process the appointment, please double check your appointment date\n";
    }
    if (isWeekend(input_month,input_date) == 1){
    cout<<"Please pick a different day, we are unavailable on weekends.\n";
    }
    if (isHoliday(input_month,input_date) == 1){
    cout<<"Please pick a different day, we are unavailable on holidays.\n";
    }
    if (input_month < 9 || input_month > 12){
    cout<<"Please enter a valid month, only dates within fall semester can be booked.\n";
    }
    if (input_month == 9 && input_date > 30){
    cout<<"Only 30 days in this month!\n";
    }
    if (input_month == 11 && input_date > 30){
    cout<<"Only 30 days in this month!\n";
    }
    if (input_month == 10 && input_date > 31){
    cout<<"Only 31 days in this month!\n";
    }
    if (input_month == 12 && input_date > 31){
    cout<<"Only 31 days in this month!\n";
    }
    if (input_date == 0){
    cout<<"Invalid number!\n";
    }
    if (input_month == 9 && input_date < 11){
    cout<<"School opens on Sep 11th!\n";
    }
}

void Date::printAppointedTimeSlots_clear (int input_month, int input_date){
    cout<<"Appointed time slot on ";
    if (input_month == 9){
            cout<<"September ";
        }
        else if(input_month == 10){
            cout<<"October ";
        }
        else if(input_month == 11){
            cout<<"November ";
        }
        else if(input_month == 12){
            cout<<"December ";
        }
        cout << input_date<<" is:\n";
        for (int i = 1;i < 48; i++ ){//print everything when the appointed array is false
            if (appointed[i] == true){
                cout<<slot[i]<<"\n";
            }
        }
        cout<<"-----------------------------------\n\n";
}

void Date::delelteappointment (int input_month, int input_date, int time_start_hr, int time_start_min, int time_end_hr, int time_end_min){
    cout<<"Deleting... ";
    if (input_month == 9){
            cout<<"September ";
        }
        else if(input_month == 10){
            cout<<"October ";
        }
        else if(input_month == 11){
            cout<<"November ";
        }
        else if(input_month == 12){
            cout<<"December ";
        }
    cout << input_date<<":\n";
    int start_index = 0;
    int end_index = 0;
    if (time_start_min != 30){//calculation for the slot index number
        start_index = (time_start_hr * 2);
    }
    else if (time_start_min == 30){
        start_index = (time_start_hr * 2) + 1;
    }
    if (time_end_min == 30){
        end_index = (time_end_hr * 2) + 1;
    }
    else if (time_end_min != 30){
        end_index = time_end_hr * 2;
    }
    int print_index = 0;
    for (print_index = start_index; print_index < end_index; print_index++){
        cout<<slot[print_index]<<"\n";
        appointed[print_index] = false;
    }
    cout <<"deleting.....";
    cout<<"-----------------------------------\n\n";
}
#include <iostream>
#include "date.hpp"
#include "time.hpp"
using namespace std;

class calendar{
    // this was private lol was such a headache --> calendar();
    public:
    calendar();
    bool book(Date date, TimeRange time);
    bool query(Date date, TimeRange time);//check if its booked/free
    //void queryApp(Date date, TimeRange time);//the function that actually gives out the output 
    bool Delete(Date date, TimeRange time);//check if its deleted
    void DeleteApp(Date date, TimeRange time);//function that actually delete appointment
    void printFreeTimeSlots_days(Date date, TimeRange time);
    //print all free days and timeslots in the calendar that can be booked
    void printFreeTimeSolts_days(Date date, TimeRange time);//print all free days and timeslots in the calendar that can be booked
    void printcalendar(int input_year);
    int dayNumber(int input_day, int input_month, int input_year);
    string getMonthName (int input_month);
    int numberOfDays (int input_month);

    void setMonth (int);
    void setday (int); 
    void setyear(int);
    int getMonth ();
    int getday ();
    int getyear();

    private:
    Date availableDates[91]; 
    Date date;
    TimeRange time;
    int cal_month;
    int cal_day;
    int cal_year;
};
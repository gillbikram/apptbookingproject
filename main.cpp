//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include "time.hpp"
#include "date.hpp"
#include "calendar.hpp"

int getthedateindex(int selected_month, int selected_date){
  int month = selected_month;
  int date = selected_date;
  int date_index = 0;
  if (month == 9){
   date_index = date - 1;
  }
  else if(month == 10){
    date_index = 29 + date;
  }
  else if(month == 11){
    date_index = 60 + date;
  }
  else if (month == 12){
    date_index = 90 + date;
  }
  return date_index;
}

int main(){
  calendar calendarobject;
  Date User_data1;
  Date bookedAppts;
  TimeRange user_input;
  Date user_data[121];
  TimeRange user_time_data[121];
  //sep 1st is [0], oct 1st = [30], nov 1st= [61], dec 1st = [91]
  //sep 30st = [29], otc 31st = [60], nov 30th = [90], dec 30th = [121]
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
  int user_month, user_date = 0;
  int user_start_hr =0;
  int user_start_min =0;
  int user_end_hr =0;
  int user_end_min =0;
  int primaryInput;
  int rpt;

  cout<<"Welcome to the appointment system\n";
do{
  cout<<"Press 1 to view booked appointments \n";//working fine
  cout<<"Press 2 to view available appointment time slots that have not been booked \n";//working fine
  cout<<"Press 3 to book new appointments\n";//working fine
  cout<<"Press 4 to check the status of an an appointment time slot\n";//working fine!! finally
  cout<<"Press 5 to delete a booked appointment time\n";//working fine
  cout<<"Press 6 to see the whole available calendar\n";//working fine
  cout<<"We will not be open on weekend or the holidays, please be aware of this.\n";
  cin >> primaryInput;
  
  int index = getthedateindex(user_month, user_date);
 
switch (primaryInput){

 case 1:
 int case1_month, case1_day, case1_start_hr, case1_start_min, case1_end_hr,case1_end_min;
 cout <<"Hi, which day of the month do you want to check?\nEnter month then day\n";
 cin >> case1_month;
 cin >> case1_day;
 index = getthedateindex(case1_month, case1_day);
 user_data[index].setMonth(case1_month);
 user_data[index].getMonth();
  user_data[index].setDate(case1_day);
  user_data[index].getDate();
 
 user_data[index].printAppointedTimeSlots_clear(case1_month,case1_day);
 
 break;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
 case 2: 
 // display all AVAILABLE appointments
  int case2_month, case2_day;
  cout <<"Hi, which day of the month do you want to check?\nEnter month then day\n";
  cin >> case2_month;
  cin >> case2_day;
  index = getthedateindex(case2_month, case2_day);
  
  user_data[index].setMonth(case2_month);
  user_data[index].getMonth();
  user_data[index].setDate(case2_day);
  user_data[index].getDate();
  user_data[index].printFreeTimeSlots(case2_month,case2_day);
 
 break;
////////////////////////////////////////////////////////////////////////
 case 3: //to book an appointment
  
  char user_choice_date;//loop for keep asking month if user enters invalid number
  while (1)
  {
  cout<<"Please enter the of month you would like to book as a number (January = 1, December = 12): \n";
  cout<<"Be advised we are only open on weekdays between September 8,2020 and December 20,2020.  We are closed on weekends, Thanksgiving, and Remembrance Day.\n";
  cin >> user_month;
  cout<<"Please enter the date would you like to view/book: \n";
  cin >> user_date;
  index = getthedateindex(user_month, user_date);
  
  user_data[index].setMonth(user_month);
  user_data[index].getMonth();
  user_data[index].setDate(user_date);
  user_data[index].getDate();

  if(user_data[index].isValid(user_month,user_date) == 1){
    break;
  }
  else
  {
    cout<<"Please ensure your information is correct!\n";
    cout<<"------------------------------\n";
  }
}
  do
  {
      cout << "Please enter the start hour of your desired appointment: ";
      cin >> user_start_hr;
      cout << "Please enter the starting minute of your desired appointment \nBe advised we only offer appointments in increments of half an hour: ";
      cin >> user_start_min;
      cout << "Please enter the hour you would like your appointment to end: ";
      cin >> user_end_hr;
      cout << "Please enter the minute you would like your appointment to end (must be an increment of half an hour): ";
      cin >> user_end_min;
  } while (user_input.isValid(user_start_hr, user_start_min, user_end_hr, user_end_min) == 0);//loop for keep asking the time if user enters invalid numbers

  user_data[index].setMonth(user_month);
  user_data[index].getMonth();
  user_data[index].setDate(user_date);
  user_data[index].getDate();
  user_data[index].setStartTime_hr(user_start_hr);
  user_data[index].getStartTime_hr();
  user_data[index].setStartTime_min(user_start_min);
  user_data[index].getStartTime_min();
  user_data[index].setEndTime_hr(user_end_hr);
  user_data[index].getEndTime_hr();
  user_data[index].setEndTime_min(user_end_min);
  user_data[index].getEndTime_min();
  user_input.setbeginHour(user_start_hr);
	user_input.getbeginHour();
	user_input.setbeginMinute(user_start_min);
	user_input.getbeginMinute();
	user_input.setendHour(user_end_hr);
	user_input.getendHour();
	user_input.setendMinute(user_end_min);
	user_input.getendMinute();

  user_data[index].printAppointedTimeSlots(user_month,user_date,user_start_hr,user_start_min,user_end_hr,user_end_min);
  user_data[index].printFreeTimeSlots(user_month,user_date);
  
  break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  case 4://check the status of an an appointment time slot
  
  while (1)
  {
  cout<<"Please enter the of month you would like to view as a number (January = 1, December = 12): \n";
  cout<<"Be advised we are only open on weekdays between September 8,2020 and December 20,2020.  We are closed on weekends, Thanksgiving, and Remembrance Day.\n";
  cin >> user_month;
  cout<<"Please enter the date would you like to view: \n";
  cin >> user_date;
  index = getthedateindex(user_month, user_date);
  user_data[index].setMonth(user_month);
  user_data[index].getMonth();
  user_data[index].setDate(user_date);
  user_data[index].getDate();
  if(user_data[index].isValid(user_month,user_date) == 1){
    break;
  }
  else
  {
    cout<<"Please ensure your information is correct!\n";
    cout<<"------------------------------\n";
  }
}
  do
  {
      cout << "Please enter the start hour of the appointment: ";
      cin >> user_start_hr;
      cout << "Please enter the starting minute of the appointment(increment of half an hour):" ;
      cin >> user_start_min;
      cout << "Please enter the ending hour of the appointment ";
      cin >> user_end_hr;
      cout << "Please enter the ending minute of the appointment (increment of half an hour): ";
      cin >> user_end_min;
  } while (user_input.isValid(user_start_hr, user_start_min, user_end_hr, user_end_min) == 0);//loop for keep asking the time if user enters invalid numbers
  
  // implement query function here, similar to time slots function but no printing, bool return value
   if(calendarobject.query(user_data[index], user_input)==false){
    cout  << "The entered appointment time is available!\n";

   }
   else {
     cout << "The entered appointment time is unavailable.\n";
   }
   
  //Check status of appointment time slot
  break;
/////////////////////////////////////////////////////////////////////////////////////////////////////////
  case 5://delete the selected appointed time slot in a day
 while (1)
  {
  cout<<"Please enter the of month you would like to delete as a number (January = 1, December = 12): \n";
  cout<<"Be advised we are only open on weekdays between September 8,2020 and December 20,2020.  We are closed on weekends, Thanksgiving, and Remembrance Day.\n";
  cin >> user_month;

  index = getthedateindex(user_month, user_date);
  
  user_data[index].setMonth(user_month);
  user_data[index].getMonth();
  user_data[index].setDate(user_date);
  user_data[index].getDate();
  user_data[index].setStartTime_hr(user_start_hr);
  user_data[index].getStartTime_hr();
  user_data[index].setStartTime_min(user_start_min);
  user_data[index].getStartTime_min();
  user_data[index].setEndTime_hr(user_end_hr);
  user_data[index].getEndTime_hr();
  user_data[index].setEndTime_min(user_end_min);
  user_data[index].getEndTime_min();

  if(user_data[index].isValid(user_month,user_date) == 1){
    break;
  }
  else
  {
    cout<<"Please ensure your information is correct!\n";
    cout<<"------------------------------\n";
  }
}
  do
  {
      cout << "Please enter the start hour of the appointment: ";
      cin >> user_start_hr;
      cout << "Please enter the starting minute of the appointment(increment of half an hour):" ;
      cin >> user_start_min;
      cout << "Please enter the ending hour of the appointment ";
      cin >> user_end_hr;
      cout << "Please enter the ending minute of the appointment (increment of half an hour): ";
      cin >> user_end_min;
  } while (user_input.isValid(user_start_hr, user_start_min, user_end_hr, user_end_min) == 0);//loop for keep asking the time if user enters invalid numbers
   // use option 4 to first check if the appointment is booked, check validity then delete if it is valid
  user_data[index].delelteappointment(user_month,user_date,user_start_hr,user_start_min,user_end_hr,user_end_min);
  calendarobject.Delete(user_data[index], user_input);

  // delete a scheduled appointment
  break;
  //////////////////////////////////////////////////////////////////////////////
case 6://to see the whole available calendar
  calendarobject.printFreeTimeSlots_days(User_data1, user_input);
//this is OK to use 
break;}
//end of the switch statement 
cout<<"Would you like to the main menu? 1 - YES, 0 - exit: ";
cin>>rpt;
} while (rpt == 1);

  cout<<"Appointment summary:\n";//printing the summary of the appointment
  User_data1.output(user_month,user_date);
  user_input.output(user_start_hr,user_start_min,user_end_hr,user_end_min);
  
  cout<<"OK with your choice?\n";//confirmation 
  cout<<"Press '1' for yes\n";
  int answer;
  cin>>answer;
  if (answer == 1){
    cout<<"GREAT! See you then!\n";
  }
  if (answer != 1){
    cout<<"Sorry, try again next time :(\n";
  }
  return 0;
}//the end of the program


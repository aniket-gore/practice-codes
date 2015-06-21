#include<iostream>

using namespace std;

const int months[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool isLeapYear(int year){
	return (year%4 == 0 && (year%400 == 0 || year%100 != 0)) ? true : false;
}

int getNumberOfDaysInMonthAndYear(int month, int year){
	return (isLeapYear(year) && month == 2) ? 29 : months[month];
}

void printDate(int day, int month, int year, int whichday){
	cout<<endl<<month<<"/"<<day<<"/"<<year<<","<<whichday;
}

void findWeek(int day, int month, int year, int whichday){
	for(int i=whichday; i>0; i--){
		if(day == 1){
			if(month == 1){
				year--;
				month = 12;
				day = 31;
			}
			else{
				month--;
				day = getNumberOfDaysInMonthAndYear(month,year);
			}
		}
		day--;
	}

	for(int i=1; i<=7; i++){
		printDate(day, month, year,i);
		if(day == getNumberOfDaysInMonthAndYear(month,year)){
			day = 1;
			if(month == 12){
				month = 1;
				year++;
			}
			else{
				month++;
			}
		}
		else{
			day++;
		}
	}
}

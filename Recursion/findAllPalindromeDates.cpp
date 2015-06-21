#include<iostream>
#include<string>

using namespace std;

void findAllPalindromeDates(string date1, string date2){
	string d1 = date1, d2 = date2;
	int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int year1=0,year2=0,day1=0,day2=0,month1=0,month2=0;
	for(int i=4; i<=7; i++){
		year1 = year1 * 10 + (int)(date1[i] - '0');
	}
	for(int i=2; i<=3; i++){
		month1 = month1 * 10 + (int)(date1[i] - '0');
	}
	for(int i=0; i<=1; i++){
		day1 = day1 * 10 + (int)(date1[i] - '0');
	}
	for(int i=4; i<=7; i++){
		year2 = year2 * 10 + (int)(date2[i] - '0');
	}
	for(int i=2; i<=3; i++){
		month2 = month2 * 10 + (int)(date2[i] - '0');
	}
	for(int i=0; i<=1; i++){
		day2 = day2 * 10 + (int)(date2[i] - '0');
	}

	for(int i = year1; i<=year2; i++){
		int day=0, month=0;
		int year = i;
		for(int i=4; i>=3; i--){
			day = day * 10 + year % 10;
			year /= 10;
		}
		for(int i=2; i>=1; i--){
			month = month * 10 + year % 10;
			year /= 10;
		}
		if(i%4 == 0 && (i%400==0 || i%100!=0) && month == 2){
			months[1] = 29;
		}
		if(day <= months[month]){
			cout<<endl<<day<<" "<<month<<" "<<i;
		}
		months[1] = 28;
	}
}
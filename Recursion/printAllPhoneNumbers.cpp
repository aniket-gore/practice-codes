#include<iostream>
#include<string>

using namespace std;

//n = required length,
void printAllPhoneNumbers(string number,int remlength, int n, int digit1, int digit2, int digit3){
	if(remlength == 0){
		if(number.at(1) == '4' && number.at(number.length()-1) == '4'){
			return;
		}
		else if(number.at(number.length()-1) == '4'){
				number.replace(0,1,1,'4');	
		}
		cout<<endl<<number;
		return;
	}
	string number_copy;
	for(char i=0; i<=9; i++){
		if(i==0 && remlength == n){
			continue;
		}
		else if(i==digit1 || i==digit2 || i==digit3){
			continue;
		}
		else if(!number.empty() && number.at(number.length()-1) == '0'+i){
			continue;
		}
		number_copy = number;
		char buff[10];
		sprintf(buff,"%d",i);
		number = number + buff;
		printAllPhoneNumbers(number,remlength-1,n,digit1,digit2,digit3);
		number = number_copy;//backtracking
	}
}
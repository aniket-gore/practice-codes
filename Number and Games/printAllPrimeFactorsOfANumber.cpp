#include<iostream>
#include<cmath>

using namespace std;

void printAllPrimeFactorsOfANumber(int number){
	//if number is even
	while(number % 2 == 0){
		cout<<"2,";
		number = number/2;
	}
	//if number is other composite number
	for(int i=3; i<=sqrt((double)number); i=i+2){
		while(number%i == 0){
			cout<<i<<",";
			number = number/i;
		}
	}
	//if remaining number is prime
	if(number > 2){
		cout<<number;
	}
}
#include<iostream>
#include<string>

using namespace std;

void integerToRoman(int num){
	string output = "";
	int integer[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
	string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	
	int i=0;
	while(num){
		int quotient = num / integer[i];
		num -= quotient * integer[i];
		for(; quotient > 0; quotient--){
			output += roman[i];
		}
		i++;
	}
	cout<<"roman = "<<output<<endl;
}
/*
int main(){
	integerToRoman(16);
	return 1;
}*/
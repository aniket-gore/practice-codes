#include<iostream>
#include<string>

using namespace std;

void pronounceNumber(int number){
	
	string output = "";
	string ones[] = {"","one","two","three","four","five","six","seven","eight","nine"};
	string tens[] = {"","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
	string teens[] = {"","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
	while(number){
		
		if(number%100 > 10 && number%100 < 20){
			output = teens[number%10] + " " + output;
		}
		else{
			output = ones[number%10] + " " + output;
			output = tens[(number%100)/10] + " " + output;
		}

		output = (number%1000)/100 ? ones[(number%1000)/100] + " " + "hundred" + " " + output : output;
		// to check if 'and' needs to be added after 'thousand'
		bool thousands_flag = number%1000 ? true : false;
		number /= 1000;
		if(number){
			// e.g. number = 1000 then, output till now is " "
			output = thousands_flag ? "thousand and " + output : "thousand ";
		}
	}
	cout<<output;
}
/*
int main(){
	pronounceNumber(999);
	cout<<endl;
	return 1;
}*/
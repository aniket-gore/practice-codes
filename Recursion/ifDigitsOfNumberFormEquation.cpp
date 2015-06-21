#include<iostream>
#include<string>

using namespace std;

int toNumber(string str){
	int num = 0;
	for(int i=0; i<str.length(); i++){
		num = num * 10 + (int)(str[i]  - '0');
	}
	return num;
}

// eg. num = 123, this num forms equation because 1+2=3.
// eg. num = 8917, this num forms equation because 8+9=17

void ifDigitsOfNumberFormEquation(string num){
	int len = num.length();
	for(int i=1; i<=len-2; i++){
		string first = num.substr(0,i);
		for(int j=i; i<=len-2; j++){
			string second = num.substr(i,len-j-1);
			string sum = num.substr(i+len-j-1);
			if(toNumber(first)+toNumber(second) == toNumber(sum)){
				cout<<endl<<first<<"+"<<second<<"="<<sum<<endl;
				return;
			}
		}
	}
	cout<<endl<<"Not a valid sum"<<endl;
}
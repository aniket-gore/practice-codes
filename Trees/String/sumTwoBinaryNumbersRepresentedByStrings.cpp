#include<iostream>
#include<string>

using namespace std;

string sumTwoBinaryNumbersRepresentedByStrings(string str1, string str2){
	if(str1.length() == 0){
		return str2;
	}
	else if(str2.length() == 0){
		return str1;
	}
	else{
		int sum = 0, carry = 0, i = str1.length()-1, j = str2.length()-1, bit1, bit2;
		string output = "";
		while(i >=0 || j >= 0){
			bit1 = i >= 0 ? str1[i] - '0' : 0;
			bit2 = j >= 0 ? str2[j] - '0' : 0;
			sum = bit1 + bit2 + carry;
			carry = (sum >> 1) & 0x01; // check 2nd bit
			char sumbit = '0' + (sum & 0x01); // check 1st bit (LSB)
			output = sumbit + output;
			i--;
			j--;
		}
		if(carry){ // check if carry at the end
			char carrybit = '0' + carry;
			output = carrybit + output;
		}
		return output;
	}
}
/*
int main(){
	cout<<sumTwoBinaryNumbersRepresentedByStrings("1000","110")<<endl;
	return 1;
}*/
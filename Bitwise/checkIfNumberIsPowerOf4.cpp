#include<iostream>

using namespace std;

bool checkIfNumberIsPowerOf4(int num){
	if(num == 0){
		return false;
	}
	return (num & (num-1)) == 0 && (num & 0xAAAAAAAA) == 0;
}
/*
int main(){
	cout<<checkIfNumberIsPowerOf4(128)<<endl;
	cout<<checkIfNumberIsPowerOf4(256)<<endl;
	return 1;
}*/
#include<iostream>

using namespace std;

void findStackGrowing(int *a){
	int b = 20;
	if(a > &b){
		cout<<endl<<"Stack growing down: a="<<a<<", b="<<&b<<endl;
	}
	else{
		cout<<endl<<"Stack growing up: a="<<a<<", b="<<&b<<endl;
	}
}

void findStackGrowingCaller(){
	int a = 10;
	findStackGrowing(&a);
}
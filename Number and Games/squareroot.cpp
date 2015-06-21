#include<iostream>
using namespace std;

double squareroot(double num) {
	double f,s,t;
	f = num/2;
	s = f/2;
	t = (f+s)/2;
	cout<<"\nstarted\n"<<t;
	while(fabs(num - pow(t,2)) > 0.00001) {
		f =	t;
		s = num/f;
		t = (f+s)/2;
		cout<<"\n"<<t;
	}
	return t;
}
#include<iostream>

using namespace std;

/*
Given a function KNOWS(A,B), which returns 1 if A knows B (and not necessarily the other way around) 
									   and 0 if A does not know B. 

A Celebrity is one who does not know anyone, 
and one who is known by everybody. 

For a list of N people, find all celebrities in linear time.
*/

//a[i][j] =1 denotes person i know person j
void findCelebrities(int **arr, int length){
	int celeb = 0;
	for(int i=1; i<length; i++){
		if(arr[celeb][i] || !arr[i][celeb]){
			celeb = i;
		}
	}
	for(int i=0; i<length; i++){
		if( i != celeb && (arr[celeb][i] || !arr[i][celeb])){
			cout<<endl<<"No celebrity found!"<<endl;
			return;
		}
	}
	cout<<endl<<"Celebrity found at "<<celeb<<endl;
}
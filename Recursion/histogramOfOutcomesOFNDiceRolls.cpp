#include<iostream>
#include<map>

using namespace std;
/*
Given N dice with m sides, print histogram of all outcomes of dice throws.
e.g. N=2, m = 3
(1, 1) -> 2 
(1, 2) -> 3 
(1, 3) -> 4 
(2, 1) -> 3 
(2, 2) -> 4 
(2, 3) -> 5 
(3, 1) -> 4 
(3, 2) -> 5 
(3, 3) -> 6 

And the function should return: 

2: 1 
3: 2 
4: 3 
5: 2 
6: 1
*/
void histogramOfOutComesOfNDiceRolls(int N, int sides, int outcomes[], int index, map<int,int> &histogram){
	if(index == -1){
		int sum=0;
		for(int i=0; i<N; i++){
			sum += outcomes[i];
		}
		if(histogram.find(sum) != histogram.end()){
			histogram[sum]++;	
		}
		else{
			histogram.insert(make_pair(sum,1));
		}
		return;
	}

	for(int i=1; i<=sides; i++){
		outcomes[index] = i;
		histogramOfOutComesOfNDiceRolls(N,sides,outcomes,index-1,histogram);
	}
}
/*
int main(){
	int outcomes[2] = {0}; //size = no. of dice
	map<int,int> histogram;
	// 4th parameter : index = index in the array denoting which dice
	// we start with last dice, and decrement till 0th by filling values from 1 to m
	histogramOfOutComesOfNDiceRolls(2,3,outcomes,1,histogram);
	cout<<"histogram = ";
	map<int,int>::iterator iter;
	for(iter = histogram.begin(); iter != histogram.end(); iter++){
		cout<<endl<<iter->first<<" : "<<iter->second;
	}
	cout<<endl;
	return 1;
}*/
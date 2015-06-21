#include<iostream>
#include<cmath>
#include<map>

using namespace std;

void insertInMap(map<int,int> &map, int factor){
	if(map.find(factor) == map.end()){
		map[factor] = 1;
	}
}

void allPossibleSeedsOfANumber(int num){
	typedef map<int,int> map;
	map factorsMap;
	for(int i=2; i<=sqrt(double(num)); i++){
		if(num%i == 0){
			insertInMap(factorsMap,i);
			insertInMap(factorsMap,num/i);
		}	
	}

	for(map::iterator iter=factorsMap.begin(); iter != factorsMap.end(); iter++){
		int factor = iter->first;
		int product = factor;
		while(factor){
			product = product * (factor%10);
			factor /= 10;
		}
		if(product == num){
			cout<<endl<<iter->first;
		}
	}
}
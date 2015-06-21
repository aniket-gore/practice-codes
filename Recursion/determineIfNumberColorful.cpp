#include<iostream>
#include<vector>
#include<map>

using namespace std;

bool determineIfNumberColorful(int num){
	vector<int> productVector;
	map<int,int> uniqueProductMap;
	int digit, index=0, product = 0;
	while(num){
		digit = num % 10;
		num /= 10;
		int length = productVector.size();//store intial length before adding new products
		for(int i=index; i<length; i++){
			product = productVector[i] * digit;
			if(uniqueProductMap.find(product) ==  uniqueProductMap.end()){
				productVector.push_back(product);
				uniqueProductMap[product] = 1;
			}
			else{
				return false;
			}
			index = i+1;
		}
		productVector.push_back(digit);
		uniqueProductMap[digit] = 1;
	}
	return true;
}
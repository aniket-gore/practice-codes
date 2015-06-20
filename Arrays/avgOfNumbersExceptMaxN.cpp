#include<iostream>
#include<queue>

using namespace std;

//N is number of max elements we don't wont to consider in the avg
double avgOfNumbersExceptMaxN(int list[], int length, int N){
	priority_queue<int,vector<int>,greater<int>> minheap;
	int sum = 0;
	for(int i=0; i<length; i++){
		if(minheap.size() < N){
			minheap.push(list[i]);
		}
		else{
			if(minheap.top() < list[i]){
				minheap.pop();
				minheap.push(list[i]);
			}
		}
		sum += list[i];
	}
	while(!minheap.empty()){
		sum -= minheap.top();
		minheap.pop();
	}
	return sum/(length - N);
}
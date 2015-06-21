#include<iostream>

using namespace std;

int maxCostRodCutting(int *cost, int size, int *mem){
	if(size <= 0){
		return 0;
	}
	if(mem[size-1] != -1){
		return mem[size-1];
	}
	int max_cost = -1;
	for(int i=0; i<size; i++){
		int cost_at_i = cost[i]+maxCostRodCutting(cost,size-i-1,mem);
		max_cost = cost_at_i > max_cost ? cost_at_i : max_cost;
	}
	mem[size-1] = max_cost;
	return max_cost;
}

int maxCostRodCuttingCaller(int *cost, int size){
	int *mem = new int[size];
	fill(mem,mem+size,-1);
	return maxCostRodCutting(cost,size,mem);
}

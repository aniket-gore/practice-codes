#include<iostream>

using namespace std;

#define SIZE 30 // length of skyline

// Time : O(number of buildings  * largest width of building) i.e. O(length of skyline)

void skylineProblem(int *height, int *width, int *position, int numberOfBuldings){
	int *skyline = new int[SIZE];
	fill(skyline,skyline+SIZE,0);

	// as you read the buildings, store the max heights till now on the x-axis
	for(int i=0; i<numberOfBuldings; i++){
		for(int j=0; j<width[i]; j++){
			if(skyline[position[i]+j] < height[i]){
				skyline[position[i]+j] = height[i];
			}
		}
	}
	// skyline array is our output
	cout<<"(0,"<<skyline[0]<<"), ";
	int last = skyline[0];
	for(int i=1; i<SIZE; i++){
		// print if height changes
		if(skyline[i] != last){
			cout<<"("<<i<<","<<skyline[i]<<"), ";
			last = skyline[i];
		}
	}
}
/*
int main(){
	// height of building, width of building, starting position of building
	int height[] = {9,9,4,11,7,3};
	int width[] = {3,5,12,3,10,2};
	int position[] = {17,9,8,3,1,19};
	skylineProblem(height,width,position,6);
	cout<<endl;
	return 1;
}*/
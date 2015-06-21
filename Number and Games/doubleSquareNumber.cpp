#include<iostream>

using namespace std;

/*
Double square number is a number which is equal to sum of 2 perfect squares. Find all ways in which it can be written
as sum of 2 squares.
e.g. 10 is a double square number because 1^2 + 3^2 = 10
*/
//Time : O(n ^ 1/2)
void doubleSquareNumber(int num){
	int start = 0;
	int end = sqrt((double)num);
	int sum;
	while(start <= end){
		sum = start * start + end * end;
		if(sum == num){
			cout<<start<<","<<end<<endl;
			start++;
			end--;
		}
		else if(sum > num){
			end--;
		}
		else{
			start++;
		}
	}
}
/*
int main(){
	doubleSquareNumber(10);
	return 1;
}*/
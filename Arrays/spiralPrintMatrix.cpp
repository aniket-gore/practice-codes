#include<iostream>

using namespace std;
//n x n matrix
void printSpiralMatrix(int **matrix, int n){
	int min_i = 0, max_i = n-1, min_j = 0, max_j = n-1;

	while(min_i <= max_i || min_j <= max_j){
		for(int j=min_j; j<max_j; j++){
			cout<<" "<<matrix[min_i][j];
		}
		for(int i=min_i; i<max_i; i++){
			cout<<" "<<matrix[i][max_j];
		}
		for(int j=max_j; j>min_j; j--){
			cout<<" "<<matrix[max_i][j];
		}
		for(int i=max_i; i>min_i; i--){
			cout<<" "<<matrix[i][min_j];
		}
		min_i++;
		max_i--;
		min_j++;
		max_j--;
	}
	if(n%2 == 1){
		cout<<" "<<matrix[max_i][max_j];
	}
}
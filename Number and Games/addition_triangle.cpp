#include<iostream>
#include<vector>

using namespace std;

vector<int> getVector(vector<int> v){
	vector<int> newvec;
	for(int i=0; i<v.size()-1; i++){
		int sum = v[i] + v[i+1];
		newvec.push_back(sum);
	}
	return newvec;
}

void additionTriangle(int arr[], int length){
	vector<vector<int>> container;
	vector<int> single;
	for(int i=0; i<length; i++){
		single.push_back(arr[i]);
	}
	container.push_back(single);

	for(int i=0; i<length-1; i++){
		container.push_back(getVector(container[i]));
	}

	//print the output
	for(int i=0; i<container.size(); i++){
		cout<<endl;
		for(int j=0; j<container[i].size(); j++){
			cout<<"\t"<<container[i][j];
		}
	}
}
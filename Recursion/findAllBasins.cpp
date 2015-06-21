#include<iostream>
#include<map>
#include<vector>
using namespace std;

/*
 *  Given matrix, the water in a cell flows to the smallest of its neighbors(up,down,left,right) if the smallest is smaller than value in the current cell. Return the count of nodes in each basin formed.
 * */

#define min(a,b) (a<b ? a : b)
#define min4(a,b,c,d) (min(min(a,b),min(c,d)))

void findAllBasins(){
	// Accept input
	int size;
	cin >> size;
	int **arr = (int **)malloc(size * sizeof(int *));
	for(int i=0; i<size; i++){
		arr[i] = (int *)malloc(size * sizeof(int));
		for(int j=0; j<size; j++){
			cin >> arr[i][j];
		}
	}
/*
	// print matrix
	for(int i=0; i<size; i++){
		cout<<endl;
		for(int j=0; j<size; j++){
			cout<<arr[i][j];
		}
	}
*/
	// For each cell, put smallest neighbor as the value in the map and mark source cells
	map<int,int> mp;
	int *source = new int[size*size];
	fill(source,source+size*size,1);

	int left,right,up,down,min;
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			left = j == 0 ? INT_MAX : arr[i][j-1];
			right = j == size-1 ? INT_MAX : arr[i][j+1];
			up = i == 0 ? INT_MAX : arr[i-1][j];
			down = i == size-1 ? INT_MAX : arr[i+1][j];
			min = min4(left,right,up,down);
			if(min > arr[i][j]){
				mp.insert(make_pair(i*size+j,-1)); // -1 denotes it is a sink
			}
			else if(min == left){
				mp.insert(make_pair(i*size+j,i*size+(j-1)));
				source[i*size+(j-1)] = -1;
			}
			else if(min == right){
				mp.insert(make_pair(i*size+j,i*size+(j+1)));
				source[i*size+(j+1)] = -1;
			}
			else if(min == up){
				mp.insert(make_pair(i*size+j,(i-1)*size+j));
				source[(i-1)*size+j] = -1;
			}
			else if(min == down){
				mp.insert(make_pair(i*size+j,(i+1)*size+j));
				source[(i+1)*size+j] = -1;
			}
		}
	}
	
/*	// print mp
	map<int,int>::iterator iter_print;
	cout<<endl;
	for(iter_print = mp.begin(); iter_print != mp.end(); iter_print++){
		cout<<iter_print->first<<" --> "<<iter_print->second<<endl;
	}
*/
	// Mark the basins
	map<int,int> basin_mp;
	int cell = -1, basin_count = 0, count;
	for(int i=0; i<size*size; i++){
		if(source[i] != -1){
			cell = i;
			while(mp[cell] != -1){// TO DO : detect if forming a Y
				cell = mp[cell];
			}
			if(basin_mp.find(cell) == basin_mp.end()){
				count = ++basin_count;
			}
			else{
				count = basin_mp[cell];
			}
			cell = i;
			while(mp[cell] != -1){
				if(basin_mp.find(cell) == basin_mp.end())
					basin_mp.insert(make_pair(cell,count));
				cell = mp[cell];
			}
			if(basin_mp.find(cell) == basin_mp.end())
				basin_mp.insert(make_pair(cell,count));
		}
	}

	// Count the basins
	map<int,int> basin_counter;
	map<int,int>::iterator iter;
	for(iter = basin_mp.begin(); iter != basin_mp.end(); iter++){
		if(basin_counter.find(iter->second) == basin_counter.end()){
			basin_counter.insert(make_pair(iter->second,1));
		}
		else{
			basin_counter[iter->second]++;
		}
	}

	cout<<endl;
	for(iter = basin_counter.begin(); iter!= basin_counter.end(); iter++){
		cout<<iter->second<<" ";
	}
}
/*
int main(){
	findAllBasins();
	return 1;
}*/

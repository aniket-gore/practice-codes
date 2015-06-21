#include<iostream>
#include<map>
#include<vector>

using namespace std;

bool checkBounds(int i, int collen){
	int row = i/collen;
	int col = i%collen;
	return (row <= 0 || row > 3 || col < 0 || col > 3) ? false : true;
}

void checkRight(char **arr, int i, int collen, map<int,bool *> &visited,int &redCount, int &blackCount){
	int count = 1;
	++i;
	int row = i/collen;
	int col = i%collen;
	while(checkBounds(i,collen) && !(visited[i])[0]){
		if(arr[row][col-1] == arr[row][col]){
			count++;
			cout <<endl<<(visited[i])[0];
			(visited[i])[0] = true;
			cout <<endl<<(visited[i])[0];
			++i;
			row = i/collen;
			col = i%collen;
		}
		else{
			if(count >=3 && arr[row][col-1] == 'r'){
				redCount += count - 2;
			}
			else if(count >=3 && arr[row][col-1] == 'b'){
				blackCount += count - 2;
			}
			return;
		}
	}
}

void checkDown(char **arr, int i, int collen, map<int,bool *> &visited,int &redCount, int &blackCount){
	int count = 1;
	int row = i/collen;
	int col = i%collen;
	while(checkBounds(++row,col) && !(visited[i])[1]){
		if(arr[row-1][col] == arr[row][col]){
			count++;
			(visited[i])[0] = true;
		}
		else{
			if(count >=3 && arr[row-1][col] == 'r'){
				redCount += count - 2;
			}
			else if(count >=3 && arr[row-1][col] == 'b'){
				blackCount += count - 2;
			}
			return;
		}
	}
}

void checkLeftDown(char **arr, int i, int collen, map<int,bool *> &visited,int &redCount, int &blackCount){
	int count = 1;
	int row = i/collen;
	int col = i%collen;
	while(checkBounds(++row,--col) && !(visited[i])[2]){
		if(arr[row-1][col+1] == arr[row][col]){
			count++;
			(visited[i])[2] = true;
		}
		else{
			if(count >=3 && arr[row-1][col+1] == 'r'){
				redCount += count - 2;
			}
			else if(count >=3 && arr[row-1][col+1] == 'b'){
				blackCount += count - 2;
			}
			return;
		}
	}
}

void checkRightDown(char **arr, int i, int collen, map<int,bool *> &visited,int &redCount, int &blackCount){
	int count = 1;
	int row = i/collen;
	int col = i%collen;
	while(checkBounds(++row,++col) && !(visited[i])[3]){
		if(arr[row-1][col-1] == arr[row][col]){
			count++;
			(visited[i])[3] = true;
		}
		else{
			if(count >=3 && arr[row-1][col-1] == 'r'){
				redCount += count - 2;
			}
			else if(count >=3 && arr[row-1][col-1] == 'b'){
				blackCount += count - 2;
			}
			return;
		}
	}
}

void redBlackCountingWinner(char **arr, int rowlen, int collen){
	//print arr
	for(int i=0; i<rowlen; i++){
		cout<<endl;
		for(int j=0; j<collen; j++){
			cout<<"\t"<<arr[i][j];
		}
	}

	map<int,bool *> visited;
	for(int i=0; i<rowlen*collen; i++){
		bool *point = new bool[4];
		point[0] = point[1] = point[2] = point[3] = false;
		visited[i] = point;
	}

	int redCount = 0, blackCount = 0;
	for(int i=0; i<rowlen*collen; i++){
		int row = i/collen;
		int col = i%collen;
		checkRight(arr,i,collen,visited,redCount,blackCount);
		checkDown(arr,i,collen,visited,redCount,blackCount);
		checkLeftDown(arr,i,collen,visited,redCount,blackCount);
		checkRightDown(arr,i,collen,visited,redCount,blackCount);
	}
	cout<<endl<<"r = "<<redCount;
	cout<<endl<<"b = "<<blackCount;
}
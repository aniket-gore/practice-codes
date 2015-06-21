#include<iostream>
#include<map>
#include<cmath>
#include<string>

using namespace std;

void recurse(multimap<int,string> &sequence, int **grid, int numrows, int numcols, int i, int j, int count, string cells){
	
	if(i>=0 && i<numrows && j-1>=0 && j-1<numcols){
		if(abs(grid[i][j] - grid[i][j-1]) == 1){
			char buff[10];
			sprintf(buff,"%d",grid[i][j-1]);
			cells = cells + "," + buff;
			count++;
			recurse(sequence,grid,numrows,numcols,i,j-1,count,cells);
		}
	}
	if(i>=0 && i<numrows && j+1>=0 && j+1<numcols){
		if(abs(grid[i][j] - grid[i][j+1]) == 1){
			char buff[10];
			sprintf(buff,"%d",grid[i][j+1]);
			cells = cells + "," + buff;
			count++;
			recurse(sequence,grid,numrows,numcols,i,j+1,count,cells);
		}
	}
	if(i-1>=0 && i-1<numrows && j>=0 && j<numcols){
		if(abs(grid[i][j] - grid[i-1][j]) == 1){
			char buff[10];
			sprintf(buff,"%d",grid[i-1][j]);
			cells = cells + "," + buff;
			count++;
			recurse(sequence,grid,numrows,numcols,i-1,j,count,cells);
		}
	}
	if(i+1>=0 && i+1<numrows && j>=0 && j<numcols){
		if(abs(grid[i][j] - grid[i+1][j]) == 1){
			char buff[10];
			sprintf(buff,"%d",grid[i+1][j]);
			cells = cells + "," + buff;
			count++;
			recurse(sequence,grid,numrows,numcols,i+1,j,count,cells);
		}
	}
	sequence.insert(make_pair(count,cells));
}

void longestSnakeSequence(int **grid, int numrows, int numcols){
	multimap<int,string> sequence;
	string cells = "";
	int maxlength = 0;
	for(int i=0; i<numrows; i++){
		for(int j=0; i<numcols; j++){
			char buff[10];
			sprintf(buff,"%d",grid[i][i]);
			string cells = buff;
			recurse(sequence,grid,numrows,numcols,i,j,1,cells);
		}
	}
}
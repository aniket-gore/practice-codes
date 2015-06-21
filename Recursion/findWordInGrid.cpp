#include<iostream>
#include<vector>

using namespace std;

bool findWordLeft(int i, int j, char grid[][5], char word[]){
	int index = 0;
	vector<pair<int,int>> position;
	j++;
	while(word[index] != '\0'){
		if( j!= 0 && grid[i][--j] == word[index]){
			position.push_back(make_pair(i,j));
		}
		else{
			return false;
		}
		index++;
	}
	for(int i=0; i<position.size(); i++){
		cout<<endl<<position[i].first<<"\t"<<position[i].second;
	}
	return true;
}

bool findWordRight(int i, int j, char grid[][5], char word[]){
	int index = 0;
	vector<pair<int,int>> position;
	j--;
	while(word[index] != '\0'){
		if(j!=4 && grid[i][++j] == word[index]){
			position.push_back(make_pair(i,j));
		}
		else{
			return false;
		}
		index++;
	}
	for(int i=0; i<position.size(); i++){
		cout<<endl<<position[i].first<<"\t"<<position[i].second;
	}
	return true;
}

bool findWordUp(int i, int j, char grid[][5], char word[]){
	int index = 0;
	vector<pair<int,int>> position;
	i++;
	while(word[index] != '\0'){
		if(i!=0 && grid[--i][j] == word[index]){
			position.push_back(make_pair(i,j));
		}
		else{
			return false;
		}
		index++;
	}
	for(int i=0; i<position.size(); i++){
		cout<<endl<<position[i].first<<"\t"<<position[i].second;
	}
	return true;
}

bool findWordDown(int i, int j, char grid[][5], char word[]){
	int index = 0;
	vector<pair<int,int>> position;
	--i;
	while(word[index] != '\0'){
		if(i!=4 && grid[++i][j] == word[index]){
			position.push_back(make_pair(i,j));
		}
		else{
			return false;
		}
		index++;
	}
	for(int i=0; i<position.size(); i++){
		cout<<endl<<position[i].first<<"\t"<<position[i].second;
	}
	return true;
}

bool findWordUpLeft(int i, int j, char grid[][5], char word[]){
	int index = 0;
	vector<pair<int,int>> position;
	++i;
	++j;
	while(word[index] != '\0'){
		if(i!=0 && j!=0 && grid[--i][--j] == word[index]){
			position.push_back(make_pair(i,j));
		}
		else{
			return false;
		}
		index++;
	}
	for(int i=0; i<position.size(); i++){
		cout<<endl<<position[i].first<<"\t"<<position[i].second;
	}
	return true;
}

bool findWordUpRight(int i, int j, char grid[][5], char word[]){
	int index = 0;
	vector<pair<int,int>> position;
	++i;
	--j;
	while(word[index] != '\0'){
		if(i!=0 && j!=4 && grid[--i][++j] == word[index]){
			position.push_back(make_pair(i,j));
		}
		else{
			return false;
		}
		index++;
	}
	for(int i=0; i<position.size(); i++){
		cout<<endl<<position[i].first<<"\t"<<position[i].second;
	}
	return true;
}

bool findWordDownLeft(int i, int j, char grid[][5], char word[]){
	int index = 0;
	vector<pair<int,int>> position;
	--i;
	++j;
	while(word[index] != '\0'){
		if(i!=4 && j!=0 && grid[++i][--j] == word[index]){
			position.push_back(make_pair(i,j));
		}
		else{
			return false;
		}
		index++;
	}
	for(int i=0; i<position.size(); i++){
		cout<<endl<<position[i].first<<"\t"<<position[i].second;
	}
	return true;
}

bool findWordDownRight(int i, int j, char grid[][5], char word[]){
	int index = 0;
	vector<pair<int,int>> position;
	--i;
	--j;
	while(word[index] != '\0'){
		if(i!=4 && j!=4 && grid[++i][++j] == word[index]){
			position.push_back(make_pair(i,j));
		}
		else{
			return false;
		}
		index++;
	}
	for(int i=0; i<position.size(); i++){
		cout<<endl<<position[i].first<<"\t"<<position[i].second;
	}
	return true;
}

void findWordInGrid(char grid[5][5], char word[], int wordlength){
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			bool found = false;
			if(grid[i][j] == word[0]){
				if(findWordLeft(i,j,grid,word)){
					return;
				}
				if(findWordRight(i,j,grid,word)){
					return;
				}
				if(findWordUp(i,j,grid,word)){
					return;
				}
				if(findWordDown(i,j,grid,word)){
					return;
				}
				if(findWordUpLeft(i,j,grid,word)){
					return;
				}
				if(findWordUpRight(i,j,grid,word)){
					return;
				}
				if(findWordDownLeft(i,j,grid,word)){
					return;
				}
				if(findWordDownRight(i,j,grid,word)){
					return;
				}
			}
		}
	}
	cout<<endl<<"Word not found";
}
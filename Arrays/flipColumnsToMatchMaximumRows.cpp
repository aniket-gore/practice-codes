#include<iostream>
#include<string>
#include<map>

using namespace std;

#define max(a,b) (a > b ? a : b)

// Return maximum number of rows matched

int flipColumnsToMatchMaximumRows(void){
	// Accept input
	/*
	int size;
	cin >> size;
	char **arr = (char **)malloc(size * sizeof(char *));
	for(int i=0; i<size; i++){
		arr[i] = (char *)malloc(size * sizeof(char));
		for(int j=0; j<size; j++){
			cin >> arr[i][j];
		}
	}
	*/
	int rows,columns;
    string instr;
    cin >> rows >> columns;
    char ** arr = (char **)malloc(rows * sizeof(char *));
    for(int i=0; i<rows; i++){
        cin >> instr;
        arr[i] = (char *)malloc(columns * sizeof(char));
        for(int j=0; j<instr.length(); j++){
            arr[i][j] = instr[j];
        }
    }
	// print matrix
	for(int i=0; i<rows; i++){
		cout<<endl;
		for(int j=0; j<columns; j++){
			cout<<arr[i][j];
		}
	}
	
	// flip all rows starting with 'T'
	char **arr_copy = (char **)malloc(rows * sizeof(char *));
	for(int i=0; i<rows; i++){
		arr_copy[i] = (char *)malloc(columns * sizeof(char));
		if(arr[i][0] == 'T'){
			for(int j=0; j<columns; j++){
				switch(arr[i][j]){
				case 'P':
					arr_copy[i][j] = 'T';
					break;
				case 'T':
					arr_copy[i][j] = 'P';
				}
			}
		}
		else{
			for(int j=0; j<columns; j++){
				arr_copy[i][j] = arr[i][j];
			}
		}
	}
	/*
	// print matrix
	for(int i=0; i<size; i++){
		cout<<endl;
		for(int j=0; j<size; j++){
			cout<<arr_copy[i][j];
		}
	}
	*/
	// store counts of distinct rows in hashmap
	map<string,int> mp;
	string concat = "";
	for(int i=0; i<rows; i++){
		concat = "";
		for(int j=0; j<columns; j++){
			concat += arr_copy[i][j];
		}
		if(mp.find(concat) == mp.end()){
			mp.insert(make_pair(concat,1));
		}
		else{
			mp[concat]++;
		}
	}

	// find max count
	map<string,int>::iterator iter;
	int max_count_of_same_rows = 0;
	for(iter = mp.begin(); iter != mp.end(); iter++){
		max_count_of_same_rows = max(max_count_of_same_rows,iter->second);
	}
	return max_count_of_same_rows;
}

int main(){
	cout << flipColumnsToMatchMaximumRows();
	return 1;
}
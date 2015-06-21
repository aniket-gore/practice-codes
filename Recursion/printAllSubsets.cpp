#include<iostream>
#include<string>

using namespace std;

/*iterative approach for all subsets,
eg. set of 5
for limit = 1 << 5,
	check the bits set and output those indices
*/

void printAllSubsets(string str, bool arr[], int index){
	if(index == str.length()){
		cout<<endl<<"{";
		for(int i=0; i<str.length(); i++){
			if(arr[i]){
				cout<<str[i];
			}
		}
		cout<<"}";
		return;
	}
	arr[index] = true;
	printAllSubsets(str,arr,index+1);
	arr[index] = false;
	printAllSubsets(str,arr,index+1);
}
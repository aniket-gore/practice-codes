#include<iostream>

using namespace std;

int findIndex(char arr[], char c){
	int i=0;
	while(arr[i] != '\0'){
		if(arr[i] == c){
			return i;
		}
		i++;
	}
	return -1;
}

//convert str1 to str2
void convertStringToOtherBySwap(char str1[], char str2[]){
	for(int i=0; i<strlen(str2); i++){
		int index = findIndex(str1,str2[i]);
		for(int j=index; j>i; j--){
			swap(str1[j],str1[j-1]);
			cout<<endl<<str1;
		}
	}
}

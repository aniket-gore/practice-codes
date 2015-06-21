#include<iostream>

using namespace std;

char * strtok(char *str, const char *delim){
	// copy of string to be used for future calls
	static char *store_str;

	// if string is passed
	if(str != NULL){
		store_str = (char *)malloc(sizeof(str));
		strcpy(store_str,str);
	}
	// if string is NULL and static pointer is NULL
	else if(store_str == NULL){
		return NULL;
	}
	// if string is NULL, and static pointer contains string
	else{
		str = store_str;
	}

	int output_index = 0;
	bool flag = false;

	// str is the output string
	while(*store_str){
		// for all the delimiters
		for(int i=0; i<strlen(delim); i++){
			if(*store_str == delim[i]){
				// if delim is found at the 1st position, shift the start of output token ahead by 1 i.e. ignore this delim
				if(output_index == 0){
					flag = true;
					str++;
				}
				else{
					// if delim is found elsewhere, return the token
					store_str++;
					str[output_index] = '\0';
					return str;
				}
			}
		}
		if(!flag){
			// if delim is not found, increment output_index which will mark the end of output token
			output_index++;
		}
		store_str++;
		flag = false;
	}
	// end of input string
	store_str = NULL;
	str[output_index] = '\0';
	return str;
}
/*
int main(){
	char str[] = ",ab,,c,d";
	cout<<strtok(str,",")<<endl;
	cout<<strtok(NULL,",")<<endl;
	return 1;
}*/
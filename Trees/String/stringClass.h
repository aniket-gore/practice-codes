#include<iostream>

using namespace std;

class stringClass{
private:
	char *str;
	int count;

public:
	//default constructor
	stringClass(){
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
		count = 1;
	}

	//constructor
	stringClass(char *st){
		int strlength = strlen(st) + 1;
		str = (char *)malloc(strlength * sizeof(char));
		for(int i=0; i<strlength; i++){
			str[i] = st[i];
		}
		count = 1;
	}

	//copy constructor
	stringClass(const stringClass &st){
		int strlength = strlen(st.str) + 1;
		str = (char *)malloc(strlength * sizeof(char));
		for(int i=0; i<strlength; i++){
			str[i] = st.str[i];
		}
		count = 1;
	}

	//Assignment operator
	stringClass & operator = (const stringClass &st){
		int strlength = strlen(st.str) + 1;
		str = (char *)realloc(str,strlength * sizeof(char));
		for(int i=0; i<strlength; i++){
			str[i] = st.str[i];
		}
		count = 1;
		return *this;
	}

	//destructor
	
	~stringClass(){
		if(count == 1){
			free(str);
		}
	}
};
#ifndef _iostream
#include<iostream>
#endif
using namespace std;

void substring(void) {

	std::string full = "eereereebee";
	std::string part = "eereebee";
	bool flag = true;
	int pos = 0;
	
	for(int i=0,l=full.length(); i<l; ++i){
		if(full.at(i) == part.at(pos)){
			pos++;
			if(pos == part.length()){
				cout<<"Found"<<endl;
				flag = false;
				break;
			}
		}else if(pos > 0){
			i -= pos;
			pos = 0;
		}
	}

	if(flag) {
		cout<<"Not found"<<endl;
	}
}
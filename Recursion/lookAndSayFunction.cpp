#include<iostream>
#include<string>

using namespace std;

void lookAndSayFunction(string num){
	for(int count=0; count<10; count++){//to print 10 numbers in the series
		char last = num[0];
		int local_count = 1;
		string new_num = "";
		for(int i=1; i<num.length(); i++){
			if(num[i] == last){
				local_count++;
			}
			else{
				char buff[10];
				sprintf(buff,"%d",local_count);
				new_num = new_num + buff + last;
				local_count = 1;
				last = num[i];
			}
		}
		char buff[10];
		sprintf(buff,"%d",local_count);
		new_num = new_num + buff + last;
		
		cout<<"\t"<<new_num;
		num = new_num;
	}
}
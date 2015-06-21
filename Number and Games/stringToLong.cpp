#include "stringToLong.h"

/*
*	Function : trimStringHelper()
*	Description : Helper function to remove leading and trailing spaces
*	Arguments : s = string to be trimmed
*	Returns : trimmed_s = trimmed string
*/
string trimStringHelper(string s){
	string trimmed_s = s;
	// Remove leading spaces
	size_t start = s.find_first_not_of(" \t");
	if(start != string::npos){
		trimmed_s = s.substr(start);
	}
	// Remove trailing spaces
	size_t end = trimmed_s.find_last_not_of(" \t\n");
	if(end != string::npos){
		trimmed_s = trimmed_s.substr(0,end+1);
	}
	return trimmed_s;
}


/*
*	Function : stringToLong()
*	Description : Function to convert string to long
*	Arguments : s = string to be converted to long
*	Returns : num = converted value of type long
*/
long stringToLong(string s){
	long num = 0, start_index = 0;
	bool negation_flag = false;
	// Throw exception if string is empty
	if(s.empty()){
		throw EmptyStringException();
	}
	// Trim the string of leading and trailing spaces
	s = trimStringHelper(s);
	// Check if the number is negative
	if(s[0] == '-'){
		start_index++;
		negation_flag = true;
	}

	for(int i=start_index; i<s.length(); i++){
		// Throw an exception if character is not a digit
		if(s[i] < '0' || s[i] > '9'){
			throw InvalidNumberException();
		}
		num = num * 10 + (long)(s[i] - '0');
		// Throw an exception if number exceeds the long range
		if(num < 0){
			throw LongOverflowException();
		}
	}
	return negation_flag ? num * (-1) : num;
}

/*
*	Function : test()
*	Description : Function to test string conversion to long
*	Arguments : None
*	Returns : None
*/
void test(){
	// Testing
	string str_arr[] = {"123","-123","-0000","-345asdf","   444   ","123123123123123123123123123123123123123123123123"};
	for(int i =0; i<6; i++){
		try{
			cout<<endl<<"string to long : "<<stringToLong(str_arr[i])<<endl;
		}
		catch(EmptyStringException& e){
			cout<<endl<<e.description()<<"STRING : "<<str_arr[i]<<endl;
		}
		catch(InvalidNumberException& e){
			cout<<endl<<e.description()<<"STRING : "<<str_arr[i]<<endl;
		}
		catch(LongOverflowException& e){
			cout<<endl<<e.description()<<endl;
		}
		catch(exception& e){
			cout<<endl<<e.what()<<endl;
		}
	}
}
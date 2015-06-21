#ifndef STRING_TO_LONG_H
#define STRING_TO_LONG_H

#include<iostream>
#include<string>
#include<exception>

using namespace std;

struct EmptyStringException : public exception{
	const char * description() const throw(){
		return "EmptyStringException: Empty string passed.";
	}
};

struct InvalidNumberException : public exception{
	const char * description() const throw(){
		return "InvalidNumberException: String contains invalid number.";
	}
};

struct LongOverflowException : public exception{
	const char * description() const throw(){
		return "LongOverflowException: String represents a number larger than allowed range for long.";
	}
};

#endif
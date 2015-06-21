#include<iostream>

using namespace std;

// Only one instance is ever created AND it has a global access

// Single-threaded design
class Singleton{
private:
	// make the constructor private
	Singleton(){};
	// override the default copy constructor and assignment operator to avoid making copies of the singleton
	Singleton(Singleton const&);// Don't implement
	void operator=(Singleton const&);// Don't implement
public:
	// lazy initialization
	static Singleton& getInstance(){
		// guarantees to be created and destroyed only once
		static Singleton instance;
		return instance;
	}
};
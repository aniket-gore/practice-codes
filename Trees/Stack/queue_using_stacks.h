#include<iostream>
#include<stack>

using namespace std;

template <class type> class Queue{
	stack<type> first;
	stack<type> second;

public:
	void push(type value){
		first.push(value);
	}

	type pop(){
		if(second.empty()){
			while(!first.empty()){
				second.push(first.top());
				first.pop();
			}
		}
		type value = second.top();
		second.pop();
		return value;
	}
};
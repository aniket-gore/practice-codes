#include<iostream>
#include<stack>

using namespace std;

/*
Ex: 
i/p: {2,12,8,6,5,1,2,10,3,2} 
o/p:{12,12,10,10,10,2,10,10,3,2}
replace each element with the next element in the list which is larger than it.
*/
void nextGreaterElement(int arr[], int length){
	stack<int> max_stack;
	if(length == 0){
		return;
	}
	max_stack.push(arr[0]);
	int next,element;
	for(int i=1; i<length; i++){
		if(!max_stack.empty()){
			next = arr[i];
			element = max_stack.top();
			max_stack.pop();
			while(element < next){
				cout<<endl<<element<<" -> "<<next;//print both because we don't always find the result serially
				if(max_stack.empty()){
					break;
				}
				element = max_stack.top();
				max_stack.pop();
			}
			if(element > next){
				max_stack.push(element);
			}
		}
		max_stack.push(next);
	}
	while(!max_stack.empty()){
		cout<<endl<<max_stack.top()<<" -> "<<"-1";
		max_stack.pop();
	}
}
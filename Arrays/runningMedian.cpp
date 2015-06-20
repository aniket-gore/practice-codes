#include<iostream>
#include<queue>

using namespace std;

/*
Create the data structure for a component that will receive a series of numbers over the time and,
when asked, returns the median of all received elements.
*/
// Time : O(nlogn)
// Space : O(n)
void runningMedian(int *arr, int length){
	priority_queue<int> max_heap;
	priority_queue<int,vector<int>,greater<int>> min_heap;

	for(int i=0; i<length; i++){
		// add the element to either of the heaps
		if(min_heap.empty()){
			min_heap.push(arr[i]);
		}
		else if(arr[i] > min_heap.top()){
			min_heap.push(arr[i]);
		}
		else{
			max_heap.push(arr[i]);
		}
		// transfer the top to balance the heaps
		if(abs((int)(min_heap.size()-max_heap.size())) > 1){// size difference > 1
			if(min_heap.size() > max_heap.size()){
				max_heap.push(min_heap.top());
				min_heap.pop();
			}
			else{
				min_heap.push(max_heap.top());
				max_heap.pop();
			}
			cout<<(min_heap.top()+max_heap.top())/2<<",";
		}
		else if(min_heap.size() == max_heap.size()){// sizes = equal
			cout<<(min_heap.top()+max_heap.top())/2<<",";
		}
		else{ // size difference = 1
			cout<<(min_heap.size() > max_heap.size() ? min_heap.top() : max_heap.top())<<",";
		}
	}
}
/*
int main(){
	int arr[] = {2, 7, 4, 9, 1, 5, 8, 3, 6 };
	runningMedian(arr,9);
	return 1;
}*/
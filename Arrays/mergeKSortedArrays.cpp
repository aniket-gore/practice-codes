#include<iostream>
#include<queue>

using namespace std;

// k arrays each of length n
// Time : O(nklog(k)), which is better than O(nklog(nk)) by append all arrays and sort.

typedef struct manode{
	int arr;
	int index;
	int value;
}maNode;

maNode * createNode(int arr, int index, int value){
	maNode *node = (maNode *)malloc(sizeof(maNode));
	node->arr = arr;
	node->index = index;
	node->value = value;
	return node;
}

struct comparenode{
	bool operator()(const maNode *a, const maNode *b){
		return a->value > b->value;
	}
};

void mergeKSortedArrays(int **kArrays, int k, int n){
	priority_queue<maNode *,vector<maNode *>,comparenode> min_heap;
	int *output = (int *)malloc(n * k * sizeof(int));

	// push 0th index of all arrays into min heap
	for(int i=0; i<k; i++){
		min_heap.push(createNode(i,0,kArrays[i][0]));
	}
	int index = 0;
	while(index < n*k){
		output[index] = min_heap.top()->value;

		int newarr = min_heap.top()->arr;
		maNode *newnode;
		// if index in an array has reached max, then assign INT_MAX value to the next node from that array
		if(min_heap.top()->index == n-1){
			newnode = createNode(newarr,INT_MAX,INT_MAX);
		}
		else{
			int newindex = min_heap.top()->index + 1;
			newnode = createNode(newarr,newindex,kArrays[newarr][newindex]);
		}
		min_heap.pop();
		min_heap.push(newnode);
		index++;
	}

	for(int i=0; i<n*k; i++){
		cout<<output[i]<<",";
	}
}
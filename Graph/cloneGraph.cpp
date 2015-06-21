#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

typedef struct graph{
	vector<struct graph*> neighbors;
	int data;
}graphNode;

graphNode * getGraphNode(int data){
	graphNode * node = new graphNode();
	node->data = data;
	return node;
}

graphNode * cloneGraph(graphNode * node){
	if(node == NULL){
		return NULL;
	}
	map<graphNode *,graphNode *> mp;
	queue<graphNode *> levelQ;
	levelQ.push(node);
	// insert the first node -> nodeCopy into the map
	graphNode * nodeCopy = getGraphNode(node->data);
	mp.insert(make_pair(node,nodeCopy));

	while(!levelQ.empty()){
		graphNode *tmp = levelQ.front();
		levelQ.pop();
		for(int i=0; i<tmp->neighbors.size(); i++){
			graphNode *neighbor = tmp->neighbors[i];
			// if neighbor is not present in the map
			if(mp.find(neighbor) == mp.end()){
				// add the neighbor to the map
				graphNode *neighborCopy = getGraphNode(neighbor->data);
				mp.insert(make_pair(neighbor,neighborCopy));
				// add neighborCopy to the its neighbors list
				mp[tmp]->neighbors.push_back(neighborCopy);
				// push the neighbor to the queue, because it is visited for the first time
				levelQ.push(neighbor);
			}
			else{
				// if neighbor is already present in the map, add it to neighbors list of current node
				mp[tmp]->neighbors.push_back(mp[neighbor]);
			}
		}
	}
	return nodeCopy;
}

/* Graph:

		1--------2
	   /  \     /
	  /	   \   /
	 3-------4  
*/
/*
int main(){
	graphNode *node1 = getGraphNode(1);
	graphNode *node2 = getGraphNode(2);
	graphNode *node3 = getGraphNode(3);
	graphNode *node4 = getGraphNode(4);
	node1->neighbors.push_back(node2);
	node1->neighbors.push_back(node3);
	node1->neighbors.push_back(node4);
	node2->neighbors.push_back(node1);
	node2->neighbors.push_back(node4);
	node3->neighbors.push_back(node1);
	node3->neighbors.push_back(node4);
	node4->neighbors.push_back(node1);
	node4->neighbors.push_back(node2);
	node4->neighbors.push_back(node3);
	graphNode *nodeCopy = cloneGraph(node1);
	cout<<"Node 1 :"<<endl;
	for(int i=0; i<nodeCopy->neighbors.size(); i++){
		cout<<nodeCopy->neighbors[i]->data<<endl;
	}
	cout<<"Node 2 :"<<endl;
	for(int i=0; i<nodeCopy->neighbors[0]->neighbors.size(); i++){
		cout<<nodeCopy->neighbors[0]->neighbors[i]->data<<endl;
	}
	return 1;
}*/
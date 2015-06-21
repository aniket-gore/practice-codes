#include "graph.h"

// Time : O(V+E)
void Graph::storeDFSOrder(queue<int> &orderOfDFS){
	bool *visited = new bool[vertices]();

	// call DFSUtil on all vertices separately to consider disjoint graph
	for(int i=0; i<this->vertices; i++){
		if(!visited[i]){
			storeDFSOrderUtil(i, visited, orderOfDFS);
		}
	}
}

void Graph::storeDFSOrderUtil(int v, bool *visited, queue<int> &orderOfDFS){
	orderOfDFS.push(v);
	visited[v] = true;

	list<int>::iterator iter;
	for(iter = adj[v].begin(); iter!=adj[v].end(); iter++){
		if(!visited[*iter]){
			storeDFSOrderUtil(*iter,visited, orderOfDFS);
		}
	}
}
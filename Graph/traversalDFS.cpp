#include "graph.h"

// Time : O(V+E)
void Graph::traversalDFS(){
	bool *visited = new bool[vertices]();

	// call DFSUtil on all vertices separately to consider disjoint graph
	for(int i=0; i<this->vertices; i++){
		if(!visited[i]){
			DFSUtil(i, visited);
		}
	}
}

void Graph::DFSUtil(int v, bool *visited){
	cout<<v<<"\t";
	visited[v] = true;

	list<int>::iterator iter;
	for(iter = adj[v].begin(); iter!=adj[v].end(); iter++){
		if(!visited[*iter]){
			DFSUtil(*iter,visited);
		}
	}
}
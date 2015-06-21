#include<iostream>
#include "graph.h"

using namespace std;
/*
Find all strongly connected components in a graph.
A directed graph is strongly connected if there is a path between all pairs of vertices.( i.e. graph should contain a cycle)
*/

// Reprase the question : Find all cycles in the graph.
// Time = O(V+E)

void Graph::findStronglyConnectedComponents(){
	queue<int> orderOfDFS;
	this->storeDFSOrder(orderOfDFS);

	Graph reverse_graph = this->reverseGraph();

	bool *visited = new bool[this->vertices];
	fill(visited, visited+this->vertices, false);

	while(!orderOfDFS.empty()){
		int v = orderOfDFS.front();
		orderOfDFS.pop();
		if(!visited[v]){
			reverse_graph.DFSUtil(v,visited);
			cout<<endl;
		}
	}
}
/*
int main(){
	Graph g(5);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(1,0);
	g.addEdge(2,1);
	g.addEdge(3,4);
	g.findStronglyConnectedComponents();

	return 1;
}*/
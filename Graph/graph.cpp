#include "graph.h"

Graph::Graph(int vertices){
	this->vertices = vertices;
	this->adj = new list<int>[vertices];
}

void Graph::addEdge(int u, int v){
	this->adj[u].push_back(v);
}

void Graph::printAdjacency(int v){
	list<int>::iterator iter;
	for(iter=adj[v].begin(); iter!=adj[v].end(); iter++){
		cout<<*iter<<"\t";
	}
}
#include<iostream>
#include "graph.h"

using namespace std;

Graph Graph::reverseGraph(){
	Graph g(this->vertices);
	
	list<int>::iterator iter;
	for(int i=0; i<this->vertices; i++){
		for(iter = this->adj[i].begin(); iter != this->adj[i].end(); iter++){
			g.adj[*iter].push_back(i);
		}
	}
	return g;
}
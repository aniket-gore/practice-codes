#include<iostream>
#include<list>
#include<queue>

using namespace std;

// Using adjacency list
class Graph{
private:
	int vertices;
	list<int> *adj;
	void DFSUtil(int v, bool *visited);
	void storeDFSOrderUtil(int v, bool *visited, queue<int> &orderOfDFS);

public:
	Graph(int vertices);
	void addEdge(int u, int v);
	void traversalDFS();
	void printAdjacency(int v);
	void storeDFSOrder(queue<int> &orderOfDFS);
	Graph reverseGraph();
	void findStronglyConnectedComponents();
};
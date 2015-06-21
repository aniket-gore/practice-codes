#include<iostream>
#include<queue>

using namespace std;

/*
Given a snake and ladder board, find the minimum number of dice throws 
required to reach the destination or last cell from source or 1st cell.
*/

// Time = O(N)
// Consider board as a directed graph with number of vertices equal to the number of cells in the board

// node to store which vertex and its distance from starting vertex
struct distancenode{
	int v;
	int distance;
};

// This function returns minimum number of dice throws required to
// Reach last cell from 0'th cell in a snake and ladder game.
// move[] is an array of size N where N is no. of cells on board
// If there is no snake or ladder from cell i, then move[i] is -1
// Otherwise move[i] contains cell to which snake or ladder at i
// takes to.
void snakeAndLadderProblem(int n, int nextvertex[]){
	bool *visited = new bool[n];
	fill(visited, visited+n, false);

	queue<struct distancenode> BFSqueue;
	distancenode node = {0,0};
	visited[0] = true;
	BFSqueue.push(node);

	// BFS
	while(!BFSqueue.empty()){
		node = BFSqueue.front();
		BFSqueue.pop();

		if(node.v == n-1){
			break;
		}
		int v = node.v;
		// check next 6 positions because die can get you to next 6 positions
		for(int i=v+1; i<=v+6 && i<n; i++){
			if(!visited[i]){
				distancenode next;
				next.distance = node.distance + 1;
				visited[i] = true;
				next.v = nextvertex[i] == -1 ? i : nextvertex[i];
				BFSqueue.push(next);
			}
		}
	}
	cout<<endl<<"Min Distance = "<<node.distance<<endl;
}

/*
int main(){
	// -1 indicates there is no  snake or ladder at that vertex
	int board[] = {-1,-1,5,-1,11,-1,-1,-1,-1,-1,-1,-1};
	snakeAndLadderProblem(12,board);
	return 1;
}*/
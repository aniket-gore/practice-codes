#include<iostream>
#include<cmath>

using namespace std;

static int count = 0;
void findVertices(int x, int y, int l, int b){
	cout<<endl<<x<<","<<y+b;
	cout<<endl<<x+l<<","<<y+b;
	cout<<endl<<x+l<<","<<y;
	count += 3;
	cout<<endl<<count;
}

void findPermutationsOfVerticesOfRectangle(int x, int y, int area){
	for(int i=1; i<=sqrt((double)area); i++){
		int l,b;
		if(area%i == 0){
			l = i;
			b = area/i;
			findVertices(x,y,l,b);
			findVertices(x,y,-l,b);
			findVertices(x,y,l,-b);
			findVertices(x,y,-l,-b);
			findVertices(x,y,b,l);
			findVertices(x,y,-b,l);
			findVertices(x,y,b,-l);
			findVertices(x,y,-b,-l);
		}
	}
}
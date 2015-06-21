#include<iostream>

using namespace std;

/*
Triangle:
1
11
121
1331
14641 -> 1, prev*4/1, prev*3/2, prev*2/3, prev*1/4 
...
*/

// Time : O(n^2)
//Space : O(1)
void pascalsTriangle(int levels){
	for(int level=1; level<=levels; level++){
		int number = 1;
		cout<<endl;
		for(int i=1; i<=level; i++){
			cout<<" "<<number;
			number = number * (level -  i) / i;
		}
	}
}
/*
int main(){
	pascalsTriangle(5);
	cout<<endl;
	return 1;
}*/
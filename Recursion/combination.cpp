#include<iostream>

using namespace std;

// Complexity = O(2^n) ??

// Type marker stick: using bits to indicate what's chosen.  The stick can't
// handle more than 32 items, but the idea is there; at worst, use array instead
void combination(int pool, int need, unsigned int answer, int indexinpool){
	static unsigned int one = 1;
	if(need > (pool - indexinpool)){//just to handle last few indices
		return;
	}
	if(need == 0){
		cout<<endl<<"{";
		for(int i=0; i<pool; i++){
			if(answer & (one << i)){
				cout<<i;
			}
		}
		cout<<"}";
		return;
	}
	combination(pool,need - 1,answer | (one << indexinpool),indexinpool + 1);
	combination(pool,need,answer,indexinpool + 1);
}
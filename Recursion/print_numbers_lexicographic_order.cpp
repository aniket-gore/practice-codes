#include<iostream>

using namespace std;

// N = limit,
// k = starting number
void Lexicographic_order(int N, int k) 
{ 
	if (k > N)
	return; 

	for(int i = 0; i<10; i++) 
	{ 
		if (k <= N) 
		{ 
			cout<<k<<endl;	
			
			k *= 10; 
			Lexicographic_order(N, k); 
			k /= 10; 
			k++; 
			if (k%10 == 0) 
				return; 
		} 
	} 
} 
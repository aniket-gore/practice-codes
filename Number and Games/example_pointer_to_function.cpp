#include<iostream>

int addition(int a , int b) {
	return a+b;
}

int subtraction(int a, int b) {
	return a-b;
}

int operation(int a, int b, int (*ptrtofunc)(int,int)) {
	int x;
	x = (*ptrtofunc)(a,b);
	return x;
}


//int main(int argc, char* argv[]) {
//	
//	int (*add)(int,int) = addition;
//	int answer = operation(5,10,add);
//	printf("\naddition =%d",answer);
//	
//	answer = operation(5,10,subtraction);
//	printf("\nsubtraction =%d",answer);
//}


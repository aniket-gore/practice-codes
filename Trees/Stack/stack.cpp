#include<iostream>

using namespace std;

#define SIZE 20

typedef struct mystack{
	int arr[SIZE];
	int top;
}Stack;

void initStack(Stack *s){
	s->top = -1;
}

bool isEmpty(Stack *s){
	return s->top == -1 ? true : false;
}

void push(Stack *s, int value){
	if(s->top != SIZE - 1){
		s->arr[++s->top] = value;
	}
}

int pop(Stack *s){
	if(isEmpty(s)){
		return -1;
	}
	else{
		return s->arr[s->top--];
	}
}

int peek(Stack *s){
	if(isEmpty(s)){
		return -1;
	}
	else{
		return s->arr[s->top];
	}
}
/*
int main(){
	Stack *s = new Stack();
	initStack(s);
	push(s,1);
	cout<<peek(s)<<endl;
	return 1;
}*/
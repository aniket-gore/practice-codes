#include<iostream>
#include<pthread.h>
#include<windows.h>

#define NUMBER 5
using namespace std;

pthread_mutex_t forksMutex[NUMBER];

void *dine(void *i){
	int num = *(int *)i;
	int iterations = 1;

	while(iterations < 2){
		cout<<num<<" is thinking"<<endl;
		Sleep(2);

		cout<<num<<" is hungry"<<endl;
		pthread_mutex_lock(&forksMutex[num]);
		pthread_mutex_lock(&forksMutex[(num+1) % NUMBER]);
		cout<<num<<" is eating"<<endl;
		Sleep(1);
		pthread_mutex_unlock(&forksMutex[num]);
		pthread_mutex_unlock(&forksMutex[(num+1) % NUMBER]);
		cout<<num<<" finished eating!!!"<<endl;
		iterations++;
	}
	pthread_exit(NULL);
	return 0;
}
/*
void main(){
	pthread_t diners[NUMBER];
	int dinerNumber[NUMBER];
	// initialize the mutexes
	for(int i=0; i<NUMBER; i++){
		pthread_mutex_init(&forksMutex[i],NULL);
	}
	// create diners threads
	for(int i=0; i<NUMBER; i++){
		dinerNumber[i] = i;
		int ret = pthread_create(&diners[i],NULL,dine,&dinerNumber[i]);
		if(ret){
			cout<<"Unable to create thread "<<i<<endl;
		}
	}
	// wait till all diners finish
	for(int i=0; i<NUMBER; i++){
		pthread_join(diners[i],NULL);
	}
	pthread_exit(0);
}
*/
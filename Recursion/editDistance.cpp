// Referred
// If memoized, then Time = O(m * n)
// Application: display all the words in a dictionary that are near proximity to a given word\incorrectly spelled word.
//
// Time : O(i * j)
# include <stdio.h>
# include <string.h>
#include<iostream>

using namespace std;

#define DELETE_COST 1
#define INSERT_COST 1
#define CHANGE_COST 1
int min(int x, int y, int z) {
	if (x<=y && x<=z)
	return x;
	if (y<=z && y<=x)
	return y;
	if (z<=x && z<=y)
	return z;
}

int findEditDistance(char* old, int i, char* news, int j) {
	int ch;
	if ((i == -1) && (j == -1))
	return 0;
	if (i == -1)
	return (j+1)*DELETE_COST;
	if (j == -1)
	return (i+1)*INSERT_COST;
	ch = (old[i]==news[j]) ? 0 : CHANGE_COST;
	return min(DELETE_COST + findEditDistance(old, i, news, j-1),
	INSERT_COST + findEditDistance(old, i-1, news, j),
	ch + findEditDistance(old, i-1, news, j-1));
}
/*
void main() {
	char old[10] = "ccat1";
	char new[10] = "bbbat2";
	int distance;
	distance = findEditDistance(old, strlen(old)-1, new, strlen(new)-1);
	printf("Distance : %d\n", distance);
}*/


// Referred
/*
You have k lists of sorted integers. Find the smallest range that includes at least one number from each of the
k lists.
For example,
List 1: [4, 10, 15, 24, 26]
List 2: [0, 9, 12, 20]
List 3: [5, 18, 22, 30]
The smallest range here would be [20, 24] as it contains 24 from list 1, 20 from list 2, and 22 from list 3.
*/
# include <stdio.h>
void swap(int *x, int *y) {
	*x = (*x) + (*y);
	*y = (*x) - (*y);
	*x = (*x) - (*y);
}
void sort(int *heap, int *index) {
	int i, j;
	// sort the heap and maintain index array accordingly
	for (i=0; i<3; i++)
		for (j=0; j<3-i-1; j++) {
			printf("%d, %d, %d\n",index[0],index[1],index[2]);
			if (heap[j] > heap[j+1]) {
				swap(&heap[j], &heap[j+1]);
				swap(&index[j], &index[j+1]);
			}
		}
}

void findRange(int *a, int alen, int *b, int blen, int *c, int clen) {
	int ai=1, bi=1, ci=1, range = 9999;
	int heap[3] = {a[0], b[0], c[0]};
	int index[3] = {1,2,3};
	while (ai<alen && bi<blen && ci<clen) {
		sort(heap, index);
		if (range > (heap[2] - heap[0]))
			range = heap[2] - heap[0];
		switch(index[0]) {
			case 1: {
				heap[0] = a[ai++];
				break;
			}
			case 2: {
				heap[0] = b[bi++];
				break;
			}
			case 3: {
				heap[0] = c[ci++];
				break;
			}
		}
	}
	printf("%d\n", range);
}
/*
void main() {
	int a[5] = {4, 10, 15, 24, 26}, b[4] = {0, 9, 12, 20}, c[4] = {5, 18, 22, 30};
	findRange(a,5,b,4,c,4);
}*/
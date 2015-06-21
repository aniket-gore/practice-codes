#include<iostream>

#define min(a,b) (a<b ? a : b)
#define max(a,b) (a>b ? a : b)

using namespace std;

/*
Given n boxes, stack them up to get max height. Smaller boxes can go on top of larger box (w1 < w2 and d1 < d2).
Of course, you can rotate a box so that any side functions as its base.
It is also allowable to use multiple instances of the same type of box.
VARIATION OF LIS.

Time = O(n^2)
Space = O(n)

*/


typedef struct box{
	int h,w,d;
}Box;

// used for internal qsort function
int compare(const void *a, const void *b){
	return ((*(Box*)b).w * (*(Box*)b).d - (*(Box*)a).w * (*(Box*)a).d);
}

void boxStackingProblem(box boxes[], int quantity){
	Box *rot = new Box[3*quantity];

	int index = -1;
	// find all rotations of all boxes
	for(int i=0; i<quantity; i++){
		// copy box as it is
		rot[++index] = boxes[i];

		// 1st rotation
		rot[++index].h = boxes[i].d;
		rot[index].w = min(boxes[i].w,boxes[i].h);
		rot[index].d = max(boxes[i].w,boxes[i].h);

		// 2st rotation
		rot[++index].h = boxes[i].w;
		rot[index].w = min(boxes[i].d,boxes[i].h);
		rot[index].d = max(boxes[i].d,boxes[i].h);
	}

	quantity *= 3;
	// sort boxes in DESCENDING order based on the AREA i.e. w * d
	qsort(rot,quantity,sizeof(rot[0]),compare);

	int *maxHeight = new int[quantity];
	// initialize output array with individual box heights
	for(int i=0; i<quantity; i++){
		maxHeight[i] = rot[i].h;
	}
	
	//dynamic approach, store the max height for each box 
	for(int i=1; i<quantity; i++){
		for(int j=0; j<i; j++){
			if(rot[j].d > rot[i].d && rot[j].w > rot[i].w && maxHeight[j]+rot[i].h > maxHeight[i]){
				maxHeight[i] = maxHeight[j] + rot[i].h;
			}
		}
	}

	// find max maxHeight
	// max height is not always the last array index in maxHeight, because last box may not always be in the solution
	int output=0;
	for(int i=0; i<quantity; i++){
		output = max(output,maxHeight[i]);
	}
	cout<<endl<<"max height = "<<output<<endl;
}

/*
int main()
{
  Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
  // output= 60  obtained by boxes { {3, 1, 2}, {1, 2, 3}, {6, 4, 5}, {4, 5, 6}, {4, 6, 7}, {32, 10, 12}, {10, 12, 32}}
  int n = sizeof(arr)/sizeof(arr[0]);
  
  boxStackingProblem (arr, n);
 
  return 0;
}*/

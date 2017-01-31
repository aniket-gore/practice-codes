/*
 * Problem: Given an array, find the max difference such that second number is
 * comes after the first
 *
 * Example: Given arr[11,21,10,5,20,15,3,19]
 * Output: 16
 *
 * Time: O(n)
 * */
#include<iostream>
#include<climits>

#define findMin(x,y) (x<y?x:y)
#define findMax(x,y) (x>y?x:y)

using namespace std;

int function(int arr[], int len){
    int minSoFar,max=INT_MIN;
    if(len <= 1){
        return max;
    }
    minSoFar=arr[0];
    for(int i=1; i<len; i++){
        minSoFar = findMin(minSoFar,arr[i]);
        max = findMax(max,arr[i]-minSoFar);
    }
    return max;
}

// int main(){
//     int arr[]={21,30,2,40,20,5,25};
//     cout<<"Max = "<<function(arr,7)<<endl;
//     return 1;
// }

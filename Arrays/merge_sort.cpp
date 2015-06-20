#include <iostream>

using namespace std;

void merge(int*,int,int,int);
void mergesort(int *a, int low, int high)
{
    int pivot;
    if(low<high)
    {
        pivot=(low+high)/2;
        mergesort(a,low,pivot);
        mergesort(a,pivot+1,high);
        merge(a,low,pivot,high);
    }
}
void merge(int *a, int low, int pivot, int high)
{
    int b[100],l,index,h,k;
    l=low;
    index=low;
    h=pivot+1;

    while((l<=pivot)&&(h<=high))
    {
        if(a[l]<=a[h])
        {
            b[index]=a[l];
            l++;
        }
        else
        {
            b[index]=a[h];
            h++;
        }
        index++;
    }
    if(l>pivot)
    {
        for(k=h; k<=high; k++)
        {
            b[index]=a[k];
            index++;
        }
    }
    else
    {
        for(k=l; k<=pivot; k++)
        {
            b[index]=a[k];
            index++;
        }
    }
    for(k=low; k<=high; k++) a[k]=b[k];
}

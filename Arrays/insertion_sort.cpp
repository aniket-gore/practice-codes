

void insertionsort(int a[], int length){
	int temp,j;
	for(int i=1;i<length;i++){
      temp=a[i];
      j=i-1;
      while((temp<a[j])&&(j>=0)){
      a[j+1]=a[j];
          j=j-1;
      }
      a[j+1]=temp;
	}
}
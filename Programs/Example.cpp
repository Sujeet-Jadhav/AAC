#include<stdio.h>

void merge(int *A,int mid,int low,int high)
{
	int i,j,k,B[100];
	i=low;
	j=mid+1;
	k=low;
	while(i<=mid && j<=high){
		if(A[i]<A[j]){
			B[k]=A[i];
			i++;
			k++;
		}
		else{
			B[k]=A[j];
			j++;
			k++;	
		}
	}
	while(i<=mid){
		B[k]=A[i];
		i++;
		k++;
	}
	while(j<=high){
		B[k]=A[j];
		j++;
		k++;
	}
	int x;
	for(x=low;x<=high;x++)
		A[x]=B[x];
}

void printArray(int *arr,int n){
	int i;
	for(i=0;i<n;i++)
		printf(" %d",arr[i]);
	printf("\n");
}

void mergeSort(int *A,int low,int high){
	if(low<high){
		int mid = (low+high)/2;
		mergeSort(A,low,mid);
		mergeSort(A,mid+1,high);
		merge(A,mid,low,high);
	}
}

int main()
{
    int A[] = {9, 1, 4, 14, 4, 15, 6,34,78,3,45,76};
    int n = sizeof(A)/sizeof(int);
    printArray(A, n);
    mergeSort(A,0,n);
    printArray(A,n);
}

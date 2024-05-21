#include<stdio.h>
#include<time.h>
// Time complexity: O(n log n)
// O(n2) if array is sorted

void printArray(int A[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// partition the array and return index of pivot
int partition(int arr[],int low,int high){
    int pivot = arr[high]; // last element as pivot
    int i = low - 1;  // index of smallest element
    int j;
    for(j = low; j < high; j++){
    	if(arr[j] <= pivot){
    		i++;
			// swaping
    		int temp=arr[i];
    		arr[i]=arr[j];
    		arr[j]=temp;
		}
	}
	// swap pivot
	int temp2 = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp2;
	return (i + 1);
}


int QuickSort(int arr[], int low,int high){
	if(low < high){
    	int pivotIndex=partition(arr,low,high);
    	QuickSort(arr,low,pivotIndex - 1);
    	QuickSort(arr,pivotIndex + 1,high);
	}
}




int main(){
	clock_t start = clock();
    int arr[] = {2,3,5,7,3,23,6,7,3};
    int len = sizeof(arr)/sizeof(int);
	printf("Original array:\n");
    printArray(arr,len);
    
    QuickSort(arr, 0, len - 1);
    
    printf("Sorted array:\n");
    printArray(arr,len);
    
	clock_t end=clock();
	double execution=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nExecution time %f",execution);
	return 0;
    }


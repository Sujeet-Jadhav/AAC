#include<stdio.h>
#include<time.h>
// Time complexity: O(n k)
int getMax(int *arr, int n){
	int max = arr[0];
	int i;
	for(i = 1; i < n; i++)
		if(arr[i] > max)
			max = arr[i];
	return max;
}

void countingSort(int *arr, int n, int exp){
	int range = 10; // Radix of deciaml system (0-9)
	
	int output[n];
	int count[range] = {0};
	
	// Store count of occurences in count[]
	int i;
	for(i = 0; i < n; i++)
		count[(arr[i] / exp) % range]++;
		
	// Change count, contains the actual position of this digit
	for(i = 1; i < range; i++)
		count[i] += count[i - 1];
		
	// Build the output array
	for(i = n - 1; i >= 0; i--){
		output[count[(arr[i] / exp) % range] - 1] = arr[i];
		count[arr[i] / exp % range]--;
	}
	
	// Copy output to arr
	for(i = 0; i < n; i++)
		arr[i] = output[i];
}

void printArray(int A[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void radixSort(int *arr, int n){
	// max no to determine no of digits
	int max = getMax(arr, n);
	
	// Count sort for every digit
	int exp;
	for(exp = 1; max/exp > 0; exp *= 10)
		countingSort(arr, n, exp); 
}

int main(){
	clock_t start = clock();
    int arr[] = {2,13,52,7,30,23,6,77,3};
    int len = sizeof(arr)/sizeof(int);
	printf("Original array:\n");
    printArray(arr, len);
    
    radixSort(arr, len);
    
    printf("Sorted array:\n");
    printArray(arr,len);
    
	clock_t end=clock();
	double execution=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nExecution time %f",execution);
	return 0;
}

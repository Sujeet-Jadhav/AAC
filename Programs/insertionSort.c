#include <stdio.h>
#include <time.h>
// Time complexity: O(n2)
// Insert an element from unsorted array to its correct position in sorted array

// Function to print an array
void printArray(int arr[], int size) {
	int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n) {
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j --;
        }
        arr[j + 1] = key;
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {29,40,31,41,2,3,3,15,12};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);
	clock_t start,end;
	start = clock();
    insertionSort(arr, n);
	end = clock();
    printf("Sorted array: ");
    printArray(arr, n);
	double time_taken=(double)(end-start)/CLOCKS_PER_SEC;
	printf("Time:%f",time_taken);
    return 0;
}


#include <stdio.h>
// Time complexity: O(n)
// Function to print an array
void printArray(int *arr, int size) {
	int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform Counting Sort on an array
void countingSort(int arr[], int n) {
    // Find the maximum value in the array
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    // Max value
    printf("Max:%d\n",max);

    // Create a count array to store the count of each element
    int count[max + 1];
    for (i = 0; i <= max; i++) {
        count[i] = 0;
    }
    
    // Count Array
    printf("Count Array:");
    printArray(count,max+1);

    // Count the occurrences of each element
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    // Count Array
    printf("Count Array:");
    printArray(count,max+1);

    // Update the count array to store the actual position of each element
    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store the sorted result
    int output[n];

    // Build the sorted array
    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back to the original array
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Example usage
int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    countingSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}


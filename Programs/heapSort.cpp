#include<stdio.h>
// Time complexity: O(n log n)
// The maximum value is continually removed from the remaining unsorted elements.
// Heapify a subtree rooted at node i

void heapify(int *arr,int n,int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    // If left child is larger than root
    if(left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than root
    if(right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not root
    if(largest != i){
        // Swap the root with the largest element
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }      
}

void heapSort(int *arr, int n){
    int i,temp;
    // Build the max heap
    for(i = n / 2 ; i >=0; i--)
        heapify(arr, n, i);

    // Extract elements one by one from heap
    for(i = n - 1; i > 0; i--){
        // Swap the current root with last element
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call heapify on the reduced heap
        heapify(arr, i, 0);

    }
}

void printArray(int *arr,int size){
    int i;
    for(i = 0; i < size; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main(){
    int arr[]={12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original Array:\n");
    printArray(arr,n);

    heapSort(arr,n);
    printf("Sorted Array:\n");
    printArray(arr,n);

    return 0;
}

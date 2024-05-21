#include<stdio.h>
// Time complexity: O(n2)

int binary(int arr[], int low, int high, int x){
	int mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] == x)
            return mid;
        if(arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int x;
    // sorted array must
    int arr[] = {1,5,8,12,20,45,53};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    printf("Enter the value to search: ");
    scanf("%d", &x);
    int p = binary(arr, 0, n - 1, x);
    
    if(p != -1)
        printf("Found at position: %d\n", p);
    else
        printf("%d not found\n", x);

    return 0;
}


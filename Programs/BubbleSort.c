#include<stdio.h>
#include<time.h>
// Time complexity: O(n2)

int BubbleSort(int *arr, int len){
    int i,j;
    
    for(i = 0; i < len - 1; i++){	
    	for(j = 0; j < len - i - 1; j++){    
    		if(arr[j] > arr[j+1]){
				// Swaping
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
			} 
		}
	}
}


int main(){
    int i;
    int arr[] = {30,53,13,3,22,67,2,89,98,45,2,7,9,1,78,34,67,32,89};
    int len = sizeof(arr)/sizeof(arr[0]);
    clock_t start = clock();
    BubbleSort(arr,len);
    clock_t end = clock();
    for(i = 0; i < len; i++){
        printf("%d ",arr[i]);
   	}
    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("\nTime:%f sec",time_taken);
    return 0;
}

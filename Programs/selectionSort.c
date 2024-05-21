#include <stdio.h>
// Time complexity: O(n2)
// Find the minimum element in unsorted array and swap it with element at begining of unsorted list

void selectionSort(int array[], int size) {

	int i,j,temp;
	for(i = 0; i < size - 1; i++){
  		int min=i;
  		// Iterate through the unsorted part of the array
  		for(j = i + 1; j < size; j++){
    		if(array[j] < array[min]){
      			min = j;
    		}
  		}
  		// swaping
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}

}


void printArray(int array[], int size) {
	int i;
  	for (i = 0; i < size; ++i) {
		printf("%d  ", array[i]);
  	}
  	printf("\n");
}


int main() {
  int data[] = {5,3,76,98,2,3,66,97};
  int size = sizeof(data) / sizeof(data[0]);
  printArray(data, size);
  selectionSort(data, size);
  printf("Sorted array :\n");
  printArray(data, size);

}

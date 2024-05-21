#include<stdio.h>

int main(){

int arr[]={22,5,25,1,4,7,88,5};
int len=sizeof(arr)/4;
//printf("%d",len);
printf("before insertion sort :");
for(int i=0; i<len;i++){

	printf("%d, ",arr[i]);
}


for (int i =1; i<len;i++){
	int item = arr[i];
	int j= i-1;
	while( arr[j]>item && j>=0){      
		arr[j+1]=arr[j];
		j=j-1;
	}	
	arr[j+1]=item;
}

printf("After sorting \n ");
for(int i=0;i<len;i++){
	
printf("%d, ",arr[i]);
	
}

return 0;

}

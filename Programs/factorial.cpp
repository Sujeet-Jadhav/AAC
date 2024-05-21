#include<stdio.h>
int main(){
	int num=0;
	printf("Enter number for Factorial: ");
	scanf("%d",&num);
	
	int fact=1;
	for(int i=1; i<=num; i++){
	fact=fact*i;
	
	}
	printf("factorial is %d ",fact);
	return 0;
}

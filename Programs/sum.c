#include<stdio.h>

int sum(int a,int b){

    int sum=0;
    sum=a+b;
    return sum;
}
int main(){
	int num1,num2;
    printf("Enter the number for addition: ");
    scanf("%d",&num1);
    scanf("%d",&num2);
    printf("the Sum of two number is %d",sum(num1,num2));
	return 0;
}

#include<stdio.h>
#include<string.h>
#include<time.h>
char palindrom(int num){
	int n=num;
	int p = 0;
    int temp;
     time_t seconds;
     time(&seconds);
	while(n>0){
		temp=n%10;
		p=p*10+temp;
		n=n/10;
	}

	if(p==num){
		printf("This Number is palindrom");
	}
	else{
		printf("Not Palindrom");
	}
	 printf("\n Time: %ld",seconds);
}
int  main(){
	time_t start;
	start=time(&start);
    int num;
	printf("Enter a number:");
    scanf("%d",&num);
    palindrom(num);
    printf("\n Time: %d",start);
    return 0;
}

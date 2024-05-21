#include<stdio.h>

int main(){

        int num;
        printf("Enter a number:");
        scanf("%d",&num);
        
        int i,sum=0;

        for(i=1;i<num;i++){
            if(num%i==0){
                sum=sum+i;
            }
        }

    if(num==sum){
        printf("%d number is perfect",num);
    }
    else{
        printf("%d is not a perfect number",num);
    }
    return 0;

}

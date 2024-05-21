#include<stdio.h>
#include<math.h>
int Sum(){
    int num1,num2, num3,sum=0;
    printf("enter 1st digit for finding sum :");
    scanf("%d",&num1);    
    printf("enter 2nd digit for finding sum :");
    scanf("%d",&num2);
    printf("enter 3rd digit for finding sum :");
    scanf("%d",&num3);
    sum=num1+num2+num3;
    return sum;
}

int factorial(){
   int num,facto=1,i;
   printf("Enter number for factorial :");
   scanf("%d",&num);
   for( i= 1 ; i<= num; i++)
   {
    facto=facto*i;
   } 
   return facto;
}


void fibonacci(){
    int num, num1=0,num2=1 ,next = num1+num2,i;
    printf("Enter number for printing fibonachi series : ");
    scanf("%d",&num);
    if(num<=0){
    	printf("Please Enter +ve Value");
    	return;
    }
    printf("%d %d ",num1,num2);
    for(i= 2; i<=num;i++){
        printf("%d ",next);
        num1 = num2;
        num2=next;
        next=num1+num2;
    }
}

int power(){
	
	long base,p,i,ans=1;
	printf("Enter Base:");
    scanf("%d",&base);
    printf("Enter power: ");
    scanf("%d",&p);
    for(i=1;i<=p;i++){
    	ans*=base;
	}
	return ans;
//    return pow(base,p);
    
}
int main(){

    int choice;
    int ans;
    printf("enter choice: \n 1 for sum:\n 2 for power \n 3 for factorial \n 4 for fibonacci \n");
    scanf("%d",&choice);

    switch (choice){
        case 1:
            ans= Sum();
            printf("the sum of three number is %d",ans);
            break;
    
    
        case 2:
            ans = power();
            printf("power is: %d",ans);
            break;

          case 3:
            ans = factorial();
            printf("factorial is  %d",ans);
            break;
            
         case 4:
            fibonacci();
			break;
    
    }

}

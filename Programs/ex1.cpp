#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
int n=9;
if(n<10 && n>0){
        if(n==1) printf("one");
        else if(n==2) printf("two");
        else if(n==3) printf("thre");
        else if(n==4) printf("four");
        else if(n==5) printf("five");
        else if(n==6) printf("six");
        else if(n==7) printf("seven");
        else if(n==8) printf("eight");
        else printf("nine");
    }
    if(n>9)
        printf("Greater than 9");
        
    return 0;
    
}

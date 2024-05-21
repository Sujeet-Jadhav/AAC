#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char ch;
    char s[10];
    char sen[50];
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    scanf("%c",&ch);  
    printf("%c\n",ch);
    scanf("%s",s);
    printf("%s\n",s);
    scanf("%[^\n]%*c",sen);
    printf("%s",sen);
    
    return 0;
}


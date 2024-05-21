#include <stdio.h>
#include <time.h>
// Time complexity: O(2n)
void towerOfHanoi(int n,char from,char to,char aux){
	if(n==1){
		printf("\n Move Disk 1 from Rod %c to Rod %c",from,to);
		return;
	}
	towerOfHanoi(n-1,from,aux,to);
	printf("\n Move Disk %d from Rod %c to Rod %c",n,from,to);
	towerOfHanoi(n-1,aux,to,from);
}

int main(){
	int n;
	printf("Enter no of disks:");
	scanf("%d",&n);
	clock_t t;
	t = clock();
	//towerOfHanoi(disks,source,destination,aux)
	towerOfHanoi(n,'A','C','B');
	t=clock()-t;
	double time_taken=double(t)/CLOCKS_PER_SEC;
	printf("\nTime:%f sec",time_taken);
	return 0;
}

#include<stdio.h>
int main(){
	int n;
	printf("Enter the number of rows");
	scanf("%d",&n);
	if(n<=0){
		printf("Invalid Input");
	}
	for(int i = 1;i<=n;i++){
		for(int s = 1;s<=n-i;s++)
			printf(" ");
		for(int j =i;j>=1;j--)
		    printf("%d",j);
		printf("\n");
		
		
	}
}

#include<stdio.h>
int main(){
	int i,j,n,s;
	printf("Enter the number of rows");
	scanf("%d",&n);
	for(i = n;i>=1;i--){
		for(s = 1;s<=n-i;s++){
			printf(" ");
		}
		for(j = 1;j<=i;j++){
			printf("*");
		}
	printf("\n");
	}
}

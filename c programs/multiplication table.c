#include<stdio.h>
int main(){
	int i,m,n;
	printf("Enter the number for multiplication\n");
	scanf("%d",&m);
	printf("Enter the times for multiplication\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("%d*%d = %d\n",i,m,i*m);
		
	}
	
}

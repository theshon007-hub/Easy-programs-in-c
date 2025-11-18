#include<stdio.h>
int main(){
	int n,i,a = 0,b = 1,next;
	printf("Enter the number");
	scanf("%d",&n);
	for( i = 1;i<=n;i++){
		printf("%d\n",a);
		next = a+b;
		a = b;
		b = next;
	}
}

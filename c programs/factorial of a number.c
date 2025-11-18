#include<stdio.h>
int main()
{
	int n,fact = 1,sum = 0;
	printf("Enter the number");
	scanf("%d",&n);
	while (n>0){
	fact = fact*n+sum;
	n--;
}
printf("factorial = %d",fact);
}


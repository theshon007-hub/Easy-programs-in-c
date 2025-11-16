#include<stdio.h>
int main()
{
	int a,b,c;
	printf("Enter two numbers\n");
	scanf("%d%d",&a,&b);
	c = a;
	a = b;
	b = c;
	printf("The swapped value for a=%d,b = %d\n",a,b);
	a = a+b;
	b = a-b;
	a = a-b;
	printf("The swapped value for a =%d ,b = %d",a,b);
	
}


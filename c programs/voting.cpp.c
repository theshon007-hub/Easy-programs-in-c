#include<stdio.h>
int main()
{
	int age;
	printf("Enter your age");
	scanf("%d",&age);
	if( age>=18)
	printf("The person is eligible to vote");
	else
	printf("The person will vote in %d years",18-age);
}

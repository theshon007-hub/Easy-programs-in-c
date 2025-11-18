#include<stdio.h>
#include<math.h>
int main()
{
	float n,square,cube;
	printf("Enter the number\n");
	scanf("%f",&n);
	square = pow(n,2);
	cube = pow(n,3);
	printf("The square of the given number is %f\n",square);
	printf("The cube of the given number is %f\n",cube);
}

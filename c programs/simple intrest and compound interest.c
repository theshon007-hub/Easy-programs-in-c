#include<stdio.h>
#include<math.h>
int main()
{
	float p,r,t,si,ci;
	printf("Enter the value for principal,rate,time\n");
	scanf("%f%f%f",&p,&r,&t);
	si = p*r*t/100;
	printf("The simple intrest amount is si = %f\n",si);
	ci = p*pow((1+r/100),t)-p;
	printf("The compound intrest is ci =%f",ci);
	
}

#include<stdio.h>
int main(){
	int j,a,b,i,isprime;
	printf("Enter the number a\n");
	scanf("%d",&a);
	printf("Enter the number b\n");
	scanf("%d",&b);
	printf("Prime numbers between %d and %d are:\n",a,b);
	for(i = a;i<=b;i++)
	{
		if(i<2)
	        continue;
	    isprime = 1;
	    for(j = 2;j<=i/2;j++){
	    	if (i%j==0){
	    		isprime = 0;
	    		break;
			}
		}
	    if(isprime)
	    printf("%d is prime\n",i);
	}
}

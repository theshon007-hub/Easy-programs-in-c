#include<stdio.h>
int main(){
	int rem,sum = 0,n,temp,i,fact = 1;
	printf("Enter a number");
	scanf("%d",&n);
	temp = n;
	while(temp>0){
		rem = temp%10;
		for( i = 1;i<=rem;i++){
			fact*=i;
		}
	    sum+=fact;
	    temp/=10;
	}
	if(sum == n)
	printf("The given number %d is a strong number ",n);
	else
	printf("The given number %d is not a strong number",n);
	
}

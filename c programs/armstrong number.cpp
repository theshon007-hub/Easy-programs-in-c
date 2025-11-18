#include<stdio.h>
#include<math.h>
int main()
{
	int n,original,sum=0,digit,temp,count=0;
	printf("Enter the number");
	scanf("%d",&n);
	original =n;
	temp =n;
	while(temp!=0){
		temp/=10;
		count++;
	}
	temp = n;
	while(temp>0){
		digit = temp%10;
		sum = sum+pow(digit,count);
		temp/=10;
	}
	if(original == sum)
	printf("%d is a amstrong number",original);
	else
	printf("%d is not an amstrong number",original);
}

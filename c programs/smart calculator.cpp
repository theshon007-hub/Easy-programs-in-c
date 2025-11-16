#include<stdio.h>
int main()
{
	int choice;
	float a,b;
	printf("Enter the choice:\n");
	printf("1.Addition\t2.Subtraction\t3.Multiplication\t4.Division\t5.Modulo Division\n");
	scanf("%d",&choice);
	printf("Enter the value of two numbers\n");
	scanf("%f%f",&a,&b);
	switch(choice){
		case 1:
			printf("The addition of two numbers are %.2f\n",a+b);
			break;
		case 2:
			printf("The subtraction of two numbers are %.2f\n",a-b);
			break;
		case 3:
			printf("The multiplication of two numbers is %.2f\n",a*b);
			break;
		case 4:
			if(b!=0)
			    printf("The division of two numbers is %.2f\n ",a/b);
			else
			    printf("Invalid choice");
			    break;
		case 5:
			printf("The modulo division is %.2f\n",int(a)%int(b));
			break;
		defaut:
			printf("Invalid choice!\n");
	}
	return 0;
	
}

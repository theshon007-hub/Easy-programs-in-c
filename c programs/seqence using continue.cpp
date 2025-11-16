#include<stdio.h>
int main()
{
	int P,Q,R;
	printf("Enter the value of P,Q,R");
	scanf("%d%d%d",&P,&Q,&R);
	printf("Numbers are = ");
	for(int i=P;i<=Q;i++){
	int num = i;
	int flag = 0;
	while(num!=0){
		if(num%10==R)
		flag = 1;
		break;
	    num/=10;
	}
    if (flag == 1)
	    continue;
	    printf("%d\n",i);
}
}

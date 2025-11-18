#include<stdio.h>
int main(){
	int a[10][10],b[10][10],m[10][10],r1,c1,r2,c2;
	printf("Enter the rows and columns for matrix A\n");
	scanf("%d%d",&r1,&c1);
	printf("Enter the rows and columns for matrix B\n");
	scanf("%d%d",&r2,&c2);
	if(c1!=r2){
		printf("Matrix multiplication is not possible\n");
	}
	printf("Enter the first matrix\n");
	for(int i = 0;i<r1;i++){
		for(int j = 0;j<c1;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter the second matrix\n");
	for(int i = 0;i<r2;i++){
		for(int j = 0;j<c2;j++){
			scanf("%d",&b[i][j]);
		}
	}
	for(int i =0;i<r1;i++){
		for(int j =0;j<c2;j++){
			m[i][j] = 0;
			for(int k = 0;k<c1;k++){
				m[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	printf("The product of multiplication is\n");
	for(int i =0;i<r1;i++){
		for(int j = 0;j<c2;j++){
			printf("%d",m[i][j]);
		printf("\n");
		}
	}
}

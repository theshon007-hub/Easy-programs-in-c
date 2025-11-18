#include<stdio.h>
int main(){
	int n,i;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements in array\n");
	for(i = 0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("You Entered\n");
	for(i = n-1;i>=0;i--){
		printf("%d ",arr[i]);
	}
	
	
}

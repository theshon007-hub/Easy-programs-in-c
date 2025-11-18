#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of elements in an array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("You entered: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#define     MAX 50                      // Maximum size of array
void printArray( int a[], int num ) {  // Display elements
    for (int i = 0; i < num; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main() {
    int arr[MAX], n, i, j;
    scanf("%d", &n);              // Input size of working array
    if (n<=0) {
            printf("ERROR: Empty list\n");
            exit(EXIT_FAILURE);
    }
    int t,c=0,f;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Pass 0: ");
    printArray(arr,n);
    for(i=1;i<n;i++)
    {
        f=0;
        for(j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                f=1;
            }
        }
        printf("Pass %d: ",i);
        printArray(arr,n);
        if(f==0)
            break;
    }
    printf("Sorted: ");
    printArray( arr, n );
    return 0;
}

#include    <stdio.h>
#include    <stdlib.h>
#define     MAX 20                      // Maximum array size
void inputArray(int arr[], int len) {   // Input array elements
    int i;
    for (i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
}
int search(int arr[],int n,int val)
{
    for(int i=0;i<n;i++)
    {
        printf("Pass %d: Comparing %d with %d\n",i,arr[i],val);
        if(arr[i]==val)
            return i;
    }
    return -1;
}
int main() {
    int arr[MAX], n, val, pos;
    scanf("%d", &n);                    // Input number of elements
    if (n<=0) {
            printf("ERROR: Empty list\n");
            exit(EXIT_FAILURE);
    }
    inputArray( arr, n );             // Input array elements
    scanf("%d", &val);                // Input val
    pos = search(arr, n, val); // Sequential Search and print passes
    if (pos != -1)
        printf("Position of %d: %d\n", val, pos);
    else
        printf("All checked: %d not found\n", val);
    return 0;
}

//Name: Md Sameer
//Roll No.: 13000119114
// C program to implement recursive Binary Search using Merge Sort

#include <stdio.h>

// A recursive binary search function. It returns
// location of x in given array arr[l..r] if key is present,
// otherwise will return -1

void printArray(int A[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void merge(int arr[], int l, int m, int r, int* ops){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    /* create temp arrays */
    int L[n1], R[n2];
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2){
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
        (*ops)++;
    }
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        (*ops)++;
    }
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        (*ops)++;
    }
}
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r, int* ops)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
        // Sort first and second halves
        mergeSort(arr, l, m,&(*ops));
        mergeSort(arr, m + 1, r,&(*ops));
        merge(arr, l, m, r,&(*ops));
    }
}

int binarySearch(int arr[], int l, int r, int x,int* bin_ops){
    if (r >= l) {
        int mid = l + (r - l) / 2;
        (*bin_ops)++;
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x,bin_ops);
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x, bin_ops);
    }
    // We reach here when element is not
    // present in array
    return -1;
}

int main(){
    int arr[] = {12, 11, 13, 5, 43, 6, 7, 85, 27};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is:  ");
    printArray(arr, arr_size);
    int bin_ops=0;
    mergeSort(arr, 0, arr_size - 1, &bin_ops);
    printf("\nSorted array is: ");
    printArray(arr, arr_size);
    printf("\n");
    bin_ops=0;
    int x = 12;// for mid element test
    int result = binarySearch(arr, 0, arr_size - 1, x,&bin_ops);
    if (result == -1)
        printf("%d is not present in array\n",x);
    else
        printf("%d is present in the array\n",x);
    printf("No. of ops in binary search: %d\n",bin_ops);
    printf("\n");
    bin_ops=0;
    x = 43;//for left element test
    result = binarySearch(arr, 0, arr_size - 1, x,&bin_ops);
    if (result == -1)
        printf("%d is not present in array\n",x);
    else
        printf("%d is present in the array\n",x);
    printf("No. of ops in binary search: %d\n",bin_ops);
    printf("\n");
    bin_ops=0;
    x = 11;//for left element test
    result = binarySearch(arr, 0, arr_size - 1, x,&bin_ops);
    if (result == -1) 
        printf("%d is not present in array\n",x);
    else
        printf("%d is present in the array\n",x);
    printf("No. of ops in binary search: %d\n",bin_ops);
    printf("\n");
    bin_ops=0;
    x = 44;//for not in array test
    result = binarySearch(arr, 0, arr_size - 1, x,&bin_ops);
    if (result == -1)
        printf("%d is not present in array\n",x);
    else
        printf("%d is present in the array\n",x);
    printf("No. of ops in binary search: %d\n",bin_ops);
    return 0;
}
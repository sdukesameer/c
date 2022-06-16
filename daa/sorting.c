//Name: Md Sameer
//Roll No.: 13000119114
// C program for Merge Sort and Quick Sort
#include <stdio.h>
#include <stdlib.h>

//Function that swaps two elements
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

/* Function to prints all elements in the array */
void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
        printf("%d ",arr[i]);
    printf("\n\n");
}

// "Functions for Quick Sort"
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */

int partition (int arr[], int low, int high, int* ops){
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
    for (int j = low; j <= high - 1; j++){
        // If current element is smaller than the pivot
        //(*ops)=(*ops)+3;
        if (arr[j] < pivot){
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
            (*ops)=(*ops)+3;
        }
    }
    swap(&arr[i + 1], &arr[high]);
    (*ops)=(*ops)+3;
    return (i + 1);
}

/* The function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high,int* ops){
    if (low < high){
        //(*ops)++;
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high,ops);
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1,ops);
        quickSort(arr, pi + 1, high,ops);
    }
}

// Functions for Merge Sort
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
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
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
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
void mergeSort(int arr[], int l, int r, int* ops){
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

/* Driver code */
int main(){
    int arr_1[] = {6,87,2,34,1,54,34,56};
    int arr_1_copy[] = {6,87,2,34,1,54,34,56};
    int arr_size_1 = sizeof(arr_1)/sizeof(arr_1[0]);

    int arr_2[] = {105,5,678,345};
    int arr_2_copy[] = {105,5,678,345};
    int arr_size_2 = sizeof(arr_2)/sizeof(arr_2[0]);

    int arr_3[] = {98,45,65,89,23,78,56,76,13,37,88,68,97,53,75,82};
    int arr_3_copy[] = {98,45,65,89,23,78,56,76,13,37,88,68,97,53,75,82};
    int arr_size_3 = sizeof(arr_3)/sizeof(arr_3[0]);

    int arr_4[] = {45,56,67,34,54,96,33,66,40,23,21,35,53,55};
    int arr_4_copy[] = {45,56,67,34,54,96,33,66,40,23,21,35,53,55};
    int arr_size_4 = sizeof(arr_4)/sizeof(arr_4[0]);

    int arr_5[] = {12,14,16,18,20,22,24,26};
    int arr_5_copy[] = {12,14,16,18,20,22,24,26};
    int arr_size_5 = sizeof(arr_5)/sizeof(arr_5[0]);

    int ops_merge_1=0;
    int ops_quick_1=0;
    int ops_merge_2=0;
    int ops_quick_2=0;
    int ops_merge_3=0;
    int ops_quick_3=0;
    int ops_merge_4=0;
    int ops_quick_4=0;
    int ops_merge_5=0;
    int ops_quick_5=0;

    printf("Input Array \n");
    printArray(arr_1, arr_size_1);
    mergeSort(arr_1, 0, arr_size_1 - 1,&ops_merge_1);
    quickSort(arr_1_copy,0, arr_size_1-1, &ops_quick_1);
    printf("\n\nOutput Array Merge \n");
    printArray(arr_1, arr_size_1);
    printf("\n\nOutput Array Quick\n");
    printArray(arr_1_copy, arr_size_1);
    printf("\n\nNumber of Merge ops %d",ops_merge_1);
    printf("\n\nNumber of Quick ops %d",ops_quick_1);
    printf("\n\n****\n\n");

    printf("Input Array \n");
    printArray(arr_2, arr_size_2);
    mergeSort(arr_2, 0, arr_size_2 - 1,&ops_merge_2);
    quickSort(arr_2_copy,0, arr_size_2-1, &ops_quick_2);
    printf("\n\nOutput Array Merge \n");
    printArray(arr_2, arr_size_2);
    printf("\n\nOutput Array Quick\n");
    printArray(arr_2_copy, arr_size_2);
    printf("\n\nNumber of Merge ops %d",ops_merge_2);
    printf("\n\nNumber of Quick ops %d",ops_quick_2);
    printf("\n\n****\n\n");

    printf("Input Array \n");
    printArray(arr_3, arr_size_3);
    mergeSort(arr_3, 0, arr_size_3 - 1,&ops_merge_3);
    quickSort(arr_3_copy,0, arr_size_3-1, &ops_quick_3);
    printf("\n\nOutput Array Merge \n");
    printArray(arr_3, arr_size_3);
    printf("\n\nOutput Array Quick\n");
    printArray(arr_3_copy, arr_size_3);
    printf("\n\nNumber of Merge ops %d",ops_merge_3);
    printf("\n\nNumber of Quick ops %d",ops_quick_3);
    printf("\n\n****\n\n");

    printf("Input Array \n");
    printArray(arr_4, arr_size_4);
    mergeSort(arr_4, 0, arr_size_4 - 1,&ops_merge_4);
    quickSort(arr_4_copy,0, arr_size_4-1, &ops_quick_4);
    printf("\n\nOutput Array Merge \n");
    printArray(arr_4, arr_size_4);
    printf("\n\nOutput Array Quick\n");
    printArray(arr_4_copy, arr_size_4);
    printf("\n\nNumber of Merge ops %d",ops_merge_4);
    printf("\n\nNumber of Quick ops %d",ops_quick_4);
    printf("\n\n****\n\n");

    printf("Input Array \n");
    printArray(arr_5, arr_size_5);
    mergeSort(arr_5, 0, arr_size_5 - 1,&ops_merge_5);
    quickSort(arr_5_copy,0, arr_size_5-1, &ops_quick_5);
    printf("\n\nOutput Array Merge \n");
    printArray(arr_5, arr_size_5);
    printf("\n\nOutput Array Quick\n");
    printArray(arr_5_copy, arr_size_5);
    printf("\n\nNumber of Merge ops %d",ops_merge_5);
    printf("\n\nNumber of Quick ops %d",ops_quick_5);
    return 0;
}
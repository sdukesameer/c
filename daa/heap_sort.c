#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int n, int i, int *ops){
    int largest=i;
    int l=(2*i)+1;
    int r=(2*i)+2;
    while(l<n && arr[l]>arr[largest])
        largest=l;
    while(r<n && arr[r]>arr[largest])
        largest=r;
    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        (*ops)=(*ops)+3;
        heapify(arr,n,largest,ops);
    }
}

void heapSort(int arr[], int n, int *ops){
    int i;
    for(i=n/2-1;i>=0;i--)
        heapify(arr,n,i,ops);
    for(i=n-1;i>0;i--){
        swap(&arr[0],&arr[i]);
        (*ops)=(*ops)+3;
        heapify(arr,i,0,ops);
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n){
    for (int i = 0; i < n; ++i)
        printf("%d ",arr[i]);
    printf("\n");
}

// Driver code
int main(){
    int arr1[] = {98,76,23,43,45,76,88,93,56,12,22,54,74,85,27,66};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int ops1=0;

    int arr2[] = {10,45,34,12};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int ops2=0;

    int arr3[] = {13,12,45,67,34,24,32,11,5,6,21,25,35,87,39,29};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int ops3=0;

    int arr4[] = {14,15,18,20,34,45,57,58};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int ops4=0;

    int arr5[] = {76,65,54,45,43,32,23,12};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    int ops5=0;

    printf("\n\nInput array is \n");
    printArray(arr1, n1);
    heapSort(arr1, n1, &ops1);
    printf("********");
    printf("Sorted array is \n");
    printArray(arr1, n1);
    printf("\nNumber of ops: %d",ops1);

    printf("\n\nInput array is \n");
    printArray(arr2, n2);
    heapSort(arr2, n2, &ops2);
    printf("********");
    printf("Sorted array is \n");
    printArray(arr2, n2);
    printf("\nNumber of ops: %d",ops2);

    printf("\n\nInput array is \n");
    printArray(arr3, n3);
    heapSort(arr3, n3, &ops3);
    printf("********");
    printf("Sorted array is \n");
    printArray(arr3, n3);
    printf("\nNumber of ops: %d",ops3);

    printf("\n\nInput array is \n");
    printArray(arr4, n4);
    heapSort(arr4, n4, &ops4);
    printf("********");
    printf("Sorted array is \n");
    printArray(arr4, n4);
    printf("\nNumber of ops: %d",ops4);

    printf("\n\nInput array is \n");
    printArray(arr5, n5);
    heapSort(arr5, n5, &ops5);
    printf("********");
    printf("Sorted array is \n");
    printArray(arr5, n5);
    printf("\nNumber of ops: %d",ops5);
}
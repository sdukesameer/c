#include <stdio.h>
#include <stdlib.h>
void inputArray(int arr[], int len){   //Function to input elements in array
    for (int i = 0; i < len; i++)
        scanf("%d", &arr[i]);
}
void printArray(int arr[], int len){   //Function to display elements in current array
    for (int i = 0; i < len; i++)
            printf("%d ", arr[i]);
    printf("\n");
}
void selectionSort(int arr[], int len){ //Function for selection sorting
    int min,i,j,t;
    for(i=0;i<len-1;i++)
    {
        min=i;   //initially min is assigned to i
        for(j=i+1;j<len;j++)   //min element if found and assigned in min
        {
            if(arr[j]<arr[min])
                min=j;;
        }
        t=arr[i];
        arr[i]=arr[min];   //swapping is done and ith element is swapped with min of current array
        arr[min]=t;
        printf("Pass %d: ",i+1); 
        printArray(arr,len);   //print function called to display current iteration
    }
}
int main(){
    int len;
    scanf("%d", &len);   // Input length of the array
    int arr[len];
    if (len<=0){   //Error case when length of array is 0
            printf("ERROR: Empty list\n");
            exit(1);
    }
    inputArray( arr, len );   //Function called to input elements in array
    selectionSort(arr, len);   //Selection sort to sort the array and print changes made in each iteration
    printf("Sorted: ");
        printArray(arr,len);   //Final array is printed i.e. sorted array
    return 0;
}

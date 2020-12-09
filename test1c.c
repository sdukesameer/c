#include<stdio.h>
#include <malloc.h>
int main(){
int *Array, n, p;
    scanf("%d", &n); //Accepts total number of elements from test data
    scanf("%d", &p); //Accepts which position to find
    //Write the program to accept n elements and then print the element
    //at position p after sorting in ascending order
    //Use the printf statement as:
    //printf("The desired element is %d", variable_name);
    Array=(int*) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
        scanf("%d",&Array[i]);
    int t=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(Array[j]>Array[j+1]){
                t=Array[j];
                Array[j]=Array[j+1];
                Array[j+1]=t;
            }
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d",Array[i]);
    printf("The desired element is %d",Array[p-1]);
    return 0;
}
#include <stdio.h>
void findrepeated(int arr[], int n);  // find the repeated elements
int main(){
    int arr[50];
    int i, size;
    scanf("%d", &size); // Size of the Array is taken from the test case
    for(i=0; i<size; i++){
        scanf("%d", &arr[i]); //Array elements are taken from test case
    }
    findrepeated(arr, size); //You have to write this function
    /*  Write the above function which finds the repeated elements and prints the desired output.
    Use the printf statement as 
    printf("Total repeated elements = %d\n", variable_name);
    printf("Repeated elements are: ");
    printf("%d ",variable); //use loop to print the elements seperated by a blank space as per the printf statement. 
    */
    return 0;
}
void findrepeated(int arr[], int n){
    int rep[n],c=0,len=0,t;
    for (int i = 0; i < n; i++){
        c=0;
        for (int j = 0; j < n; j++){
            if (arr[i]==arr[j])
                c++;
        }
        if (c>1){
            t=0;
            for (int k = 0; k < len; k++){
                if(arr[i]==rep[k])
                    t=1;
            }
            if(!t){
                rep[len++]=arr[i];
            }
        }
    }
    printf("Total repeated elements = %d\n", len);
    printf("Repeated elements are: ");
    for (int i = 0; i < len; i++)
        printf("%d ",rep[i]);
}
#include <stdio.h>
void print_rectangle(int n, int m); 
int main()  
{  
    int rows, columns;  
    scanf("%d", &rows); //No of rows is accepted from test data
    scanf("%d", &columns); //No of columns is accepted from test data
    print_rectangle(rows, columns);  
    return 0;  
}  
//Write the above function to complete the program
void print_rectangle(int n, int m){
    for (int i = 0; i < m; i++)
        printf("*");
    printf("\n");
    for (int i = 0; i < n-2; i++){
        printf("*");
        for (int j = 0; j < m-2; j++)
            printf(" ");
        printf("*\n");
    }
    for (int i = 0; i < m; i++)
        printf("*");
    printf("\n");
}
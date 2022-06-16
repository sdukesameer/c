#include<stdio.h>
int main()
{
    int m,n,i,j;
    printf("Enter the size of the arrays (MXN).\n");
    printf("Enter M: ");
    scanf("%d",&m);
    printf("Enter N: ");
    scanf("%d",&n);
    printf("\n");
    int arr1[m][n],arr2[m][n];
    //Entering Values in Matrix 1
    printf("Enter the values of Matrix 1.\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("Value at location [%d][%d] = ",i,j);
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("\n");
    //Entering Values in Matrix 2
    printf("Enter the values of Matrix 2.\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("Value at location [%d][%d] = ",i,j);
            scanf("%d",&arr2[i][j]);
        }
    }
    printf("\n");
    //Printing Matrix 1
    printf(" Matrix 1: \n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
            printf("%3d  ",arr1[i][j]);
        printf("\n");
    }
    printf("\n");
    //Printing Matrix 2
    printf(" Matrix 2: \n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
            printf("%3d  ",arr2[i][j]);
        printf("\n");
    }
    printf("\n");
    //Printing the difference
    printf(" Sum of the Matrix: \n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
            printf("%3d ",(arr1[i][j]+arr2[i][j]));
        printf("\n");
    }
    return 0;
}
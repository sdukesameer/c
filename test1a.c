#include<stdio.h>
int main()
{
    int a[10][10], n; 
    scanf("%d", &n);
    int sum=0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            scanf("%d",&a[i][j]);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i==j)
                sum+=a[i][j];
            if(i+j==(n-1))
                sum+=a[i][j];
        }
    }
    printf("Sum of the diagonal elements is = %d",sum);
    return 0;
}
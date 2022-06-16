#include <stdio.h>
#include <stdlib.h>

double findArea(double [], int, double);

int main(){
    printf("\n******* Output of Set-6 by Md Sameer-114 *******\n");
    double arr[] = { 3.1, 4.4, 5.6, 6.4, 6.5, 6.2, 5.8, 7.7, 8.7, 8.6, 7.5, 0.0 };
    double length = 33;
    double price = 28;
    int n = sizeof(arr) / sizeof(double);
    double h = length / ( n - 1 );
    printf("The Datas are :\n");
    for(int i=0; i<n; i++)
        printf("%.3f ", arr[i]);
    printf("\n\nThe Total Length is : %.3f \n", length);
    printf("\nThe Step Length is : %.3f \n", h);
    printf("\nThe number of sub-intervals are : %d \n", n-1);
    double area = findArea(arr, n, h);
    printf("\nThe Area is : %.3f \n", area);
    double cost=area*price;
    printf("\nThe Cost of turfing is : %.3f \n",cost);
    return 0;
}

double findArea(double arr[], int n, double h)
{
    double y0 = arr[0];
    double yn = arr[n - 1];
    double pFactor = 0;
    int i = 1;
    for (; i < n; i++)
        pFactor += arr[i];
    pFactor *= 2;
    double area = (h / 2) * (y0 + yn + pFactor);
    return area;
}

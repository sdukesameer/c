#include <stdio.h>
#include <malloc.h>
int main(){
    int n;
    scanf("%d", &n); //number of elements of the arrays is accepts from test data   
    int* a=(int*)malloc(sizeof(int)*n);
    int* b=(int*)malloc(sizeof(int)*n);
    int* c=(int*)malloc(sizeof(int)*n);
    int i;
    for (i = 0; i < n; i++)
        scanf("%d",&a[i]);
    for (i = 0; i < n; i++){
        scanf("%d",&b[i]);
        c[i]=a[i]+b[i];
    }
    for (i = 0; i < n; i++)
        printf("%d\n",c[i]);
    return 0;
}
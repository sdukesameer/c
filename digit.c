#include<stdio.h>
int main(){
    int n,c=0;
    scanf("%d",&n);
    do{
        c++;
        n=n/10;
    }while (n);
    printf("%d",c);
    return 0;
}
#include<stdio.h>
int main()
{
    int n,c=0;
    scanf("%d",&n);
    if (n>0)
    {
        while(n>0)
        {
            c++;
            n=n/10;
        }
    }
    else if(n<0)
    {
        while(n<0)
        {
            c++;
            n=n/10;
        }
    }
    else
    {
        c=0;
    }
    printf("%d",c);
    return 0;
}
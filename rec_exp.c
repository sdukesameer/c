#include<stdio.h>
#include<stdlib.h>
float pow(float b, int e);
int main()
{
    float b;
    int e;
    scanf("%f%d",&b,&e);
    if(b<0)
    {
        printf("ERROR");
        exit(1);
    }
    printf("%.2f",pow(b,e));
    return 0;
}
float pow(float b, int e)
{
    if(e==0)
        return 1;
    else if(e>0)
        return pow(b,e-1)*b;
    else
        return pow(b,e+1)*1/b;
}


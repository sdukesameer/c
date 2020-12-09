#include <stdio.h>
float sine(float x, int n);
int main() {
    int n;
    float x;
    scanf("%f",&x);             // Input angle in degrees
    scanf("%d",&n);
    printf("%.2f", sine(x, n) );    // Sine value
    return 0;
}
float sine(float x, int n)
{
    float rad=x*(3.142/180.0);
    float sum=rad,num,den;
    for(int i=3,c=1; c<=n; i=i+2,c++)
    {
        num=1,den=1;
        for(float j=1; j<=i; j++)
        {
            num=num*rad;
            den=den*j;
        }
        if(c%2!=0)
            sum=sum-(num/den);
        else
            sum=sum+(num/den);
    }
    return sum;
}

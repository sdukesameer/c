#include<stdio.h>
int count(int x)
{
    if(x==0)
    return 0;
    else
    return count(x/10)+1;
}
int rev(int n)
{
    int c=count(n), h=1;
    for(int i=1;i<c;i++) h=h*10;
    if (n==0)
    return 0;
    else
    return rev(n/10)+(h*(n%10));
}
int main()
{
    int n,pal;
    printf("Enter an integer: ");
    scanf("%d",&n);
    pal=rev(n);
    if (pal==n)
        printf("%d is Palindrome Number.",n);
    else
        printf("%d is not a Palindrome Number.",n);
    return 0;
}
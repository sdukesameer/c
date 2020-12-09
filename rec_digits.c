#include <stdio.h>
int numDigitsRecursive( int n );
int main() {
    int n;
    scanf("%d", &n);
    printf("Number of digits: %d\n", numDigitsRecursive(n));
    return 0;
}
int numDigitsRecursive( int n )
{
    if(n==0)
    return 0;
    else
    {
        return numDigitsRecursive(n/10)+1;
    }
}
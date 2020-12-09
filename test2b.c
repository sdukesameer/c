#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n); //Value of n is accepted from test case
    // Use the printf statement as:
    //printf("The Sum of Series up to Value %d = %d\n",n,sum);
    int sum=0,s;
    for (int i = 1; i <= n; i++){
        s=0;
        for (int j = 1; j <= i; j++)
            s+=j;
        sum+=s;
    }
    printf("The Sum of Series up to Value %d = %d\n",n,sum);
    return 0;
}
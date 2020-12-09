#include <stdio.h>
int main() {
    int N; //Number of * in the middle row
    scanf("%d", &N); //Value of N is taken from test data
    int i,j,k,space=N-1,star=1;
    for (i = 1; i < 2*N; i++){
        if(i<N){
            for (j = 0; j < space; j++)
                printf(" ");
            space--;
            for (k = 0; k < star; k++)
                printf("*");
            star++;
        }
        if(i==N){
            for (j = 0; j < N; j++)
                printf("*");
            space=1;
            star=N-1;
        }
        if(i>N){
            for (j = 0; j < space; j++)
                printf(" ");
            space++;
            for (k = 0; k < star; k++)
                printf("*");
            star--;
        }
        printf("\n");
    }
    return 0;
}
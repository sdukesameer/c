//NAME: MD SAMEER
//ROLL NO.: 13000119114
//DEPT.: CSE-‘B’
//GROUP: 2
/*
A gambler gambles every night, he may win or lose anything from 0 to 1000 rupees.
Write a program that will help him estimate the most lucky period in the span of the last 15  days.
You can use rand() and % to generate the winning/losing amounts.
Also find out the money he earned or lost in the period. Also print the number of ops.
*/
#define INT_MIN -10000
#include<stdio.h>
#include<stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }
int max3(int a, int b, int c) { return max(max(a, b), c); }

int maxCrossingSum(int arr[], int l, int m, int h, int *ops, int *l_idx, int *r_idx){
    int s=0,i;
    int ls=INT_MIN,rs=INT_MIN;
    for(i=m;i>=l;i--){
        s+=arr[i];
        (*ops)++;
        if(s>ls){
            ls=s;
            *l_idx=i;
        }
    }
    s=0;
    for(i=m+1;i<=h;i++){
        s+=arr[i];
        (*ops)++;
        if(s>rs){
            rs=s;
            *r_idx=i;
        }
    }
    return(max3(ls+rs,ls,rs));
}

int maxSubArraySum(int arr[], int l, int h, int *ops, int *l_idx, int *r_idx){
    int L,R,C,m;
    if(l==h)
        return arr[l];
    else{
        m=(l+h)/2;
        L=maxSubArraySum(arr,l,m,ops,l_idx,r_idx);
        R=maxSubArraySum(arr,m+1,h,ops,l_idx,r_idx);
        C=maxCrossingSum(arr,l,m,h,ops,l_idx,r_idx);
        return(max3(L,R,C));
    }
}

void printArrayWithBrackets(int arr[], int size, int l, int r){
	for (int i=0; i < size; i++){
        if((i==l)&&(i!=r))
            printf("[%d ", arr[i]);
        else if((i!=l)&&(i==r))
            printf("%d] ", arr[i]);
        else if((i==l)&&(i==r))
            printf("[%d] ", arr[i]);
        else
            printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[15];
    for(int i=0; i<15; i++)
        arr[i]=(-1000+ (rand()%2000));
    int n = sizeof(arr) / sizeof(arr[0]);
    int ops=0;
    int l_index=0, r_index=0;
    int max_sum = maxSubArraySum(arr, 0, n - 1, &ops, &l_index, &r_index);
    printf("\nInput array and sequence markers is:\n");
    printArrayWithBrackets(arr,n,l_index,r_index);
    printf("\nMaximum win in his lucky night is %d\n", max_sum);
    printf("Number of ops: %d\n", ops);
    return 0;
}
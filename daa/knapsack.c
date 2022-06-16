#include <stdio.h>
#include <stdlib.h>
//knapsack using greedy
float knapsack_frac(int W, int c[], int v[], int n, int *ops) {
    int i,j,temp,item[n];
    //item mapping
    for (i = 0; i <n; i++)
        item[i]=i+1;
    // sorting vlue and weight respectively acc to value/weight
    for(i = 1; i < n; i++) {
    for(j = 0; j < n - i; j++) {
        if((float)v[j+1]/c[j+1] > (float)v[j]/c[j]) {
            temp=c[j];
            c[j]=c[j+1];
            c[j+1]=temp;
            temp=v[j];
            v[j]=v[j+1];
            v[j+1]=temp;
            //item tracking a/c to density i.e value/weight
            temp=item[j];
            item[j]=item[j+1];
            item[j+1]=temp;
        }
    }
}
    int cur_w=W;
    float total=0;
    for (i = 0;cur_w>0; i++){
        (*ops)++;
        if(cur_w>=c[i]){
            cur_w-=c[i];
            printf("Inserted item %d (val:%d,cost:%d) completely in knapsack. Space left: %d.\n", item[i], v[i], c[i], cur_w);
            total+=v[i];
        }
        else {
            printf("Inserted %d%% (val:%d,cost:%d) of item %d in the knapsack to fill it.\n", (int)(((float)cur_w/c[i]) * 100), v[i], c[i], item[i]);
            total += ((float)cur_w/c[i]) *(float)v[i];
            cur_w=0;
        }
    }
    return total;
}
//knapsack using dynamic
int max(int a, int b) { return (a > b) ? a : b; }

void knapSack(int W, int wt[], int val[], int n, int *ops){
    int i, w;
    int K[n + 1][W + 1];
    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            (*ops)++;
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    // stores the result of Knapsack
    int res = K[n][W];
    printf("Total selected weight: %d\n\n", res);
    printf("Items selected with values\n");
    w = W;
    for (i = n; i > 0 && res > 0; i--) {
        (*ops)++;
        // either the result comes from the top
        // (K[i-1][w]) or from (val[i-1] + K[i-1]
        // [w-wt[i-1]]) as in Knapsack table. If
        // it comes from the latter one/ it means
        // the item is included.
        if (res == K[i - 1][w])
            continue;
        else {
            // This item is included.
            printf("[item %d val: %d]", i-1,wt[i - 1]);
            // Since this weight is included its
            // value is deducted
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
}
void printInputItems(int v[], int w[], int n, int W){
    printf("\n\n** Input Items (value -> weight) *\n\n");
    for(int i=0;i<n;i++){
        printf("[%d -> %d] ",v[i],w[i]);
    }
    printf("\n\n*** Total Knapsack capacity: %d\n\n",W);
}

int main(){
    printf("\n\n--01-Knapsack--\n\n");

    int val[] = { 60, 80, 100 };
    int wt[] = { 10, 20, 25 };
    int W11 = 45;
    int n11 = sizeof(val) / sizeof(val[0]);
    int ops11=0;
    printInputItems(val,wt,n11,W11);
    knapSack(W11, wt, val, n11, &ops11);
    printf("\n\nNumber of ops: %d\n",ops11);

    int val2[] = { 50, 100, 100, 150 };
    int wt2[] = { 5, 10, 25, 15 };
    int W12 = 40;
    int n12 = sizeof(val2) / sizeof(val2[0]);
    int ops12=0;
    printInputItems(val2,wt2,n12,W12);
    knapSack(W12, wt2, val2, n12, &ops12);
    printf("\n\nNumber of ops: %d\n",ops12);

    int val3[] = { 20, 40, 60, 80, 80 };
    int wt3[] = { 5, 4, 2, 10, 4 };
    int W13 = 15;
    int n13 = sizeof(val3) / sizeof(val3[0]);
    int ops13=0;
    printInputItems(val3,wt3,n13,W13);
    knapSack(W13, wt3, val3, n13, &ops13);
    printf("\n\nNumber of ops: %d\n",ops13);

    int val4[] = { 150, 100, 180, 250 };
    int wt4[] = { 30, 10, 50, 40 };
    int W14 = 100;
    int n14 = sizeof(val4) / sizeof(val4[0]);
    int ops14=0;
    printInputItems(val4,wt4,n14,W14);
    knapSack(W14, wt4, val4, n14, &ops14);
    printf("\n\nNumber of ops: %d\n",ops14);

    printf("\n\n--KnapsackFractional--\n\n");

    int n21 = 5;
    int c[] = {14, 3, 5, 4, 8};
    int v[] = {8, 9, 9, 2, 10};
    int W21 = 20;
    float total;
    int ops21=0;
    printInputItems(v,c,n21,W21);
    total = knapsack_frac(W21,c,v,n21,&ops21);
    printf("\n\n***** Total value in knapsack: %f, ops (not considering sorting time) = %d\n",total,ops21);

    int n22 = 5;
    int c2[] = {15, 5, 5, 10, 15};
    int v2[] = {15, 2, 8, 20, 15};
    int W22 = 30;
    float total2;
    int ops22=0;
    printInputItems(v2,c2,n22,W22);
    total2 = knapsack_frac(W22,c2,v2,n22,&ops22);
    printf("\n\n***** Total value in knapsack: %f, ops (not considering sorting time) = %d\n",total2,ops22);

    int n23 = 4;
    int c3[] = {12, 15, 18, 20};
    int v3[] = {6, 12, 8, 12};
    int W23 = 30;
    float total3;
    int ops23=0;
    printInputItems(v3,c3,n23,W23);
    total3 = knapsack_frac(W23,c3,v3,n23,&ops23);
    printf("\n\n***** Total value in knapsack: %f, ops (not considering sorting time) = %d\n",total3,ops23);

    int n24 = 5;
    int c4[] = {12, 12, 12, 12, 12,};
    int v4[] = {15, 20, 25, 30, 18, 11};
    int W24 = 48;
    float total4;
    int ops24=0;
    printInputItems(v4,c4,n24,W24);
    total4 = knapsack_frac(W24,c4,v4,n24,&ops24);
    printf("\n\n***** Total value in knapsack: %f, ops (not considering sorting time) = %d\n",total4,ops24);
    return 0;
}
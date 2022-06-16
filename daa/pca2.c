//NAME: MD SAMEER
//ROLL NO.: 13000119114
//DEPT.: CSE-‘B’
//GROUP: 2
//Set-3
/*

You have 600 rupees in your wallet and the
following is the shopping list which has the price
and priorities (1 is highest) of different
commodities. Spend your money in a fruitful
manner, and you can only purchase one of each
commodity.

Commodity - Price = Priority

Cooking oil 1 ltr pack -> 180 = 2
Rice 5 kg -> 350 = 1
Egg pack of 6 -> 48 = 2
Salt 1 kg pack -> 25 = 1
Frozen Chicken pack -> 300 = 3
Paneer pack -> 150 = 3
Atta 5 kg -> 200 = 1

Write the algorithm and complexity analysis.

*/
#include <stdio.h>
#include <stdlib.h>
int knapsack(int W, int cost[], int val[], int n, int *ops) {
    int i,j,temp,item[n];
    //item mapping
    for (i = 0; i <n; i++)
        item[i]=i+1;
    // sorting value according to priority
    for(i = 1; i < n; i++) {
        for(j = 0; j < n - i; j++) {
            if(val[j] > val[j+1]) {
                temp=cost[j];
                cost[j]=cost[j+1];
                cost[j+1]=temp;

                temp=val[j];
                val[j]=val[j+1];
                val[j+1]=temp;

                //item tracking a/c to density i.e value/weight
                temp=item[j];
                item[j]=item[j+1];
                item[j+1]=temp;
            }
        }
    }

    int current_W=W;
    int total=0;
    for (i = 0;current_W>0 && i<n; i++){
        (*ops)++;
        if(current_W>=cost[i]){
            current_W-=cost[i];
            total+=cost[i];
            printf("\nInserted item %d (priority: %d, cost: %d) \n",item[i], val[i], cost[i]);
            printf("Money left: %d \n",current_W);
        }
        else
            continue;
    }
    return total;
}

void printInputItems(int val[], int cost[], int n, int W){
    printf("\n\tInputted Items [priority -> price] \t\n");
    for(int i=0; i<n; i++)
        printf("[%d -> %d] ",val[i],cost[i]);
    printf("\nTotal money: %d\n\n",W);
}

int main(){
    printf("\t\t\tNAME: MD SAMEER\t\n");
    printf("\t\t\tROLL NO: 13000119114\t\n");
    int n=7;
    int cost[] = {180, 350, 48, 25, 300, 150, 200};
    int value[] = {2, 1, 2, 1, 3, 3, 1};
    int W=600;
    int total;
    int ops=0;
    printInputItems(value,cost,n,W);
    total = knapsack(W,cost,value,n,&ops);
    printf("\nTotal money spend on buying items (priority wise): %d\n",total);
    printf("Money left after expenditure: %d\n",W-total);
    printf("Total ops (not considering sorting time): %d\n",ops);
    return 0;
}


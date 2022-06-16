//NAME: MD SAMEER
//ROLL NO.: 13000119114
//DEPT.: CSE - ‘B’
//GROUP: 2
//Set - '3'
/*
You have an infinite number of coins of denomination
1, 2 and 5 and an infinite number of notes of
denomination 10, 20, 50, 100, 200, 500 and 2000. Code
a program that can calculate the minimum number of
coins and notes needed to give a change for any given
amount.
Also report the number of each denomination required
for the change.
*/
#include <stdio.h>
#define COINS 10
#define MAX 20

// All denominations of Indian Currency
int coins[COINS] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };

void findMin(int cost){
    int coinList[MAX] = { 0 };
    int i,k=0,c=0,n=0;

    for (i = COINS - 1; i >= 0; i--) {
        while (cost >= coins[i]) {
            cost -= coins[i];
            // Add coin in the list
            coinList[i]++;
            if(i<=2)
                c++;
            else
                n++;
        }
    }

    printf("\n\nTotal No of Coins : %d\n",c);
    printf("Total No of Notes : %d\n\n",n);
	for (i = 9; i >=0; i--) {
        if(coinList[i]){
            if(i<=2)
                printf("No. of Rs.  %d coins = %d\n", coins[i],coinList[i]);
            else
                printf("No. of Rs. %d notes = %d\n", coins[i],coinList[i]);
        }
    }
    return;
}

int main(void){
    int n;
    printf("Please enter the amount: ");
    scanf("%d",&n);
    printf("\n#Following is minimal number of change required for Rs. %d: ", n);
    findMin(n);
    return 0;
}
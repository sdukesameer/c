//Write a Program to implement the 8 queen algorithm problem  or  n queen problem through array in recursive way.
#include<stdio.h>
int N;//no of row col
void display(int arr[N][N]){//graphical representation
    static int n=1;
    printf("\nSolution No. %d: \n",n++);
    for (int i = 0; i < N; i++){
        if(i==0){
            for (int k = 0; k < N; k++)
                printf(" ---");
            printf("\n");
        }
        printf("|");
        for (int j = 0; j < N; j++){
            if(arr[i][j])
                printf(" Q |");
            else
                printf("   |");
        }
        printf("\n");
        for (int k = 0; k < N; k++)
            printf(" ---");
        printf("\n");
    }
}
int safe(int arr[N][N], int row, int col){//to check if the column is safe
    int i,j;
    for ( i = 0; i < col; i++)//if column is filled return 0
        if(arr[row][i])
            return 0;
    for ( i = row, j = col; i >= 0 && j >= 0; i--, j--)//if upper diagonal is filled return 0
        if(arr[i][j])
            return 0;
    for ( i = row, j = col; i < N && j >= 0; i++, j--)//if lower diagonal is filled return 0
        if(arr[i][j])
            return 0;
    return 1;//else id safe 
}
void queens(int arr[N][N],int n){//n is col no, initially its 0
    if(n>=N){//best case, when all queens are well placed
        display(arr);
        return;
    }
    for (int i = 0; i < N; i++){//surf accross rows
        if(safe(arr,i,n)){
            arr[i][n]=1;//if safe insert a queen
            queens(arr,n+1); //then check if at next col its safe to place queen
            arr[i][n]=0;//if on next col queens can't be placed backtrack and remove queen from that location
        }
    }
}
int main(){
    int n=1;
    while(n){//check for invalid input
        printf("Enter valid N i.e no of rows and columns: ");
        scanf("%d",&N);
        if(N>0)
            n=0;
    }
    int arr[N][N];
    for (int i = 0; i < N; i++)//initiaise all to 0
        for (int j = 0; j < N; j++)
            arr[i][j]=0;
    if(N==2 || N==3)
        printf("\nFor N = %d, solution doesn't exist.\n",N);
    else
        queens(arr,0);//queen function call
    return 0;
}//end of main function
//1: n-Rook or n-Castle Problem: Write a complete C Program to place  n Rooks or Castles on a nXn Chess Board. 
#include<stdio.h>
int N;
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
                printf(" R |");
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
    for (int i = 0; i < row; i++)//if row is filled return 0
        if(arr[row][i])
            return 0;
    for (int i = 0; i < col; i++)//if col is filled return 0
        if(arr[row][i])
            return 0;
    return 1;//else id safe 
}
void rooks(int arr[N][N], int n){//n is col no, initially its 0
    if(n>=N){//best case, when all rooks are well placed
        display(arr);
        int trs[N][N], t=0;
        for (int i = 0; i < N; i++)//create transpose
            for (int j = 0; j < N; j++)
                trs[j][i]=arr[i][j];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if(trs[i][j]==arr[i][j])
                    t++;
        if(t!=(N*N))//check if array and its tranpose are not same
            display(trs);
        return;
    }
    for (int i = 0; i < N; i++){//surf accross rows
        if(safe(arr,i,n)){
            arr[i][n]=1;//if safe insert a rook
            rooks(arr,n+1);//then check if at next col its safe to place rook
            arr[i][n]=0;//if on next col rooks can't be placed backtrack and remove rook from that location
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
    rooks(arr,0);//rooks function call
    return 0;
}//end of main function
//2: n-Bishop Problem: Write a complete C Program to place  n  Bishops on a nXn Chess Board.  
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
                printf(" B |");
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
    for (i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)//if left upper diagonal is filled return 0
        if(arr[i][j])
            return 0;
    for (i = row+1, j = col+1; i < N && j < N; i++, j++)//if right lower diagonal is filled return 0
        if(arr[i][j])
            return 0;
    for (i = row+1, j = col-1; i < N && j >= 0; i++, j--)//if left lower diagonal is filled return 0
        if(arr[i][j])
            return 0;
    for (i = row-1, j = col+1; i >= 0 && j < N; i--, j++)//if right upper diagonal is filled return 0
        if(arr[i][j])
            return 0;
    return 1;//else id safe 
}
void bishops(int arr[N][N], int n){//n is col no, initially its 0
    if(n>=N){//print if a combination is found
        display(arr);
        if(N>1){
            int trs[N][N];
            for (int i = 0; i < N; i++)//creating transpose of the array
                for (int j = 0; j < N; j++)
                    trs[j][i]=arr[i][j];
            display(trs);
        }
        return;
    }
    for (int i = 0; i < N; i++){//surf accross rows
        if(safe(arr,i,n)){
            arr[i][n]=1;//if safe insert a rook
            bishops(arr,n+1);//then check if at next col its safe to place rook
            arr[i][n]=0;//if on next col bishops can't be placed backtrack and remove rook from that location
        }
    }
}
int main(){
    int n=1;
    while(n){//check for invalid input
        printf("Enter valid N i.e. no of rows and columns: ");
        scanf("%d",&N);
        if(N>0)
            n=0;
    }
    int arr[N][N];
    for (int i = 0; i < N; i++)//initialise all to 0
        for (int j = 0; j < N; j++)
            arr[i][j]=0;
    bishops(arr,0);//bishops function call
    return 0;
}//end of main function
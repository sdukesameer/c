#include <stdio.h>
#include <stdlib.h>
#define N 8

//A utility function to print solution
void printSolution(int board[N][N]){
    int i,j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++){
            if(board[i][j])
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

//checks whether the new row col entry is safe for the existing board
int isSafe(int board[N][N], int row, int col){
	int i;
	// for row check
    for(i=0;i<N;i++)
        if(board[row][i]==1)
            return 0;
    // for diagonal check
    // for upper left
    for(i=1;row-i>=0 && col-i>=0;i++){
        if(board[row-i][col-i]==1)
            return 0;
    }
    // for lower left
    for(i=1;row+i<N && col-i>=0;i++)
        if(board[row+i][col-i]==1)
            return 0;
    return 1;
}

//A recursive function to solve 8 queen
int solveNQUtil(int board[N][N], int col){
	if (col>N-1)
		return 1;
	int row;
	for(row=0;row<N;row++){
		if(isSafe(board,row,col)){
			board[row][col]=1;
			if (solveNQUtil(board,col+1))
					return 1;
			else
				board[row][col]=0;
		}
	}
	return 0;
}

int solveNQ(int board[N][N]){
	return solveNQUtil(board,0);
}

// driver program to test above function
int main(){
    int board[N][N] = { { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 } };
    solveNQ(board);
    printSolution(board);
    printf("\n");
    return 0;
}

#include<stdio.h>
#define INT_MAX 30000

//name is the index of the array i.e for A1 name is 1 and so on, bracket is the s table
//a 2d array passed as 1d array, row major order
void printParenthesis(int i, int j, int n, int* bracket, int *name, int *ops){
    if (i==j){
        (*ops)++;
        printf("A%d",(*name)++);
        return;
    }
    printf("(");
    // Recursively put brackets around subexpression
    // from i to bracket[i][j].
    // Note that "*((bracket+i*n)+j)" is similar to
    // bracket[i][j]
    printParenthesis(i,*((bracket+i*n)+j), n, bracket, name, ops);
    // Recursively put brackets around subexpression
    // from bracket[i][j] + 1 to j.
    printParenthesis(*((bracket+i*n)+j)+1, j, n, bracket, name, ops);
    printf(")");
}

int matrixChainOrder(int p[], int n, int* ops){
    //add ops as +1 when calculating cost q for each k (as per cormen algo) and when q < present m table value
    //that means there should only be two (*ops++) in this function
    /* For simplicity of the program,
    one extra row and one
    extra column are allocated in m[][].
    0th row and 0th
    column of m[][] are not used */
    int m[n][n];
    int bracket[n][n];
    int i,j,k,L,q;
    /* m[i, j] = Minimum number of
    scalar multiplications
    needed to compute the matrix
    A[i]A[i+1]...A[j] =
    A[i..j] where dimension of A[i]
    is p[i-1] x p[i] */
    // cost is zero when multiplying one matrix.
    for (i=1; i<n; i++)
        m[i][i]=0;
    // L is chain length.
    for (L=2; L<n; L++){
        for (i=1; i<n-L+1; i++){
            j=i+L-1;
            m[i][j]=INT_MAX;
            for (k=i; k<=j-1; k++){
                // q = cost/scalar multiplications
                q = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                (*ops)++;
                if (q < m[i][j]){
                    (*ops)++;
                    m[i][j]=q;
                    bracket[i][j]=k;
                }
            }
        }
    }
    int name=1;
    printParenthesis(1, n-1, n, (int*)bracket, &name, ops);
    return m[1][n-1];
}

void printDimensionArray(int* a,int n){
    int i;
    printf("Dimensions are: \n");
    for(i=0;i<(n-1);i++)
        printf("A%d: %d x %d   ",(i+1),a[i],a[i+1]);
    printf("\n\n");
}

// Driver code
int main(){
    int arr[] = { 30, 35, 15, 5, 10, 20, 25 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int ops=0;
    printf("\nThe dimension array is:\n");
    printDimensionArray(arr,n);
    int cost = matrixChainOrder(arr, n, &ops);
    printf("\nOptimal cost is: %d ops is %d\n",cost,ops);

    int arr2[] = { 5, 9, 12, 6, 10, 12, 8 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int ops2=0;
    printf("\nThe dimension array is:\n");
    printDimensionArray(arr2,n2);
    int cost2 = matrixChainOrder(arr2, n2, &ops2);
    printf("\nOptimal cost is: %d ops is %d\n",cost2,ops2);

    int arr3[] = { 5, 10, 15 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int ops3=0;
    printf("\nThe dimension array is:\n");
    printDimensionArray(arr3,n3);
    int cost3 = matrixChainOrder(arr3, n3, &ops3);
    printf("\nOptimal cost is: %d ops is %d\n",cost3,ops3);

    int arr4[] = { 5, 5, 5, 5, 5, 5, 5 };
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int ops4=0;
    printf("\nThe dimension array is:\n");
    printDimensionArray(arr4,n4);
    int cost4 = matrixChainOrder(arr4, n4, &ops4);
    printf("\nOptimal cost is: %d ops is %d\n",cost4,ops4);

    int arr5[] = { 20, 10, 15, 5, 15, 20, 5, 10, 5 };
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    int ops5=0;
    printf("\nThe dimension array is:\n");
    printDimensionArray(arr5,n5);
    int cost5 = matrixChainOrder(arr5, n5, &ops5);
    printf("\nOptimal cost is: %d ops is %d\n",cost5,ops5);

    return 0;
}
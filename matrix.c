#include<stdio.h>
#include<stdlib.h>
int n;
void input(int** mat){
    int f=0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            printf("Enter value at %d%d: ",i,j);
            scanf("%d",&f);
            mat[i][j]=f;
        }
}
void transpose(int** mat, int** res){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[j][i]=mat[i][j];
}
void print_mat(int** mat, int** res){
    printf("\nOriginal matrix: \n");
    for (int i = 0; i < n; i++){
        printf("     ");
        for (int j = 0; j < n; j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
    printf("\nTranposed matrix: \n");
    for (int i = 0; i < n; i++){
        printf("     ");
        for (int j = 0; j < n; j++)
            printf("%d ",res[i][j]);
        printf("\n");
    }
}
void free_mat(int** mat, int** res){
    for (int i = 0; i < n; i++){
        free(mat[i]);
        free(res[i]);
    }
    free(mat);
    free(res);
    printf("\nProgram completed.");
}
int main(){
    int** mat; int** res;
    printf("Enter size of the matrix: ");
    scanf("%d",&n);
    if(n<1)
        exit(1);
    mat=(int**)malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++)
        mat[i]=(int*)malloc(sizeof(int)*n);
    input(mat);
    res=(int**)malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++)
        res[i]=(int*)malloc(sizeof(int)*n);
    transpose(mat,res);
    print_mat(mat,res);
    free_mat(mat,res);
    return 0;
}
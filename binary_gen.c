#include<stdio.h>
void generator(int n, int arr[], int i, char name[][50]){
    if(i==n){
        for (int i = 0; i < n; i++)
            printf("%s<= '%d';\n",name[i],arr[i]);
        printf("wait for 1 ps;\n\n");
        return;
    }
    arr[i]=0;
    generator(n,arr,i+1,name);
    arr[i]=1;
    generator(n,arr,i+1,name);
}
int main(){
    int n=0;
    while(n<1){
        printf("Enter the length of the binary sequence: ");
        scanf("%d",&n);
    }
    int arr[n];
    char name[n][50];
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("Enter %d name: ",i+1);
        scanf("%s",&name[i]);
    }
    printf("\n");
    generator(n,arr,0,name);
}
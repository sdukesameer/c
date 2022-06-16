#include<stdio.h>
void towerofhanoi(int n, int source, int aux, int dest){
    if(n==1){
        printf("Moving disk 1 from %c to %c\n",source,dest);
        return;
    }
    towerofhanoi(n-1,source,dest,aux);
    printf("Moving disk %d from %c to %c\n",n,source,dest);
    towerofhanoi(n-1,aux,source,dest);
}
int main(){
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    towerofhanoi(n,'A','B','C');//A=Source Row, B=Auxilary Row, C=Destination Row
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
struct stud
{
    int roll;
    char fname[30];
    char lname[20];
    int marks;
};
int main()
{
    int n,rec=0,i=0;
    char fn[100];
    scanf("%s",fn);
    scanf("%d",&n);
    FILE *fp;
    struct stud inp;
    fp=fopen(fn,"r");
    if (fp == NULL)
    {
        printf("ERROR\n");
        exit(1);
    }
    printf("Reading file: %s\n",fn);
    while(i<=n)
    {
        fread(&inp,sizeof(struct stud),1,fp);
        i++; rec++;
    }
    printf("%3d %-30s %-20s %3d\n",inp.roll,inp.fname,inp.lname,inp.marks);
    while(fread(&inp,sizeof(struct stud),1,fp))
        rec++;
    printf("Total: %d",rec);
    fclose(fp);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
typedef struct a
{
    int roll;
    char fn[30];
    char ln[20];
    int marks;
}student;
void main()
{
    char file[50];
    int i,c=0;
    student data,temp;
    FILE* fp;
    scanf("%[^\n]s",file);
    scanf("%d",&i);
    fp=fopen(file,"r");
    if (fp==NULL)
    {
        printf("ERROR");
        exit(1);
    }
    printf("Reading file: %s\n",file);
    while(!feof(fp))
    {
        fscanf(fp,"%d %s %s %d\n",&temp.roll,temp.fn,temp.ln,&temp.marks);
        c++;
        if (c==i)
            data=temp;
    }
    printf("%3d %-30s %-20s %3d\n",data.roll,data.fn,data.ln,data.marks);
    printf("Total: %d",c);
}
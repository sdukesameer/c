#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
    int rollno;
    char name[30];
    float grade;
}class;
int main()
{
    int n;
    scanf("%d",&n);
    if(n<1)
    {
        printf("ERROR");
        exit(1);
    }
    class arr[n],t;
    //input
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i].rollno);
        for(int j=0;j<30;j++) arr[i].name[j]=' ';
        gets(arr[i].name);
        //int len=strlen(arr[i].name);
        //arr[i].name[len]=' ';
        scanf("%f",&arr[i].grade);
    }
    //sorting
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if(arr[j+1].grade > arr[j].grade)
            {
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
    //output
    printf("Merit List: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i].rollno);
        printf("%-30s",arr[i].name);
        printf(" %.2f\n",arr[i].grade);
    }
    return 0;
}
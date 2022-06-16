#include<stdio.h>
#include<stdlib.h>
int main()
{
    char file[50],c;
    int u=0,l=0;
    FILE *fp;
    scanf("%s",file);
    fp=fopen(file,"r");
    if (fp == NULL)
    {
        printf("ERROR\n");
        exit(1);
    }
    printf("Reading file: %s\n",file);
    do
    {
        c=fgetc(fp);
        if((int)c>64&&(int)c<91)
            u++;
        else if((int)c>96&&(int)c<123)
            l++;
    }
    while(c!=EOF);
    printf("Uppercase count: %d\n",u);
    printf("Lowercase count: %d\n",l);
    return 0;
}
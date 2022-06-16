#include<stdio.h>
#include<math.h>
void leap()
{
    int year;
    printf("Enter the year: ");
    scanf("%d",&year);
    printf("\n");
    if(year%4==0)
        printf("Leap Year\n");
    else
        printf("Not a Leap Year\n");
}
void greatest()
{
    int a,b,c;
    printf("Enter the first number: ");
    scanf("%d",&a);
    printf("Enter the second number: ");
    scanf("%d",&b);
    printf("Enter the third number: ");
    scanf("%d",&c);
    printf("\n");
    if(a>b&&a>c)
        printf("The first number is the greatest.\n");
    else if(b>a&&b>c)
        printf("The second number is the greatest.\n");
    else if(c>a&&c>b)
        printf("The third number is the greatest.\n");
}
void factorial()
{
    int n;
    unsigned long int fact=1;
    printf("Enter the number: ");
    scanf("%d",&n);
    printf("\n");
    for(int i=n;i>1;i--)
    {
        fact=fact*i;
    }
    printf("Factorial: %lu\n",fact);
}
void swapping()
{
    int a,b,c;
    printf("Enter the first number: ");
    scanf("%d",&a);
    printf("Enter the second number: ");
    scanf("%d",&b);
    printf("Enter the third number: ");
    scanf("%d",&c);
    printf("\n");
    a=a+b+c;
    b=a-(b+c);
    c=a-(b+c);
    a=a-(b+c);
    printf("The first Number is: %d\n",a);
    printf("The second Number is: %d\n",b);
    printf("The third Number is: %d\n",c);
}
void armstrong()
{
    int n,x,c=0,sum=0,f;
    printf("Enter the number: ");
    scanf("%d",&n);
    x=n;
    while(x>0)
    {
        c++;
        x=x/10;
    }
    x=n;
    while(x>0)
    {
        f=x%10;
        sum=sum+(pow(f,c));
        x=x/10;
    }
    if(sum==n)
        printf("Armstrong Number\n");
    else
        printf("Not a Armstrong Number.\n");
}
int main()
{
    int ch;
    printf("Enter your choice:- \n\n");
    printf("1. For leap year\n");
    printf("2. For greatest of three Number\n");
    printf("3. For factorial of any Number\n");
    printf("4. For swapping of three Numbers\n");
    printf("5. For Armstrong Numbers\n");
    printf("6. For exit\n");
    printf("\n");
    scanf("%d",&ch);
    printf("\n");
    switch(ch)
    {
    case 1:
        {
            leap();
            break;
        }
    case 2:
        {
            greatest();
            break;
        }
    case 3:
        {
            factorial();
            break;
        }
    case 4:
        {
            swapping();
            break;
        }
    case 5:
        {
            armstrong();
            break;
        }
    case 6:
        {
            printf("Exitting.....\n");
            break;
        }
    default:
        {
            printf("INVALID OPTION. TRY AGAIN!!!\n");
            break;
        }
        return 0;
    }
}

#include <stdio.h>

int main()
{
    int num,i,sum=0;
    printf("Enter the number: ");
    scanf("%d",&num);

    for(i=1;i<=num/2;i++)
    {
        if(num%i==0)
            {
            sum+=i;
        }
    }

    if(sum==num)
    {
        printf("\n%d is Perfect number!\n",num);
    }
    else
    {
        printf("\n%d is NOT a perfect number!\n",num);
    }
    printf("\nAnshkumar Darji - 24CE022");
}

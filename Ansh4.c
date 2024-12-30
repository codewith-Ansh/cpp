#include <stdio.h>

int main()
{
    int lcm,i,num1,num2,smaller;

    printf("Enter number 1: ");
    scanf("%d",&num1);
    printf("Enter number 2: ");
    scanf("%d",&num2);

    if(num1>num2)
    {
        smaller=num2;
    }
    else if(num2>num1)
    {
        smaller=num1;
    }

    for(i=2;i<=smaller;i++)
    {
        if(num1%i==0 && num2%i==0)
        {
            lcm=i;
            break;
        }
    }
    if(lcm==i)
    {
    printf("\nLCM of %d and %d is %d\n",num1,num2,lcm);
    }
    else{
        printf("\nNo LCM Possible for this two numbers!\n");
    }

    printf("\nAnshkumar Darji - 24CE022");
}

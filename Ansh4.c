#include <stdio.h>

int main()
{
    int lcm,num1,num2,greater;

    printf("Enter number 1: ");
    scanf("%d",&num1);
    printf("Enter number 2: ");
    scanf("%d",&num2);

    if(num1<num2)
    {
        greater=num2;
    }
    else if(num2>num1)
    {
        greater=num1;
    }

    int i=greater;

    while(1)
    {
        if(i%num1==0 && i%num2==0)
        {
            lcm=i;
            break;
        }
        i++;
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

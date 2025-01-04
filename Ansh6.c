#include <stdio.h>
#include <math.h>

int main()
{
    int binary,decimal,octal[15];

    printf("Enter your Binary Number: ");
    scanf("%d",&binary);

    // FOR DECIMAL CONVERSION OF BINARY

    int i,j,remainder,length=0,sum=0;
    j=binary;

    while(j>0)
    {
        length++;
        j/=10;
    }
    j=binary;

    for(i=0;i<length;i++)
    {
        remainder=j%10;
        sum+=remainder*pow(2,i);
        j/=10;
    }
    decimal=sum;
    printf("\nDecimal conversion of Binary %d is %d\n",binary,decimal);

    // FOR OCTAL CONVERSION OF THAT DECIMAL

    int length2=0;
    j=decimal;

    while(j>0)
    {
        length2++;
        j/=10;
    }
    j=decimal;
    for(i=length2-1;i>=0;i--)
    {
        remainder=j%8;
        octal[i]=remainder;

        j/=8;
    }
    printf("Octal conversion of Binary %d is ",binary);
    for(i=0;i<length2;i++)
    {
        printf("%d",octal[i]);
    }
    printf("\n");

    printf("\nAnshkumar Darji - 24CE022");
    return 0;
}

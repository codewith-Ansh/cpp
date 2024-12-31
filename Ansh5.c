#include <stdio.h>
#include <math.h>

int main()
{
    float a,b,c,root1,root2;
    printf("EQUATION MUST BE OF FORM \"a*X^2 + b*X + c\" !\n");

    printf("Enter 'a' Coefficient of X^2: ");
    scanf("%f",&a);
    printf("Enter 'b' Coefficient of X: ");
    scanf("%f",&b);
    printf("Enter 'c' Constant: ");
    scanf("%f",&c);

    root1=((-b)+sqrt((b*b)-(4*a*c)))/(2*a);
    root2=((-b)-sqrt((b*b)-(4*a*c)))/(2*a);

    printf("\nRoots of your equation are %.2f and %.2f\n",root1,root2);
    printf("\nAnshkumar Darji - 24CE022");
    return 0;
}

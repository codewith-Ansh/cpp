#include <stdio.h>

int main()
{
    char str1[25],str2[25];
    int i;
    printf("Enter the string: ");
    gets(str1);

    printf("\nEntered string is: ");
    puts(str1);

    for(i=0;str1[i]!='\0';i++)
    {
        if(str1[i]>=65 && str1[i]<=90)
        {
            str2[i]=str1[i]+32;
        }
        else if(str1[i]>=97 && str1[i]<=122)
        {
            str2[i]=str1[i]-32;
        }
        else if(str1[i]==' ')
        {
            str2[i]=' ';
        }
    }
    str2[i]='\0';

    printf("Output string is: ");
    puts(str2);
}

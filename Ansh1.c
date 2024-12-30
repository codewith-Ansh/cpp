#include <stdio.h>

int main()
{
    char str[50];
    int i,len;

    printf("Enter the string: ");
    gets(str);

    for(i=0;str[i]!='\0';i++)
    {
        len++;
    }
    printf("\nThe length of the string is %d\n",len);
    printf("\nAnshkumar Darji - 24CE022\n");
    return 0;
}

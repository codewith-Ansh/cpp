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
    printf("The length of the string is %d\n",len);
    return 0;
}

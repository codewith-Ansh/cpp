#include <stdio.h>

int main()
{
    int arr[100][3],sumx=0,sumy=0,sumz=0,i,j,len;

    scanf("%d",&len);

    for(i=0;i<len;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<len;i++)
    {
        sumx+=arr[i][0];
        sumy+=arr[i][1];
        sumz+=arr[i][2];
    }
    if(sumx==0 && sumy==0 && sumz==0)
    {
        printf("\nYES");
    }
    else
    {
        printf("\nNO");
    }
    printf("\nAnshkumar Darji - 24CE022");
    return 0;
}

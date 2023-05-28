#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void symm(int a[100][100],int row,int col);
int main()
{
    int a[100][100],i,j,num,row,col;
    printf("enter the number of rows and columns\n");
    scanf("%d%d",&row,&col);
    if(row!=col)
        printf("the matrix is not square matrix\n");
    else{
    printf("enter the elements of array\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&a[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    symm(a,row,col);
    }
    return 0;
}
void symm(int a[100][100],int row,int col)
{
    int i,j,status=0;
    for(i=0;i<row;i++)
    {
       for(j=0;j<col;j++)
       {
           if(a[i][j]==a[j][i])
           {
               status=1;
           }
           else
           {
             status=0;
             break;
           }

       }
    }
    if(status==1)
    {
        printf("generated matrix is symmetric\n");
    }

    else
    {
         printf("generated matrix is not symmetric\n");
    }
}

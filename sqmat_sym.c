/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define row 4
#define col 4
void symm(int a[row][col]);
int main()
{
    int a[row][col],i,j,num;
    printf("enter the elements of array\n");
    srand(time(NULL));
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            num=(rand()%(10-1+1))+1;//(UPPER-LOWER+1)+LOWER;
            //scanf("%d",&a[i][j]);
            a[i][j]=num;
            printf("%d " ,a[i][j]);
        }
        printf("\n");
    }
    symm(a);
}
void symm(int a[row][col])
{
    int i,j,status=0;
    for(i=0;i<row;i++)
    {
       for(j=0;j<col;j++)
       {
           if(a[i][j]==a[j][i])
           {
               status=1;
               printf("status = %d\n",status);
           }
           else
           {
             status=0;
             printf("status = %d\n",status);
             break;
           }
           //break;
       }
       //break;
    }
    if(status==1)
    {
        printf("generated matrix is symmetric\n");
    }

    else
    {
         printf("generated matrix is not symmetric\n");
    }
}*/

/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define row 4
#define col 4
void symm(int a[row][col]);
int main()
{
    int a[row][col],i,j,num;
    printf("enter the elements of array\n");
    //srand(time(NULL));
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
    symm(a);
}
void symm(int a[row][col])
{
    int i,j,status=0;
    for(i=0;i<row;i++)
    {
       for(j=0;j<col;j++)
       {
           if(a[i][j]==a[j][i])
           {
               status=1;
               //printf("status = %d\n",status);
           }
           else
           {
             status=0;
             //printf("status = %d\n",status);
             break;
           }
           //break;
       }
       //break;
    }
    if(status==1)
    {
        printf("generated matrix is symmetric\n");
    }

    else
    {
         printf("generated matrix is not symmetric\n");
    }
}*/
/*
1 2 3 4
2 0 6 5
3 6 0 8
4 5 8 0
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//#define row 4
//#define col 4
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

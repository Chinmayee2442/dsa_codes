#include<stdio.h>
#include<stdlib.h>
#define row 3
#define col 3
void read(int mat[row][col]);
void print(int mat[row][col]);
void mult(int mat1[row][col],int mat2[row][col]);

void main()
{
    int mat1[row][col],mat2[row][col];
    printf("enter the elements for 1st matrix\n");
    read(mat1);
    print(mat1);
     printf("enter the elements for 2nd matrix\n");
    read(mat2);
    print(mat2);
    mult(mat1,mat2);
}
void read(int mat[row][col])
{
   int x,y;
   for(x=0;x<row;x++)
   {
       for(y=0;y<col;y++)
       {
           scanf("%d",(*(mat+x)+y));
       }
   }
}
 void print(int mat[row][col])
 {
     int x,y;
   for(x=0;x<row;x++)
   {
       for(y=0;y<col;y++)
       {
           printf("%d ",*(*(mat+x)+y));
       }
       printf("\n");
   }
}
void mult(int mat1[row][col],int mat2[row][col])
{
   int x,y,k,sum=0,res[row][col];
   for(x=0;x<row;x++)
   {
       for(y=0;y<col;y++)
       {
          for(k=0;k<col;k++)
           {
             sum=sum+((*(*(mat1+x)+k)) * (*(*(mat2+k)+y)));

           }
           *(*(res+x)+y)=sum;
           sum=0;
       }
   }
   printf("\n");
   print(res);
}

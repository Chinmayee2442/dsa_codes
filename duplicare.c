#include<stdio.h>
void duplicate(int a[26]);
int main()
{
    int i,n=25,a[26];
    printf("enter the 25 integers\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        printf("%d ",a[i]);
    }
    duplicate(a);
}
void duplicate(int a[26])
{
    int i=0,j,c=0,max=0,ab[9];
    /*for(i=0;i<25;i++)
    {
        c=0;
        for(j=i;j<25;j++)
        {
            if(a[i]==a[j])
            {
                c++;
            }
        }
        printf("%d is repeated %d times\n",a[i],c);
    }*/
    while(i<25)
    { c=0;
        for(j=i+1;j<25;j++)
        {
            if(a[i]==a[j])
            {
                c++;
            }
            else
            {
                // printf("\n%d",j);
               // i=j;
                break;
            }
            //break;
        }
       printf("\n%d is repeated %d times",a[i],c+1);
       //printf("\n%d",j);
      /* if((c+1)>max)
       {
           max=(c+1);
       }*/
       i=j;
    }
}
/* 1 1 2 2 2 3 3 3 4 4 4 4 4 5 5 6 6 6 6 6 7 7 7 7 7 */

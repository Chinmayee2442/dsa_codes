#include<stdio.h>
#include<stdlib.h>
void key(char str[10][100]);
int count(char str[]);

int main()
{
    FILE *s;
 char str[11][100];
 s=fopen("test.txt","r");
 for(int i=0;i<10;i++)
 {
     fgets(str[i],200,s);
 }
 for(int i=0;i<10;i++)
 {
     puts(str[i]);
 }
 key(str);
 return 0;
}
int count(char str[])
{

    int i,countt=0;
    while(str[i]!='\0')
    {
        countt++;
        i++;
    }
    return countt;
}
void key(char str[][100])
{
    char keey[26],arr[10],abcd[26];
    printf("enter the key string\n");
    gets(keey);
    int i=0,j=0,k=0,l,n=0;
   for(int i=0;i<10;i++)
   { j=0;
    while(str[i][j]!='\0')
    {
        if(str[i][j]==keey[0])
        {
              n=0;
            for(int m=j;m<j+4;m++)
            {
                if(str[i][m]==keey[n])
                {
                    n++;
                    while(keey[n]=='\0')
                    {
                        printf("LINE IS %s\n",str[i]);
                       int a=i;
                        break;
                    }

                }
            }
        }
        j++;
    }
    //int f=count(str[i]); printf("%d\n",f);
   }
printf("enter the string to be replaced\n");
gets(abcd);
for(int i=0;i<10;i++)
   { j=0;
    while(str[i][j]!='\0')
    {
        if(str[i][j]==keey[0])
        {
              n=0;
            for(int m=j;m<j+4;m++)
            {
                if(str[i][m]==keey[n])
                {
                    str[i][m]=abcd[n];
                    n++;
                    while(keey[n]=='\0')
                    {
                        printf("LINE IS %s\n",str[i]);
                       int a=i;

                        break;
                    }

                }
            }
        }
        j++;
    }
   }
}


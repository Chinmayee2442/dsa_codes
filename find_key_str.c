#include<stdio.h>
#include<stdlib.h>
void key(char str[10][100]);
int count(char str[]);

int main()
{
    FILE *s;
 char str[10][100];
 s=fopen("test.txt","r");
 for(int i=0;i<10;i++)
 {
     fgets(str[i],264,s);
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
    printf("%d",count);
    return countt;
}
void key(char str[][100])
{
    char keey[26];
    printf("enter the key string\n");
    gets(keey);
    int i=0,j=0,k=0,l;
    for(l=0;l<10;l++)
    {
        i=0;
        while(str[l][i]!='\0')
        {
        if(str[l][i]==keey[0])
        {
           j=0;
           for(j=i;j<i+4;j++)
            {
               if(str[l][j]==keey[k])
                {
                    k++;
                   while(keey[j+1]=='\0')
                   {
                       printf("\nthe string is %s",str[l]);
                       break;
                   }
                }
            }
        }
        i++;
        }

    }
}


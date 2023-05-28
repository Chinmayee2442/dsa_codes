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
    //printf("%d",count);
    return countt;
}
void key(char str[][100])
{
    char keey[26],arr[10],abcd[26];
    printf("enter the key string\n");
    gets(keey);
    //int f=count(keey);
    //printf("f=%d\n",f);
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
                       // arr[a]=str[i];
                       // print("\n%s",arr[a]);
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
 /*int f=count(str[i+1]);
 int b=i+1;
 printf("%d\n",b);
 printf("%d\n",f);
 int s;
 j=0;
while(str[b][j]!='\0')
{
    for(s=0;s<=f;s++)
    {
        arr[s]=str[b][j];
        printf("%s",str[j]);
        j++;
    }
}
for(s=0;s<=f;s++)
    {
       printf("%s",arr[s]);
    }*/

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
/*
cause i,i,i'm
 in the stars tonight
 so watch me bring the star
 and set the night alight
 shoes on get up in the morn
 cup of milk, lets rock n roll
 king kong kick the drum
 rolling on like a rolling stone..i dunno what to type
 sing-song when i'm walking home
 jump up to the top, lebron*/

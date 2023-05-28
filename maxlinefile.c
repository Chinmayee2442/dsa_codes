#include<stdio.h>
#include<stdlib.h>
void compare(char str[10][100]);
int count(char str[]);

int main()
{
 FILE *s,*c;
 char str[10][100];
 s=fopen("test.txt","r");
 for(int i=0;i<10;i++)
 {
     fgets(str[i],264,s);
 }
 compare(str);
 c=fopen("test1.txt","w");
 for(int i=0;i<10;i++)
 {
     fputs(str[i],c);
 }

 fclose(s);
 fclose(c);
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
void compare(char str[10][100])
{
    int c=0,m,k,i;
    char a[100];
    for(i=0;i<10;i++)
    {
       if(m=count(str[i])>c)
        {
            c=count(str[i]);
           k=i;
        }
    }
   printf("\n longest is \n %s\n",str[k]);
}


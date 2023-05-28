#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct stack
{
    int data[100];
    int top;
};
void push(struct stack *sptr,int n);
int pop(struct stack *sptr);
void display(struct stack *sptr);
int main()
{
    int x,f,a[100000],l,u;
    struct stack s;
    struct stack *sptr;
    sptr=&s;
    sptr->top=-1;
    printf("enter the limit in which numbers to be generated in order of lower-upper limit");
    scanf("%d%d",&l,&u);
    printf("enter the number of random numbers to be generated\n");
    scanf("%d",&x);
    FILE *i=fopen("input2.txt","w");
    srand(time(0));
    for(f=0;f<x;f++)
    {
        a[f]=(rand()%(u-l+1))+l;
        fprintf(i,"%d ",a[f]);
        printf("%d ",a[f]);
    }
    fclose(i);
    int c=0;
    int ch,n,e,k,d,z;
    FILE *st = fopen("stack.txt", "w");
    fclose(st);
    FILE *p = fopen("push.txt", "w");
    fclose(p);
    FILE *pp = fopen("pop.txt", "w");
    fclose(pp);
    FILE *o = fopen("opr.txt", "w");
    fclose(o);
    while(1)
    {
        printf("\n1:PUSH\t 2:POP\t 3:DISPLAY\t 4:EXIT");
        printf("\nenter the number\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:c=c+1;
                   printf("c %d\n",c);
                i=fopen("input2.txt","r");
                e=0;
                while(fscanf(i,"%d",&n)!=EOF)
                {
                    e++;
                    if(e==c)
                    {
                        z=n;
                         printf("%d ",z);
                         push(sptr,z);
                    }
                }
                fclose(i);
            break;
           case 2: k=pop(sptr);
                    d=d+1;
                    if(k==-1)
                        printf("stack underflow\n");
                    else
                        printf("popped: %d",k);
            break;
           case 3: display(sptr);
           break;
           case 4: exit(0);
           break;
        }
    }
}

void push(struct stack *sptr,int n)
{
    FILE *st=fopen("stack.txt","a");
    FILE *p=fopen("push.txt","a");
    FILE *o=fopen("opr.txt","a");
    sptr->top++;
    sptr->data[sptr->top]=n;
    fprintf(st,"%d ",n);
    fprintf(p,"%d ",n);
    fprintf(o,"pushed: %d\n ",n);
    fclose(st);
    fclose(p);
    fclose(o);
}
int pop(struct stack  *sptr)
{
    int n,g;
    FILE *pp=fopen("pop.txt","a");
    FILE *o=fopen("opr.txt","a");
    if(sptr->top==-1)
        return -1;
    else
    {
        n=sptr->data[sptr->top];
        g=n;
        fprintf(pp,"%d ",g);
        fprintf(o,"popped: %d\n ",n);
        fclose(pp);
    fclose(o);
        sptr->top--;
        return n;
    }
}
void display(struct stack  *sptr)
{
    int i;
    if(sptr->top==-1)
                   printf("stack is empty\n");
                else
                 {
                   for(i=sptr->top;i>=0;i--)
                     {
                       printf("->%d",sptr->data[i]);
                     }
                 }

}

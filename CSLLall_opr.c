#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node *NODE;
int count_nodes(NODE tail);
NODE insert_end(NODE tail);
NODE insert_front(NODE tail);
NODE delete_front(NODE tail);
NODE delete_end(NODE tail);
void display(NODE tail);
NODE delete_pos(NODE tail,int a);
NODE insert_pos(NODE tail);
NODE search_and_delete(NODE tail);
NODE sort_ascending(NODE tail);
NODE sort_descending(NODE tail);
NODE find_min(NODE tail);
NODE find_max(NODE tail);
NODE delete_max(NODE tail);
NODE delete_min(NODE tail);
NODE reverse_list(NODE tail);
int main()
{
    NODE tail=NULL;
    int ch;
    int a;
    NODE low,high;
    while(1)
    {
        printf("enter 1 to insert_end,2 to insert front,3 to delete front,4 to delete end,5 to display,6 to delete a position,\n7 to insert at a psoition,8 to search and delete nodes,9 to sort in increasing order,10 to sort in decreasing order,\n12 to find maximum node,11 to find minimum node,13 to delete maximum data,14 to delete minimum data,15 to reverse list,16 to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
          case 1:tail=insert_end(tail);
          break;
          case 2:tail=insert_front(tail);
          break;
          case 3:tail=delete_front(tail);
          break;
          case 4:tail=delete_end(tail);
          break;
          case 5:display(tail);
          break;
          case 6:
              printf("enter the position to be deleted\n");
              scanf("%d",&a);
              tail=delete_pos(tail,a);
              break;
          case 7:tail=insert_pos(tail);
          break;
          case 8:tail=search_and_delete(tail);
          break;
          case 9:tail=sort_ascending(tail);
          break;
          case 10:tail=sort_descending(tail);
          break;
          case 11:low=find_min(tail);
          printf("the least data in the list is %d\n",low->data);
          break;
          case 12:high=find_max(tail);
          printf("the highest data in the list is %d\n",high->data);
          break;
          case 13:tail=delete_max(tail);
          break;
          case 14:tail=delete_min(tail);
          break;
          case 15:tail=reverse_list(tail);
          break;
          case 16:exit(0);
          break;
          default:printf("invalid choice\n");
          break;
        }
    }
}
int count_nodes(NODE tail)
{
    NODE cur=tail->link;
    int n=0;
    do
    {
      n++;
      cur=cur->link;
    }while(cur!=tail->link);
    return n;
}
NODE insert_end(NODE tail)
{
    NODE cur;
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    printf("enter data\n");
    scanf("%d",&newnode->data);
    if(tail==NULL)
    {
        tail=newnode;
        newnode->link=newnode;
    }
    else{
            cur=tail->link;
        newnode->link=tail->link;
        tail->link=newnode;
        tail=newnode;
    }
    return tail;
}
NODE insert_front(NODE tail)
{
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    printf("enter data\n");
    scanf("%d",&newnode->data);
    if(tail==NULL)
    {
        tail=newnode;
        newnode->link=newnode;
    }
    else{
        newnode->link=tail->link;
        tail->link=newnode;
    }
    return tail;
}
NODE delete_front(NODE tail)
{
    if(tail==NULL)
    {
        printf("it is empty\n");
    }
    else if(tail->link==tail)
    {
        free(tail);
        tail=NULL;
    }
    else{
    NODE temp=tail->link;
    tail->link=(tail->link)->link;
    free(temp);
    return tail;
    }
}
NODE delete_end(NODE tail)
{
    if(tail==NULL)
    {
        printf("it is empty\n");
    }
    else if(tail->link==tail)
    {
        free(tail);
        tail=NULL;
    }
    else{
    NODE cur=tail->link,temp;
    do
    {
        cur=cur->link;
    }while(cur->link!=tail);
    temp=cur->link;
    cur->link=tail->link;
    tail=cur;
    free(temp);
    }
    return tail;
}
void display(NODE tail)
{
    if(tail==NULL)
    {
        printf("the list is empty\n");
    }
    else{
    NODE cur=tail->link;
    do{
      printf("%d->",cur->data);
      cur=cur->link;
    }while(cur!=tail->link);
    }
    printf("\n");
}
NODE delete_pos(NODE tail,int a)
{
    if(tail==NULL)
    {
        printf("the list is empty\n");
    }
    else{
    int n=count_nodes(tail);
     if(a==n)
    {
        tail=delete_end(tail);
    }
    else if(a==1)
    {
        tail=delete_front(tail);
    }
    else{
    NODE cur=tail->link,prev=NULL;
    for(int i=0;i<a-1;i++)
    {
        prev=cur;
      cur=cur->link;
    }
    prev->link=cur->link;
    free(cur);
    }
    }
    return tail;
}
NODE insert_pos(NODE tail)
{
    if(tail==NULL)
    {
        printf("the list is empty\n");
    }
    else{
    int n=count_nodes(tail);
    int a;
    printf("enter the position at which you want to insert(between 1 and %d\n",n+1);
    scanf("%d",&a);
    if(a==1)
    {
        tail=insert_front(tail);
    }
    else if(a==n+1)
    {
        tail=insert_end(tail);
    }
    else{
        NODE newnode;
        newnode=(NODE)malloc(sizeof(struct node));
        printf("enter the data\n");
        scanf("%d",&newnode->data);
        NODE cur=tail->link;
        for(int i=0;i<a-2;i++)
        {
            cur=cur->link;
        }
        newnode->link=cur->link;
        cur->link=newnode;
    }
    }
    return tail;
}
/*NODE search_and_delete(NODE tail)
{
    int n=count_nodes(tail);
    int a;
    int i=1,j=0;
    NODE cur=tail->link,temp;
    printf("enter the number you want to search and delete throughout the list\n");
    scanf("%d",&a);
    for(i=1;i<=n-j;i++)
    {
       if(cur->data==a)
       {
           temp=cur->link;
           tail=delete_pos(tail,i);
           cur=temp;
           i--;
           j++;
       }
       else{
       cur=cur->link;
       }
    }
   return tail;
}*/
NODE search_and_delete(NODE tail)
{
    int n=count_nodes(tail);
    int a;
    NODE cur=tail->link,prev=tail,temp;
    printf("enter the number you want to search and delete throughout the list\n");
    scanf("%d",&a);
    do{
        if(cur->data==a)
        {
            prev->link=cur->link;
            printf("deleted %d\n",cur->data);
            free(cur);
            cur=(prev->link)->link;
        }
        prev=cur;
        cur=cur->link;
    }while(cur!=tail->link);
    return tail;
}
NODE sort_ascending(NODE tail)
{
    NODE cur=tail->link,prev=NULL;
    int n=count_nodes(tail);
    int temp;
    for(int i=0;i<n;i++)
    {
        cur=tail->link;
        prev=cur;
        do{
           if(cur->data<prev->data)
           {
               temp=cur->data;
               cur->data=prev->data;
               prev->data=temp;
           }
           prev=cur;
           cur=cur->link;
        }while(cur!=tail->link);
    }
    return tail;
}
NODE sort_descending(NODE tail)
{
    NODE cur,prev;
    int n=count_nodes(tail);
    int temp;
    for(int i=0;i<n;i++)
    {
        cur=tail->link;
        prev=cur;
        do{
           if(cur->data>prev->data)
           {
               temp=cur->data;
               cur->data=prev->data;
               prev->data=temp;
           }
           prev=cur;
           cur=cur->link;
        }while(cur!=tail->link);
    }
    return tail;
}
NODE find_min(NODE tail)
{
    NODE cur=tail->link;
    NODE cur_min=cur;
    do{
      if(cur->data<cur_min->data)
      {
          cur_min=cur;
      }
      cur=cur->link;
    }while(cur!=tail->link);
    return cur_min;
}
NODE find_max(NODE tail)
{
    NODE cur=tail->link;
    NODE cur_max=cur;
    do{
      if(cur->data>cur_max->data)
      {
          cur_max=cur;
      }
      cur=cur->link;
    }while(cur!=tail->link);
    return cur_max;
}

NODE delete_max(NODE tail)
{
    NODE cur=tail->link,prev=tail,temp=NULL;
    NODE max=NULL;
    int i=1;
    max=find_max(tail);
    do{
        if(cur->data==max->data)
        {
            prev->link=cur->link;
            temp=cur->link;
            free(cur);
            cur=temp;
        }
        else{
        prev=cur;
        cur=cur->link;
        }
    }while(cur!=tail->link);
    return tail;
}
NODE delete_min(NODE tail)
{
    NODE cur=tail->link,prev=tail;
    NODE min;
    NODE temp;
    min=find_min(tail);
    do{
        if(cur->data==min->data)
        {
            prev->link=cur->link;
            temp=cur->link;
            free(cur);
            cur=temp;
        }
        else{
        prev=cur;
        cur=cur->link;
        }
    }while(cur!=tail->link);
   return tail;
}
NODE reverse_list(NODE tail)
{
    NODE temp1=tail->link;
    NODE cur=tail->link,temp=NULL,prev=tail;
    do{
            temp=cur->link;
            cur->link=prev;
            prev=cur;
            cur=temp;

    }while(cur!=temp1);
    tail=cur;
    return tail;
}

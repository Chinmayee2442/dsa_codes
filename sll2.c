#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node *NODE;

NODE create_node();
NODE insert_end(NODE head);
NODE insert_front(NODE head);
NODE insert_pos(NODE head);
NODE delete_front(NODE head);
NODE delete_end(NODE head);
NODE delete_pos(NODE head);
int count_nodes(NODE head);
NODE reverse(NODE head);
void display_list(NODE head);


int main()
 {
  NODE head=NULL;
  int ch, count;
  while(1)
  {
      printf("\n1:insert_end 2:insert_front 3:insert_pos 4:delete_end 5:delete_front 6:delete_pos 7:display 8:reverse 9:Exit\n");
      printf("Enter your choice\n");
      scanf("%d",&ch);
      switch(ch)
      {
            case 1:head=insert_end(head);
                   break;
            case 2:head=insert_front(head);
                    break;
            case 3:head=insert_pos(head);
                    break;
            case 4:head=delete_end(head);
                    break;
            case 5:head=delete_front(head);
                    break;
            case 6:head=delete_pos(head);
                     break;
            case 7:display_list(head);
                     break;
            case 8:head=reverse(head);
                     break;
            case 9:exit(0);
                     break;
        }
  }
}

NODE create_node() //create node function
{
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter data\n");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    return newnode;
}

NODE insert_end(NODE head)
{
    NODE cur,newnode;
    newnode=create_node();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        cur=head;
        while(cur->link!=NULL)
        {
            cur=cur->link;
        }
        cur->link=newnode;
    }
    return head;
}

NODE insert_front(NODE head)
{
    NODE newnode;
    newnode=create_node();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->link=head;
        head=newnode;
    }
    return head;
}

NODE insert_pos(NODE head)
{
    NODE prev,cur;
    NODE newnode=create_node();
    int pos;
    int count=count_nodes(head);
    printf("Enter position\n");
    scanf("%d",&pos);
    if(pos==1 && head==NULL)
    {
        head=newnode;
    }
    else if(pos==1)
    {
        newnode->link=head;
        head=newnode;
    }
    else if(pos==count+1)
    {
        cur=head;
        while(cur->link!=NULL)
        {
            cur=cur->link;
        }
        cur->link=newnode;
    }
    else if(pos>1 && pos<=count)
    {
        prev=NULL;
        cur=head;
        for(int i=0;i<pos-1;i++)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=newnode;
        newnode->link=cur;
    }
    else
    {
        printf("Invalid position\n");
    }
    return head;
}


NODE delete_end(NODE head)
{
    NODE prev, cur;
    if(head==NULL)
    {
        printf("Singly linked list is empty\n");
    }
    else if(head->link==NULL)
    {
        printf("Deleted %d\n",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        prev=NULL;
        cur=head;
        while(cur->link!=NULL)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=NULL;
        printf("Deleted %d\n",cur->data);
        free(cur);
    }
    return head;
}

NODE delete_front(NODE head)
{
    NODE cur;
    if(head==NULL)
    {
        printf("Singly linked list is empty\n");
    }
    else if(head->link==NULL)
    {
        printf("Deleted %d\n",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        cur=head;
        head=head->link;
        printf("Deleted %d\n",cur->data);
        cur->link=NULL;
        free(cur);
    }
    return head;
}

NODE delete_pos(NODE head)
{
    int pos;
    NODE cur, prev;
    int count=count_nodes(head);
    printf("Enter position to delete\n");
    scanf("%d",&pos);
    if(head==NULL)
    {
        printf("SLL is empty\n");
    }
    else if(pos==1 && head->link==NULL)
    {
        printf("Deleted %d\n",head->data);
        free(head);
        head=NULL;
    }
    else if(pos==1)
    {
        cur=head;
        head=head->link;
        cur->link=NULL;
        printf("Deleted %d\n",cur->data);
        free(cur);
    }
    else if(pos==count)
    {
        prev=NULL;
        cur=head;
        while(cur->link!=NULL)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=NULL;
        printf("Deleted %d\n",cur->data);
        free(cur);
    }
    else if(pos>1 && pos<count)
    {
        prev=NULL;
        cur=head;
        for(int i=0;i<pos-1;i++)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=cur->link;
        printf("Deleted %d\n",cur->data);
        free(cur);
    }
    else
    {
        printf("Invalid position\n");
    }
    return head;
}


int count_nodes(NODE head)
{
    int count=0;
    NODE cur;
    if(head==NULL)
    {
        return count;
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            count++;
            cur =cur->link;
        }
    }
    return count;
}
NODE reverse(NODE head)
{
   int i,j,n,temp;
   NODE prev,cur;
   prev=head;
   cur=prev->link;
   n=count_nodes(head);
   for(i=0;i<n-1;i++)
   {
        prev=head;
        cur=prev->link;
       for(j=0;j<n-i-1;j++)
       {
          temp=prev->data;
          prev->data=cur->data;
          cur->data=temp;
           prev=cur;
        cur=cur->link;
       }
   }
   return head;
}

void display_list(NODE head)
{
    NODE cur=head;
    if(head==NULL)
    {
        printf("Singly linked list is empty\n");
    }
    else
    {
        while(cur!=NULL)
        {
            printf("%d->",cur->data);
            cur=cur->link;
        }
    }
}


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct NODE
{
    int data;
    struct NODE *lc;
    struct NODE *rc;
};
typedef struct NODE *node;
void inorder(node root);
void insert(int data);
void preorder(node root);
void postorder(node root);
void someorder(node root);
void levelorder(node root);
void currentlevel(node root,int level);
int height(node n);
node root=NULL;   //works like head;
int main()
{
    int n,p,q,i,num,x,a,h[1000];
    FILE *s;
    printf("enter the range in which N random numbers are to be generated in order [lower,upper]\n");
    scanf("%d%d",&p,&q);
    printf("enter the number of random numbers to be generated\n");
    scanf("%d",&n);
    s=fopen("input.txt","w");
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
       num=(rand()%(q-p+1))+p;//(UPPER-LOWER+1)+LOWER;
       printf("%d\t",num);
       //putw(num,s);
       fprintf(s,"%d\n",num);
    }
    fclose(s);
     s=fopen("input.txt","r");
     for(i=0;i<n;i++)
    {
      fscanf(s,"%d",&a);
      x=a;
      insert(x);
    }
    fclose(s);
    printf("\n");
    printf("inorder traverse is:\n");
    inorder(root);
     printf("\n");
     printf("preorder traverse is:\n");
    preorder(root);
     printf("\n");
     printf("postorder traverse is:\n");
    postorder(root);
    printf("\n");
    printf("descending order traverse is:\n");
    someorder(root);
     printf("\n");
    printf("level order traverse is:\n");
    levelorder(root);
   return 0;
}

void insert(int data)
{
   node newnode = (node)malloc(sizeof(struct NODE));
   node current;
   node parent;
   newnode->data = data;
   newnode->lc = NULL;
   newnode->rc = NULL;
   if(root == NULL)
   {
      root = newnode;
   }
    else
        {
      current = root;
      parent = NULL;
      while(1)
      {
         parent = current;
         if(data < parent->data)  //go to left of the tree
         {
            current = current->lc;
            if(current == NULL)
            {
               parent->lc = newnode; //insert to the left
               return;
            }
         }
         else //go to right of the tree
         {
            current = current->rc;
            if(current == NULL)
            {
               parent->rc= newnode;//insert to the right
               return;
            }
         }
      }
   }
}
void inorder(node root)
{
    FILE *i;
   i=fopen("inorder.txt","w");
   if(root != NULL)
    {
      inorder(root->lc); //recursion to leftchild
      printf("%d ",root->data);
      fprintf(i,"%d ",root->data);
      inorder(root->rc);//recursion to rightchild
   }
   fclose(i);
}

void preorder(node root)
{
    FILE *pre;
   pre=fopen("preorder.txt","w");
   if(root != NULL)
    {
      printf("%d ",root->data);
      fprintf(pre,"%d ",root->data);
      preorder(root->lc);//recursion to leftchild
      preorder(root->rc);//recursion to rightchild
   }
    fclose(pre);
}

void postorder(node root)
{
    FILE *post;
   post=fopen("postorder.txt","w");
   if(root != NULL)
    {
      postorder(root->lc);//recursion to leftchild
      postorder(root->rc);//recursion to rightchild
      printf("%d ",root->data);
      fprintf(post,"%d ",root->data);
   }
    fclose(post);
}

void someorder(node root)
{
    FILE *some;
   some=fopen("someorder.txt","w");
   if(root != NULL)
    {
      someorder(root->rc);//recursion to rightchild
      printf("%d ",root->data);
      fprintf(some,"%d ",root->data);
      someorder(root->lc);//recursion to leftchild
   }
    fclose(some);
}
int height(node n)
{
    if(n==NULL)
        return 0;
    else{
        int lheight=height(n->lc);
        int rheight=height(n->rc);
        if(lheight>rheight)
            return (lheight+1);
        else
            return (rheight+1);
    }
}
void currentlevel(node root,int level)
{
    if(root==NULL)
        return;
    printf("\n");
    if(level==1) // when desired level is reached
        printf("%d",root->data);
    else if(level>1){
        currentlevel(root->lc,level-1);
        currentlevel(root->rc,level-1);
    }
}
void levelorder(node root)
{
    int h=height(root);
    int i;
    for(i=1;i<=h;i++)
        currentlevel(root,i);
}

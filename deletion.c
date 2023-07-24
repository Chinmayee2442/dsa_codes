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
void insert(int data);
void inorder(node root);
node deletion(node root,int data);
node inpredecessor(node root);
node root=NULL;
int main()
{
    int n,p,q,i,num,x,a,val;
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
    printf("enter the value to be deleted:\n");
    scanf("%d",&val);
    root=deletion(root,val);
    inorder(root);
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


node inpredecessor(node root)//get the predecessor of current node which has been sent as argument
{                            //to find  the largest value in the left subtree
    root=root->rc;
    while(root->rc!=NULL)
    {
        root=root->rc;
    }
    return root;
}
node deletion(node root, int val)
{
    if (root == NULL)
        return NULL;

    if (val < root->data)
    {
        root->lc = deletion(root->lc, val);
    }
    else if (val > root->data)
    {
        root->rc = deletion(root->rc, val);
    }
    else
    {
        if (root->lc == NULL)
        {
            node temp = root->rc;
            free(root);
            return temp;
        }
        else if (root->rc == NULL)
        {
            node temp = root->lc;
            free(root);
            return temp;
        }

        node ipre = inpredecessor(root);
        root->data = ipre->data;
        root->lc = deletion(root->lc, ipre->data);
    }
    return root;
}
/*node deletion(node root,int val)
{
    node ipre;
    if(root==NULL)
     return NULL;
   if(root->lc==NULL && root->rc==NULL)
   {
       free(root);
       return NULL;
   }
   if(val<root->data)// to check if value is greater or lesser than root data
   {
      root->lc= deletion(root->lc,val);
   }
   else if(val>root->data)
   {
      root->rc= deletion(root->rc,val);
   }
   else //actual deletion process
   {
       ipre=inpredecessor(root);
       root->data=ipre->data;
       root->lc=deletion(root->lc,ipre->data);
   }
    return root;
}
*/

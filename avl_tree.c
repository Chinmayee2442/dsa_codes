/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct NODE
{
    int key;
    struct NODE *lc;
    struct NODE *rc;
     int height;
};
typedef struct NODE *node;
node root=NULL;   //works like head;
int getheight(node n)
{
    if(n==NULL)
        return 0;
    return n->height;
}
node create_node(int key)
{
    node newnode=(node)malloc(sizeof(struct NODE));
    newnode->key=key;
    newnode->lc=NULL;
    newnode->rc=NULL;
    newnode->height=1;

    return newnode;
}
int max(int a,int b)
{
    return a>b?a:b;
}
int getbf(node n)//utility function to find balance factor
{
    if(n==NULL)
        return 0;
    return getheight(n->lc)-getheight(n->rc);
}
node rightrotate(node y)
{
    node x=y->lc;
    node t2=x->rc;

    x->rc=y;
    y->lc=t2;

    y->height=max(getheight(y->lc),getheight(y->rc))+1;
    x->height=max(getheight(x->lc),getheight(x->rc))+1;
    return x;//x becomes root
}
node leftrotate(node x)
{
    node y=x->lc;
    node t2=y->rc;

    y->lc=x;
    x->rc=t2;

    y->height=max(getheight(y->lc),getheight(y->rc))+1;
    x->height=max(getheight(x->lc),getheight(x->rc))+1;
    return y;//y becomes root
}
node insert(int key)
{
      node current;
   node parent;
    node newnode=create_node(key);
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
         if(key < parent->key)  //go to left of the tree
         {
            current = current->lc;
            if(current == NULL)
            {
               parent->lc = newnode; //insert to the left
               return root;
            }
         }
         else //go to right of the tree
         {
            current = current->rc;
            if(current == NULL)
            {
               parent->rc= newnode;//insert to the right
               return root;
            }
         }
      }
   }
   parent->height=1+max(getheight(parent->lc),getheight(parent->rc));
   int bf=getbf(parent);

   //left left case
   if(bf>1 && key<parent->lc->key)
   {
       return rightrotate(parent);
   }
   //right right case
   if(bf<-1 && key>parent->rc->key)
   {
       return leftrotate(parent);
   }
   //left right case
   if(bf>1 && key>parent->lc->key)
   {
       parent->lc=leftrotate(parent->lc);
       return rightrotate(parent);
   }
   //right left case
   if(bf<-1 && key<parent->rc->key)
   {
       parent->rc=rightrotate(parent->rc);
       return leftrotate(parent);
   }
   return root;
}
void preorder(node root)
{
   if(root != NULL)
    {
      printf("%d ",root->key);
      preorder(root->lc);//recursion to leftchild
      preorder(root->rc);//recursion to rightchild
   }
}
int main()
{
    int n,p,q,i,num,x,a;
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
      root=insert(x);
    }
    fclose(s);
     printf("\n");
     printf("preorder traverse is:\n");
    preorder(root);

   return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct NODE {
    int key;
    struct NODE *lc;
    struct NODE *rc;
    int height;
};

typedef struct NODE *node;

node root = NULL;

int getheight(node n) {
    if (n == NULL)
        return 0;
    return n->height;
}

node create_node(int key) {
    node newnode = (node)malloc(sizeof(struct NODE));
    newnode->key = key;
    newnode->lc = NULL;
    newnode->rc = NULL;
    newnode->height = 1;

    return newnode;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getbf(node n) {
    if (n == NULL)
        return 0;
    return getheight(n->lc) - getheight(n->rc);
}

node rightrotate(node y) {
    node x = y->lc;
    node t2 = x->rc;

    x->rc = y;
    y->lc = t2;

    y->height = max(getheight(y->lc), getheight(y->rc)) + 1;
    x->height = max(getheight(x->lc), getheight(x->rc)) + 1;

    return x;
}

node leftrotate(node x) {
    node y = x->rc;
    node t2 = y->lc;

    y->lc = x;
    x->rc = t2;

    x->height = max(getheight(x->lc), getheight(x->rc)) + 1;
    y->height = max(getheight(y->lc), getheight(y->rc)) + 1;

    return y;
}

node insert(node root, int key) {
    if (root == NULL)
        return create_node(key);

    if (key < root->key)
        root->lc = insert(root->lc, key);
    else if (key > root->key)
        root->rc = insert(root->rc, key);
    else
        return root;  // Duplicate keys are not allowed in AVL tree

    root->height = 1 + max(getheight(root->lc), getheight(root->rc));
    int bf = getbf(root);

    // Left Left case
    if (bf > 1 && key < root->lc->key)
        return rightrotate(root);

    // Right Right case
    if (bf < -1 && key > root->rc->key)
        return leftrotate(root);

    // Left Right case
    if (bf > 1 && key > root->lc->key) {
        root->lc = leftrotate(root->lc);
        return rightrotate(root);
    }

    // Right Left case
    if (bf < -1 && key < root->rc->key) {
        root->rc = rightrotate(root->rc);
        return leftrotate(root);
    }

    return root;
}

void preorder(node root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->lc);
        preorder(root->rc);
    }
}

int main() {
    int n, p, q, i, num, x, a;
    FILE *s;

    printf("Enter the range in which N random numbers are to be generated in order [lower,upper]: ");
    scanf("%d%d", &p, &q);
    printf("Enter the number of random numbers to be generated: ");
        scanf("%d", &n);
    s = fopen("input.txt", "w");
    srand(time(NULL));

    for (i = 0; i < n; i++) {
        num = (rand() % (q - p + 1)) + p;
        printf("%d\t", num);
        fprintf(s, "%d\n", num);
    }

    fclose(s);

    s = fopen("input.txt", "r");
    for (i = 0; i < n; i++) {
        fscanf(s, "%d", &a);
        x = a;
        root = insert(root, x);
    }

    fclose(s);

    printf("\n");
    printf("Preorder traversal:\n");
    preorder(root);

    return 0;
}

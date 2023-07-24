#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 100
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

node minvalue(node n)
{                            //to find  the lowest value in the left subtree
    node current=n;
    while(current->lc!=NULL)
    {
        current=current->lc;
    }
    return current;
}
node deletion(node root,int key)
{
   if(root==NULL)
    return root;
   if(key<root->key)
    root->lc=deletion(root->lc,key);
   else if(key>root->key)
     root->rc=deletion(root->rc,key);
   else
   {
       if(root->lc==NULL || root->rc==NULL)
       {
           node temp;
           if (root->lc != NULL)
            {
               temp = root->lc;
            }
                else
                {
                temp = root->rc;
                }
        if(temp==NULL)
        {
            temp=root;
            root=NULL;
        }
        else
        *root = *temp; // Copy the contents of the non-empty child
            free(temp);

       }
       else
       {
         node temp = minvalue(root->rc);
            // Copy the inorder successor's data to this node
            root->key = temp->key;
            // Delete the inorder successor
            root->rc = deletion(root->rc, temp->key);
       }
   }
   if (root == NULL)
      return root;
    root->height = 1 + max(getheight(root->lc),getheight(root->rc));
    int balance = getbf(root);
    // Left Left Case
    if (balance > 1 && getbf(root->lc) >= 0)
        return rightrotate(root);
    // Left Right Case
    if (balance > 1 && getbf(root->lc) < 0)
    {
        root->lc =  leftrotate(root->lc);
        return rightrotate(root);
    }
    // Right Right Case
    if (balance < -1 && getbf(root->rc) <= 0)
        return leftrotate(root);
    // Right Left Case
    if (balance < -1 && getbf(root->rc) > 0)
    {
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
void inorder(node root)
{
   if(root != NULL)
    {
      inorder(root->lc); //recursion to leftchild
      printf("%d ",root->key);
      inorder(root->rc);//recursion to rightchild
   }
}
void print2DUtil(node root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->rc, space);
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    // Process left child
    print2DUtil(root->lc, space);
}

void print2D(node root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}
int main() {
    int n, p, q, i, num, x, a,val;
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
    printf("inorder traversal:\n");
     inorder(root);
    printf("\n");
    printf("enter the value to be deleted:\n");
    scanf("%d",&val);
    root=deletion(root,val);
    inorder(root);
    printf("\n");
    print2D(root);
    return 0;
}

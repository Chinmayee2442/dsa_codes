#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void b_sort(int h[1000],int x);
void ins_sort(int arr[1000],int x);
void slc_sort(int arr[1000],int x);
void qik_sort(int arr[1000],int lb,int ub);
int partition(int arr[1000],int lb,int ub);
void merge_sort(int arr[1000],int lb,int ub);
void merge(int arr[1000],int lb,int mid,int ub);
int main()
{
    int n,p,q,i,num,x,a,h[1000];
    FILE *s,*l;
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
    printf("\nenter the number of numbers to be sorted\n");
    scanf("%d",&x);
    l=fopen("log.txt","w");
    fprintf(l,"%d\n",x);
    fclose(l);
    for(i=0;i<x;i++)
    {
      fscanf(s,"%d",&a);
       h[i]=a;
      printf("%d\t",h[i]);
    }
    fclose(s);
    l=fopen("log.txt","a");
    clock_t start_t,end_t;
    double total_t;

    start_t=clock();
    b_sort(h,x);
    end_t=clock();
    fprintf(l,"\ntime taken by bubble sort=%lf",total_t);

    start_t=clock();
    slc_sort(h,x);
    end_t=clock();
    fprintf(l,"\ntime taken by selection sort=%lf",total_t);

    start_t=clock();
    ins_sort(h,x);
    end_t=clock();
    fprintf(l,"\ntime taken by insertion sort=%lf",total_t);

    FILE *c;
   c=fopen("output.txt","a");
   fprintf(c,"\nquick sort\n");
   fprintf(l,"\n");

    start_t=clock();
     printf("\n%f",start_t);

    qik_sort(h,0,x-1);

    end_t=clock();
    printf("\n%f",end_t);
    total_t=(double)((end_t-start_t))/CLOCKS_PER_SEC;
    printf("\ntime taken=%lf\n",total_t);
    fprintf(l,"\ntime taken by quick sort=%lf",total_t);
  
   fprintf(c,"\n");
    for(i=0;i<x;i++)
    {
        printf("%d ",h[i]);
        fprintf(c,"%d\t",h[i]);
    }
    fclose(c);
  
   c=fopen("output.txt","a");
   fprintf(c,"\nmerge sort\n");
    start_t=clock();
    printf("\n%f",start_t);

    merge_sort(h,0,x-1);

    end_t=clock();
    printf("\n%f",end_t);
     total_t=((double)(end_t-start_t))/CLOCKS_PER_SEC;
    printf("\ntime taken=%lf\n",total_t);
     fprintf(l,"\ntime taken by merge sort=%lf",total_t);
     fprintf(c,"\n");
    for(i=0;i<x;i++)
    {
        printf("%d ",h[i]);
        fprintf(c,"%d\t",h[i]);
    }
    fclose(c);
     fclose(l);
    return 0;
}
void b_sort(int h[1000],int x)
{
    FILE *c,*l;
   c=fopen("output.txt","w");
   fprintf(c,"bubble sort\n");
   l=fopen("log.txt","a");
   fprintf(l,"\n");
    int i,j,temp;
   printf("bubble sort\n");
    for(i=0;i<x-1;i++)
    {
       for(j=0;j<x-i-1;j++)
       {
           if(h[j]>h[j+1])
           {
               temp=h[j];
               h[j]=h[j+1];
               h[j+1]=temp;
           }
       }
    }

    for(i=0;i<x;i++)
    {
        printf("%d ",h[i]);
        fprintf(c,"%d\t",h[i]);
    }
    fclose(c);
     fclose(l);
}
void slc_sort(int arr[1000],int x)
{
    FILE *c,*l;
   c=fopen("output.txt","a");
   fprintf(c,"\nselection sort\n");
   l=fopen("log.txt","a");
   fprintf(l,"\n");
   int i,j,min,temp;
   for(i=0;i<x-1;i++)
   {
       min=i;
       for(j=i+1;j<x;j++)
       {
           if(arr[j]<arr[min])
           {
               min=j;
           }
       }
       if(min!=i)
       {
           temp=arr[i];
           arr[i]=arr[min];
           arr[min]=temp;
       }
   }

   fprintf(c,"\n");
    for(i=0;i<x;i++)
    {
        printf("%d ",arr[i]);
        fprintf(c,"%d\t",arr[i]);
    }
    fclose(c);
     fclose(l);
}

void ins_sort(int arr[1000],int x)
{
    FILE *c,*l;
   c=fopen("output.txt","a");
  fprintf(c,"\ninsertion sort\n");
  l=fopen("log.txt","a");
   fprintf(l,"\n");
   int i,j,temp;
    clock_t start_t,end_t;
    start_t=clock();
     printf("\n%f",start_t);

    for(i=1;i<x;i++)
    {
       temp=arr[i];
       j=i-1;
       while(j>=0 && arr[j]>temp)
       {
           arr[j+1]=arr[j];
           j--;
       }
       arr[j+1]=temp;
    }
   fprintf(c,"\n");
    for(i=0;i<x;i++)
    {
        printf("%d ",arr[i]);
        fprintf(c,"%d\t",arr[i]);
    }
    fclose(c);
     fclose(l);
}

void qik_sort(int arr[1000],int lb,int ub)
{
    if(lb<ub)
     {
         int a=partition(arr,lb,ub);
         qik_sort(arr,lb,a-1);
         qik_sort(arr,a+1,ub);
     }
}

int partition(int arr[1000],int lb,int ub)
{
    int start,end,p,temp;
    p=arr[lb];
    start=lb;
    end=ub;
    while(start<end)
    {
        while(arr[start]<=p)
        {
            start++;
        }
         while(arr[end]>p)
        {
            end--;
        }
        if(start<end)
        {
            temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
    }
            temp=arr[lb];
            arr[lb]=arr[end];
            arr[end]=temp;
    return end;
}

void merge_sort(int arr[1000],int lb,int ub)
{
   if(lb<ub)
   {
       int m;
       m=(lb+ub)/2;
       merge_sort(arr,lb,m);
       merge_sort(arr,m+1,ub);
       merge(arr,lb,m,ub);
   }
}

void merge(int arr[1000],int lb,int mid,int ub)
{
    int i,j,k,b[1000];
    i=lb;
    j=mid+1;
    k=lb;
    while((i<=mid) && (j<=ub))
    {
        if(arr[i]<=arr[j])
        {
            b[k]=arr[i];
            i++;
        }
        else
        {
            b[k]=arr[j];
            j++;
        }
        k++;
    }
   while(i<=mid)
     b[k++]=arr[i++];
   while(j<=ub)
     b[k++]=arr[j++];
    for(k=lb;k<=ub;k++)
    {
        arr[k]=b[k];
    }
    printf("\n");
    for(k=lb;k<ub;k++)
    {
        printf("%d ",arr[k]);
    }
}

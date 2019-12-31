#include <stdio.h>
#include <stdlib.h>
int part(int a[],int l,int r);
void swap(int * ,int *);
void quicksort(int a[],int l,int r)
{
    if(l<r)
    {
        int s=part(a,l,r);
        quicksort(a,l,s-1);
        quicksort(a,s+1,r);
    }
}
int part(int a[],int l,int r)
{
    int i,j,p;
    p=a[l];
    i=l;
    j=r+1;
    do
    {
        do
        {
            i++;
        }while(a[i]<p);
        do
        {
            j--;
        }while(a[j]>p);
        swap(&a[i],&a[j]);
    }while(i<j);
    swap(&a[i],&a[j]);
    swap(&a[l],&a[j]);
    return j;
}
void swap(int *x,int *y)
{


    int temp=*x;
    *x=*y;
    *y=temp;
}

int main()
{
  int a[100],n,i;
  printf("Ente no\n");
   scanf("%d",&n);
   printf("Enter elemnts\n");
   for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    printf("After sorting\n");
   for(i=0;i<n;i++)
    printf("%d ",a[i]);
   return 0;
}

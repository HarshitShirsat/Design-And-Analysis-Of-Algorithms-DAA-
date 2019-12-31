#include <stdio.h>
#include <stdlib.h>

void merge(int b[],int c[],int a[],int p,int q)
{
    int i=0,j=0,k=0;
    while(i<p && j<q)
    {
        if(b[i]<=c[j])
        {
            a[k]=b[i];
            i++;
        }
        else
        {
            a[k]=c[j];
            j++;
        }
        k++;
    }
    if(i==p)
    {
        while(j<q && k<(p+q))
        {
            a[k]=c[j];
            j++;
            k++;
        }
    }

        else
        {
            while(i<p && k<(p+q))
            {
                a[k]=b[i];
                i++;
                k++;
            }
        }


}
  void mergesort(int a[],int n)
  {
      if(n>1)
      {
          int i,j,len;
          len=n/2;
          int b[len],c[n-len];
          for(i=0,j=0;i<len && j<len;i++,j++)
          {


            b[j]=a[i];
          }
          for(i=len,j=0;i<n && j<(n-len);i++,j++)
          {


            c[j]=a[i];
          }
          mergesort(b,len);
          mergesort(c,n-len);
          merge(b,c,a,len,n-len);
      }
  }

int main()
{

   int n,i,j,a[20];
   printf("Ente no\n");
   scanf("%d",&n);
   printf("Enter elemnts\n");
   for(i=0;i<n;i++)
    scanf("%d",&a[i]);
   mergesort(a,n);
   printf("After sorting\n");
   for(i=0;i<n;i++)
    printf("%d ",a[i]);
   return 0;
}

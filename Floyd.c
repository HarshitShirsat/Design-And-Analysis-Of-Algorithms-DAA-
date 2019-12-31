#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n,w[10][10],i,j,k,d[10][10],min;
   printf("Enter thr value of n\n");
   scanf("%d",&n);
   printf("Weight matrix\n");
   for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&w[i][j]);
   printf("weight mat is:\n");
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=n;j++)
       {
           printf("%d  ",w[i][j]);
       }
       printf("\n");
   }
   for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    d[i][j]=w[i][j];
   for(k=1;k<=n;k++)
   {
       for(i=1;i<=n;i++)
       {
           for(j=1;j<=n;j++)
           {
               if(d[i][j]<d[i][k]+d[k][j])
                min=d[i][j];
               else
                min=d[i][k]+d[k][j];
               d[i][j]=min;
           }
       }
   }
   printf("dist matrix:\n");
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=n;j++)
       {
           printf("%d ",d[i][j]);
       }
       printf("\n");
   }
   return 0;
}

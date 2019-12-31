#include <stdio.h>
#include <stdlib.h>

int a[10][10],b[10][10],n,e,root[10];
void update(int v1,int v2)
{
    int i,t;
    t=root[v2];
    for(i=1;i<=n;i++)
    {
        if(root[i]==t)
            root[i]=root[v1];
    }
}

void find(int *v1,int *v2)
{
    int edge=0,i,j;
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
    {
        if((edge>a[i][j] ||edge==0)&& a[i][j]>0)
        {
            edge=a[i][j];
            *v1=i;
            *v2=j;
        }
    }
}

int krus()
{
    int i,j,v1,v2,cost,total=0,ecounter=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
    {
        if(i==j)
            b[i][j]=0;
        else
            b[i][j]=999;
    }
    while(ecounter<(n-1))
    {
        find(&v1,&v2);
        cost=a[v1][v2];
        a[v1][v2]=a[v2][v1]=0;
        if(root[v1]!=root[v2])
        {
            b[v1][v2]=b[v2][v1]=cost;
            update(v1,v2);
            total=total+cost;
            ecounter++;
        }
    }
    return total;
}

int main()
{
 int i,j,v1,v2,cost;
   printf("Entet no of vert\n");
   scanf("%d",&n);
   printf("Enter the no of edges\n");
   scanf("%d",&e);
   for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
   {
       if(i==j)
        a[i][j]=0;
       else
        a[i][j]=999;
   }
   printf("Enter edges\n");
   for(i=1;i<=e;i++)
   {
       printf("Edge:%d",i);
       scanf("%d%d",&v1,&v2);
       printf("Weight:");
       scanf("%d",&cost);
       a[v1][v2]=a[v2][v1]=cost;

   }
   for(i=1;i<=n;i++)
    root[i]=i;
   cost=krus();
   printf("The given graph is\n");
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=n;j++)
        printf("%d ",a[i][j]);
       printf("\n");
   }
   printf("Min spanning tree is\n");
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=n;j++)
        printf("%d ",b[i][j]);
       printf("\n");
   }
   printf("Cost is:%d",cost);
   return 0;
}



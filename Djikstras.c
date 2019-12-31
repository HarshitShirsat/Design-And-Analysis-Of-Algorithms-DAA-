#include <stdio.h>
#include <stdlib.h>
int a[10][10],n,e,dist[10],visited[10];

int min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}

void dijkstra(int sv)
{
    int i,w,u,k,mini;
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        dist[i]=a[sv][i];
    }
    for(k=1;k<=n;k++)
    {
        mini=999;
        for(i=1;i<=n;i++)
        {
            if(dist[i]<mini && visited[i]==0)
            {
                u=i;
                mini=dist[i];
            }
        }
        visited[u]=1;
        for(w=1;w<=n;w++)
        {
            if(visited[w]==0)
                dist[w]=min(dist[w],dist[u]+a[u][w]);
        }
    }
}
void main()
{
    int i,j,v1,v2,cost,sv;
    printf("Enter n\n");
    scanf("%d",&n);
    printf("Enter e\n");
    scanf("%d",&e);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
    {
        if(i==j)
            a[i][j]=0;
        else
            a[i][j]=999;
    }
    printf("Enter edegs one by one\n");
    for(i=1;i<=e;i++)
    {
        printf("Edge: %d:",i);
        scanf("%d%d",&v1,&v2);
        printf("Weight: ");
        scanf("%d",&cost);
        a[v1][v2]=a[v2][v1]=cost;
    }
    printf("Enter starting vert\n");
    scanf("%d",&sv);
    dijkstra(sv);
    printf("The given graph is\n");
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=n;j++)
        printf("%d ",a[i][j]);
       printf("\n");
   }
   printf("Shortest dist from %d to:\n",sv);
   for(i=1;i<=n;i++)
   {
       printf("%d is %d\n",i,dist[i]);
   }
   return 0;
}



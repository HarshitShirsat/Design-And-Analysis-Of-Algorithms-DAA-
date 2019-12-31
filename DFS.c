#include <stdio.h>
#include <stdlib.h>
int n,visited[20],a[10][10];
void dfs(int v)
{
    int w,count=0;
    count++;
    visited[v]=count;
    printf("Reacged %d",v);
    for(w=1;w<=n;w++)
    {
        if(a[v][w]==1 && visited[w]==0)
        {
            dfs(w);
        }
    }
}

int main()
{
    int i,j,v1,v2,e,v;
     printf("Enter no of vert\n");
    scanf("%d",&n);
    printf("Enter no of edge\n");
    scanf("%d",&e);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        a[i][j]=0;

    printf("Enter edges one by one\n");
    for(i=1;i<=e;i++)
    {
        scanf("%d%d",&v1,&v2);
        a[v1][v2]=a[v2][v1]=1;
    }
    printf("Adjacency mat is:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    for(i=1;i<=n;i++)
        visited[i]=0;
    printf("Enter a vertex\n");
    scanf("%d",&v);
    dfs(v);
    return 0;
}


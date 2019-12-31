#include <stdio.h>
#include <stdlib.h>
int order[10],a[10][10],n,in[10],visited[10],e,k=0;
int isall()
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
            return 0;
    }
    return 1;
}
int main()
{
  int i,j,v1,v2,w;
  printf("enter no of vert\n");
  scanf("%d",&n);
  printf("No of edges\n");
  scanf("%d",&e);
  for(i=1;i<=n;i++)

      for(j=1;j<=n;j++)

          a[i][j]=0;


  for(i=1;i<=n;i++)
  {
      in[i]=0;
  }
  for(i=1;i<=n;i++)
  {
      visited[i]=0;
  }
printf("Enter edges one by one\n");
for(i=1;i<=e;i++)
{
    scanf("%d%d",&v1,&v2);
    a[v1][v2]=1;
}
for(i=1;i<=n;i++)
{
    for(j=1;j<=n;j++)
    {
        if(a[i][j]==1)
            in[j]=in[j]+1;
    }
}
while(1)
{
    if(isall())
        break;
    else
        for(i=1;i<=n;i++)
    {
        if(in[i]==0 && visited[i]==0)
        {
            order[k]=i;
            k++;
            visited[i]=1;
            for(w=1;w<=n;w++)
            {
                if(a[i][w]==1 && visited[w]==0)
                {
                    in[w]--;
                }
            }
        }
    }
}
printf("topologicl order is\n");
for(i=0;i<n;i++)
{
    printf("%d\t",order[i]);
}
return 0;
}

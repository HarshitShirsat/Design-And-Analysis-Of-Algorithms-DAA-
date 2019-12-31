#include <stdio.h>
#include <stdlib.h>
int n,w, val[10],wei[10],v[10][10];
int max(int i,int k)
{
    if(i>k)
        return i;
    else
        return k;

}
int knap(int i,int j)
{
    int value;
    if(v[i][j]<0)
    {
        if(j<wei[i])
            value=knap(i-1,j);
        else
            value=max(knap(i-1,j),val[i]+knap(i-1,j-wei[i]));
        v[i][j]=value;
    }
    return v[i][j];
}

int main()
{
    int i,j,value;
    printf("Enter no of items\n");
    scanf("%d",&n);
    printf("Enter capacity\n");
    scanf("%d",&w);
    printf("Enter values and weights\n");
    for(i=1;i<=n;i++)
    {
        printf("Item %d:",i);
        printf("Weight: ");
        scanf("%d",&wei[i]);
        printf("VAlue ");
        scanf("%d",&val[i]);
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=w;j++)
        {
            if(i==0 || j==0)
                v[i][j]=0;
            else
                v[i][j]=-1;
        }
    }
    value=knap(n,w);
    printf("Optimla sol:%d",value);
    printf("Items added are\n");
    for(i=n,j=w;i>0;i--)
    {
        if(v[i][j]!=v[i-1][j])
        {
            printf("%d ",i);
            j=j-wei[i];
        }
    }
    return 0;

}

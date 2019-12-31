#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10],n,i,j,min,temp;
     printf("Enetr no\n");
    scanf("%d",&n);
    printf("Enetr elemnts\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(i=0;i<n-1;i++)
        {
            min=i;
            for(j=i+1;j<n;j++)
            {
                if(a[j]<a[min])
                {


                    min=j;
                }
            }
                temp=a[i];
                a[i]=a[min];
                a[min]=temp;

        }
        printf("after sorting\n");
        for(i=0;i<n;i++)
            printf("%d ",a[i]);
        return 0;

}

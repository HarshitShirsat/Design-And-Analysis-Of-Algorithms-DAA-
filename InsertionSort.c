#include <stdio.h>
#include <stdlib.h>
#include<sys/time.h>
int main()
{
    struct timeval tim;
    double dtim1,dtim2;
  int i,j,a[20],n,v;
  printf("Enter np\n");
  scanf("%d",&n);
  printf("Elements\n");
  for(i=0;i<n;i++)
    {
    a[i]=rand()%100;
    printf("%d ",a[i]);
}
gettimeofday(&tim,NULL);
dtim1=tim.tv_sec+(tim.tv_usec/1000000.0);
 for(i=1;i<n;i++)
  {
      v=a[i];

      j=i-1;
      while(j>=0 && a[j]>v)
      {
          a[j+1]=a[j];
          j=j-1;
      }
      a[j+1]=v;
  }
  gettimeofday(&tim,NULL);
dtim2=tim.tv_sec+(tim.tv_usec/1000000.0);
  printf("After sorting\n");
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("Elapsed time is %lf",dtim2-dtim1);
  return 0;
}


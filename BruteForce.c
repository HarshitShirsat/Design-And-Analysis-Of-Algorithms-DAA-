#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char p[20],t[20];
    int i,j,n,m;
    printf("Enter the text\n");
    gets(t);
    printf("Enter pattern\n");
    gets(p);
    n=strlen(t);
    m=strlen(p);
    for(i=0;i<=(n-m);i++)
    {
        j=0;
        while(j<m && p[j]==t[i+j])



            j=j+1;

        if(j==m)
        {
            printf("Pattern found at %d",i+1);
            exit(0);
        }
    }



    printf("Pattern not found");
    return 0;

}

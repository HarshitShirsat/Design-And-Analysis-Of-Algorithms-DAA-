#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char p[100],t[100];
int m,n;
int table[250];
void shift()
{
    int i,j;
    for(i=0;i<250;i++)
        table[i]=m;
    for(j=0;j<m-1;j++)
        table[p[j]]=m-1-j;
}
int horspool()
{
    int i,k;
    shift();
    i=m-1;
    while(i<=n-1)
    {
        k=0;
        while(k<=m-1 && p[m-1-k]==t[i-k])
            k=k+1;
        if(k==m)
            return i-m+1;
        else
            i=i+table[t[i]];
    }
    return -1;
}
int main()
{
    int pos;
    printf("Text\n");
    gets(t);
    printf("Pattern\n");
    gets(p);
    m=strlen(p);
    n=strlen(t);
    pos=horspool();
    if(pos==-1)
        printf("Pattern not found ");
    else
        printf("Pattern found at %d",pos+1);
    return 0;
}

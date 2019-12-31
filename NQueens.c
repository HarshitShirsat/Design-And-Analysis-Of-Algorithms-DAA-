#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int place(int k, int a[])
{
 int i;
	for(i=1;i<=k-1;i++) //check whether two queen attach vertically or diagonally
	{
		if( (a[k]==a[i]) || ( abs(i-k) == abs(a[i]-a[k]) ) )
		     return 0; //Queen cannot be placed in kth column
	}
	return 1;
}

int NQueens(int n)
{
 int k=1; 	// Select first queen->queen 1 in row 1
 int count=0;   // count indicates the no of solutions
 int i;
 int a[10];
 a[k]=0; //Queen 1, in row 1, column 0
             //Queen selected but not placed

 while(k!=0) //backtrack till k=1 i.e. queen exists
 {
   a[k]=a[k]+1; //place kth queen in next column

   while( (a[k]<=n) && (place(k, a)==0) )
   {
	a[k]=a[k]+1; //place queen in next column
   }
//if queen successfully placed ?
   if(a[k]<=n)
   {
	if(k==n)          //if all queens are placed
	{
		count++;
		printf("Solution No %d:\n", count);
		for(i=1;i<=n;i++)
		{
		printf("Queen No: %d is placed in  Row No: %d  and Column No %d\n", i, i,a[i]);
		}
	}
	else

{
		k++;   //select the next queen
		a[k]=0; //but do not place
	}
   }
   else
   {
	k--;     //backtrack & select previous queen
   }
}
return count;
}
void main()
{
 int n,noofsoln;
 printf("Enter the number of queens\n");
 scanf("%d",&n);
 noofsoln=NQueens(n);
 if(noofsoln==0)
	printf("No Solution!!!");
 return 0;
}


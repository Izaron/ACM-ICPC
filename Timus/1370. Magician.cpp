// The solution of the problem was written by Izaron
// Date: 00:29:56   3 May 2015
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include<stdio.h>
int main()
{
    int N,M,a[1000],i;
    scanf("%d %d",&N,&M);
    for(i=0;i<N;i++)scanf("%d",&a[i]);
    for(i=M;i<M+10;i++)printf("%d",a[i%N]);
}
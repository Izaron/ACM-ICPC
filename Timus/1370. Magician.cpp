#include<stdio.h>
int main()
{
    int N,M,a[1000],i;
    scanf("%d %d",&N,&M);
    for(i=0;i<N;i++)scanf("%d",&a[i]);
    for(i=M;i<M+10;i++)printf("%d",a[i%N]);
}
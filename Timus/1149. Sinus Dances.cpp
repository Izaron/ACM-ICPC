#include<stdio.h>
main()
{
    int n,i,j;
    scanf("%i",&n);
    for(i=1;i<n;i++) printf("(");
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=i;j++)
      {
         if(j>1)
           printf((j&1)?"+":"-");
         printf("sin(%i",j);
      }
      for(j=1;j<=i;j++)printf(")");
      printf("+%i",n+1-i);
      if(i!=n)printf(")");
    }
}
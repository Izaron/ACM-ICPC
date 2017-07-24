// The solution of the problem was written by Izaron
// Date: 10:36:15   18 Mar 2015
// Execution time: 0.953

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <stdio.h>
int main()
{
      long i=3;
      long long a;
      scanf("%I64d",&a);
      while (a%i!=0)
        i++;
      printf("%ld",i-1);
      return 0;
}
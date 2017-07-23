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
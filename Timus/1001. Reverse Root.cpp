#include <stdio.h>
#include <math.h>
double stack[131073];
int main()
{
    int index = -1;
    while(scanf("%lf", &stack[++index]) != EOF);
    for(; index > 0;printf("%.4lf\n", sqrt(stack[--index])));
    return 0;
}
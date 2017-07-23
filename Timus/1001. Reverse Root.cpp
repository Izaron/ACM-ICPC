// The solution of the problem was written by Izaron
// Date: 18:43:47   19 Feb 2015
// Execution time: 0.203

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

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
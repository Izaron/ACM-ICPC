// The solution of the problem was written by Izaron
// Date: 23:23:09   22 May 2015
// Execution time: 0.031

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int p = 10000;
double xs, ys;
int x, y, ans;

int main(void)
{
    scanf ("%lf%lf", &xs, &ys);
    ans = 1, x = y = 0;
    ys -= 1E-10, xs += 1E-10;
    while (x == y)
          ans++, x = int (ans * xs) / 100, y = int (ans * (ys)) / 100;
    printf ("%d", ans);
    return 0;
}
// The solution of the problem was written by Izaron
// Date: 00:37:54   3 May 2015
// Execution time: 0.031

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <math.h>
#include <iostream>
using namespace std;
void P(long& x, long& y)
{
  int i, j;
  if (x>0 && y>0)
  {
    for (i = 1; i <= x+y; i++)
    {
      y = x*x+y;
      x = x*x+y;
      y = (long)sqrt((long double)x+(long double)(y/labs(y))*(-labs(y)));
      x = x - 2*y*y;
    }
  }
}

int main() 
{
   long int x, y;
   cin >> x >> y;
   P(x,y);
   cout << x << " " << y;
}
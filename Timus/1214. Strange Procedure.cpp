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
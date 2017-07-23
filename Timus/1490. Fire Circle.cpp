// The solution of the problem was written by Izaron
// Date: 14:35:42   18 Jul 2015
// Execution time: 0.001

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include<iostream>
using namespace std;
int main()
{
  long long int x,y=0,z=0,q,p,r;
  cin>>r;
  x=r;
  q=r*r;
 while(y<r)
 {
   p=q-y*y;
    while( x*x >= p && x >= 0 )--x;
   z+=(x+1);
   y++;
 }
  z*=4;
  cout<<z;
return 0;
}
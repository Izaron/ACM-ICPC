// The solution of the problem was written by Izaron
// Date: 21:47:49   13 May 2015
// Execution time: 0.031

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
using namespace std;

int main() {
int n;
cin >> n;
cout << 2 * n - 1 << endl;
for(int i = 1; i <= n; i++) cout << i << " ";
for(int i = n; i > 1; i--) cout << i << " ";
}
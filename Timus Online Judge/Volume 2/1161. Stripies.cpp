// The solution of the problem was written by Izaron
// Date: 16:50:46   29 Apr 2015
// Execution time: 0.031

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
vector <float> weights;
int n;
float def(int ind);

int main()
{
    int i;
    float f;
    cout.precision(2);
    cin >> n;
    for(i = 0; i < n; ++i)
    {
        cin >> f;
        weights.push_back(f);
    }
    sort(weights.begin(), weights.end());
    cout << fixed << def(0);
    return 0;
}

float def(int ind)
{
    if(ind >= n - 1)
        return weights[ind];
    else
        return 2 * sqrt(weights[ind] * def(ind + 1));
}
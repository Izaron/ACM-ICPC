// The solution of the problem was written by Izaron
// Date: 14:01:05   22 Aug 2016
// Execution time: 0.982

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <stdio.h>
#include <random>
#include <string.h>
#include <iostream>
#include <map>
#include <vector>
#include <bitset>
#define pb push_back
#define ins insert
#define mkp make_pair
#define mt make_tuple
using namespace std;

typedef long long int ll;
typedef long double ld;

const int maxn = 3000 + 5;

int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    int k, n;
    scanf("%d", &k);
    int p, q;
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &n);
        p = 0; q = 0;
        if (n % 2 == 0) {
            p = 2;
            q = n / 2;
        } else for (int z = 3; z < n; z += 2)
        {
            if (n % z == 0)
            {
                p = z;
                q = n / z;
                break;
            }
        }
        if (q < p)
            swap(q, p);
        printf("0 1 ");
        for (ll x = q; x < n; x += q)
        {
            ll y = x - 1;
            if ((x * y) % n == 0 && x < n)
                printf("%d ", (int)x);
            y = x + 1;
            if ((x * y) % n == 0 && y < n)
                printf("%d ", (int)y);
        }
        printf("\n");
    }
}

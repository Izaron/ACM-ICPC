#include <iostream>
#include <math.h>
using namespace std;

double len_points(double x1, double x2, double y1, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    const double pi = 3.14159;
    double sum = 0, arr[101][2], r;
    int n;

    cin>>n>>r;
    for(int i = 0; i < n; ++i)
        cin>>arr[i][0]>>arr[i][1];

    for(int i = 0; i < (n - 1); ++i)
        sum += len_points(arr[i][0], arr[i + 1][0], arr[i][1], arr[i + 1][1]);

    sum += len_points(arr[0][0], arr[n - 1][0], arr[0][1], arr[n - 1][1]) + 2 * pi * r;
    printf("%.2lf", sum);

    return 0;
}
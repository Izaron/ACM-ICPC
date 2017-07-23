// The solution of the problem was written by Izaron
// Date: 16:53:03   29 Apr 2015
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>

using namespace std;

const int MAX=1002;
const double Dc=141.42135623730950488016887242097;
const double Dl=100.0;
const double INF=1e20;

struct Point
{
    int x,y;
};

int M,N,P;
Point T[MAX];
int F[MAX];
double Ans;

inline int cmp(const void *a,const void *b)
{
    if (((Point *)a)->x==((Point *)b)->x && ((Point *)a)->y<((Point *)b)->y)
        return -1;
    return ((Point *)a)->x < ((Point *)b)->x ?-1 :1;
}

void init()
{
    int i,a,b;
    cin >> M >> N >> P;
    N++;M++;
    for (i=1;i<=P;i++)
    {
        cin >> b >> a;
        a++;b++;
        T[i].x=a;
        T[i].y=b;
    }
    qsort(T+1,P,sizeof(T[0]),cmp);
}

void dynamic()
{
    int i,j,max,cnt=0,d;
    for (i=1;i<=P;i++)
    {
        max=0;
        for (j=0;j<=i-1;j++)
        {
            if (T[j].x<T[i].x && T[j].y<T[i].y &&  F[j] + 1 > max)
                max=F[j]+1;
        }
        F[i]=max;
        if (F[i]>cnt)
            cnt=F[i];
    }
    d=N+M-cnt*2-2;
    Ans=d*Dl + cnt*Dc;
    printf("%.0lf",Ans);
}

int main()
{
    init();
    dynamic();
    return 0;
}
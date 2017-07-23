#include <bits/stdc++.h>
using namespace std;

#define mt make_tuple
#define mkp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define pss pair<int,int>
#define pdd pair<double,double>
#define pff pair<float,float>
#define piii pair<ll, pair<ll,ll> >
#define pddd pair<ld, pair<ld,ld> >
#define ff first
#define ss second
typedef long long int ll;
typedef long double ld;

struct Point
{
    long double x;
    long double y;
};
struct Point2
{
    int number;
    long double angle;
};
void insertSort(Point2 ** a, long size) {
  Point2 * x;
  long i, j;

  for ( i=0; i < size; i++) {  // цикл проходов, i - номер прохода
    x = a[i];

    // поиск места элемента в готовой последовательности
    for ( j=i-1; j>=0 && (a[j]->angle < x->angle); j--)
      a[j+1] = a[j];      // сдвигаем элемент направо, пока не дошли

    // место найдено, вставить элемент
    a[j+1] = x;
  }
}
/*
int compare( const void *arg1, const void *arg2 )
{
   if(((Point2*)arg1)->angle>((Point2*)arg2)->angle)
       return -1;
   else
        return 1;

}*/
int main()
{

    int n;
    cin>>n;
    Point * arr = new Point[n];
    long double min_a=0;
    int min_ai;
    for(int i = 0;i<n;++i)
    {
        cin>>arr[i].x;
        cin>>arr[i].y;
        if((!i)||arr[i].y<min_a)
        {
            min_a = arr[i].y;
            min_ai = i;
        }
    }
    cout<<min_ai+1<<" ";
    Point2 ** arr2 = new Point2*[n-1];
    int j = 0;
    long double xx = arr[min_ai].x;
    long double yy = arr[min_ai].y;
    for(int i = 0;i<n;++i)
    {
        if(i!=min_ai)
        {
            arr2[j] = new Point2;
            arr2[j]->number = i;
            arr2[j]->angle =  (arr[i].x - xx)/sqrt(pow(arr[i].x-xx,2)+pow(arr[i].y-yy,2));
            ++j;

        }
    }
    //qsort(arr2,n-1,4,compare);
    insertSort(arr2,n-1);
    cout<<arr2[(n-1)/2]->number+1<<endl;
    return 0;
}
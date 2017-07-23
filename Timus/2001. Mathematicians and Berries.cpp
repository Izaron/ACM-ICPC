#include <iostream>
using namespace std;

int main()
{
    int a[3];
    int b[3];
    int sum,m1,m2;
    cin>>a[0]>>b[0];
    if(a[0]<0||b[0]<0||a[0]>10000||b[0]>10000) exit(1);
    sum=a[0]+b[0];

    cin>>a[1]>>b[1];
    if(a[1]<0||b[1]<0||a[1]>10000||b[1]>10000) exit(1);
    if(b[1]>b[0]||(a[1]+b[1]!=sum))exit(1);

    cin>>a[2]>>b[2];
    if(a[2]<0||b[2]<0||a[2]>10000||b[2]>10000) exit(1);
    if(a[2]>a[0]||(a[2]+b[2]!=sum))exit(1);
    m1=a[0]-a[2];
    m2=b[0]-b[1];

    cout<<m1<<' '<<m2;
    return 0;
}

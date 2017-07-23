#include <iostream>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int m=n/k + ((n%k==0) ? 0:1);

    int * A=new int [m*k];
    for (int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for (int i=n;i<m*k;i++)
        A[i]=-1;

    for (int i=0;i<m;i++)
    {
        for (int j=0;j<k;j++)
        {
            int h=j*m+i;
            if (A[h]<0)
                cout<<"    ";
            if (A[h]>-1 && A[h]<10)
                cout<<"   "<<A[h];
            if (A[h]>9 && A[h]<100)
                cout<<"  "<<A[h];
            if (A[h]>99 && A[h]<1000)
                cout<<" "<<A[h];
        }
        cout<<endl;
    }

    return 0;
}
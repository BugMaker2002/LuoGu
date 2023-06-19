#include <iostream>
using namespace std;
long long a[100100],b[100100];
int main()
{
    int n,m;
    long long x;
    cin>>n>>m>>x;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    for (int i = 0; i < n; i++)
    {
        int t = x - a[i];
        //二分
        int l=0,r=m-1;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(b[mid]>=t)r=mid;
            else l=mid+1;
        }
        if(b[l]==t)
        {
            cout<<i<<" "<<l;
            break;
        }
    }
}
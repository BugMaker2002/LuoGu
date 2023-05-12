#include <iostream>
#include <cmath>
using namespace std;
int a[1025][1025]={0};
int set(int s,int t,int x)
{
    if (x/2==0)
    {
        return 0;
    }
    for(int i=0;i<x/2;i++)
    {
        for(int j=0;j<x/2;j++)
        {
            a[s+i][t+j]=1;
        }
    }
    set(s,t+x/2,x/2);
    set(s+x/2,t,x/2);
    set(s+x/2,t+x/2,x/2);
    return 0;
}
int main()
{
     int n;
     cin>>n;
     set(1,1,pow(2,n));
     for(int i=1;i<=pow(2,n);i++)
     {
         for(int j=1;j<=pow(2,n);j++)
         {
             cout<<1-a[i][j]<<" ";
         }
         cout<<endl;
     }
}
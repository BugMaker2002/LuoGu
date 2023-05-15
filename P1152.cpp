#include <iostream>
#include <cmath>
using namespace std;
long long a[1003];
long long b[1003]={0};
int main()
{
    long long n;
    cin>>n;
    for (long long i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (long long i = 0; i < n-1; i++)
    {
        if (abs(a[i]-a[i+1])<=n-1 && abs(a[i]-a[i+1])>=1)
        {
           b[abs(a[i]-a[i+1])]++;
        }
    }
    for (long long i = 1; i <= n-1; i++)
    {
        if (b[i]==0)
        {
            cout<<"Not jolly";
            return 0;
        }
    }
    cout<<"Jolly";
}
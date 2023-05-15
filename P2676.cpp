#include <iostream>
#include <algorithm>
using namespace std;
long long a[20005];
int main()
{
    int n;
    long long B;
    long long max=0;
    cin>>n>>B;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for (int i = n-1; i >= 0; i--)
    {
        if (max<B)
        {
            max+=a[i];
        }
        else
        {
            cout<<n-1-i;
            break;
        }
    }

}
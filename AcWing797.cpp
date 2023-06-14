#include <iostream>
using namespace std;
int a[100010],s[100010];
int main()
{
    int n,m,l,r,c;
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        cin>>s[i];
        a[i]=s[i]-s[i-1];
    }
    while (m-->0)
    {
        cin>>l>>r>>c;
        a[l]+=c;
        a[r+1]-=c;
    }
    for (int i = 1; i <= n; i++)
    {
        s[i]=s[i-1]+a[i];
        cout<<s[i]<<" ";
    }
}
#include <iostream>
using namespace std;
int a[100010];
int s[100010];
int main()
{
    int n,m;
    int l,r;
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
        s[i] = s[i-1] + a[i];
    }
    while(m-->0)
    {
        cin>>l>>r;
        cout<<s[r]-s[l-1]<<endl;
    }
}
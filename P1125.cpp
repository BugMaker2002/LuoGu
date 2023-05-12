#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin>>s;
    int a[26]={0};
    for (int i = 0; i < s.length(); i++)
    {
        int k=s[i]-'a';
        a[k]++;
    }
    sort(a,a+26);
    int n;
    for (int i = 0; i < sizeof(a)/sizeof(int); i++)
    {
        if (a[i]!=0)
        {
           n=a[25]-a[i];
           break;
        }
    }
    bool alpha=true;
    for (int i = 2; i*i <= n; i++)
    {
        if (n%i==0)
        {
            alpha=false;
        }
    }
    if ((alpha)&&(n!=0)&&(n!=1))
    {
        cout<<"Lucky Word"<<endl<<n;
    }
    else
    {
        cout<<"No Answer"<<endl<<0;
    }
}
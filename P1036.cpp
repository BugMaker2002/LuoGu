#include <iostream>
using namespace std;
int n,k,a[22],ans=0;
int isPrime(int n)
{
    if (n==1)
    {
        return false;
    }
    if (n==2)
    {
        return true;
    }
    for (int i = 2; i*i <= n; i++)
    {
        if (n%i==0)
        {
            return false;
        }
    }
    return true;
}
void dfs(int m,int sum,int startx)
{
    if (m==k)
    {
        if (isPrime(sum))
        {
            ans++;
        }
        return;
    }
    for (int i = startx; i <= n; i++)
    {
        dfs(m+1,sum+a[i],i+1);
    }
    return;
}
int main()
{   
    cin>>n>>k;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    dfs(0,0,1);
    cout<<ans;
}
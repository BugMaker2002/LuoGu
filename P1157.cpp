#include <iostream>
#include <iomanip>
using namespace std;
int n,r;
int a[22];
void dfs(int k)
{
    if(k>r)
    {
        for (int i = 1; i <= r; i++)
        {
            cout<<setw(3)<<a[i];
        }
        cout<<endl;
        return;
    }
    for (int i = a[k-1]+1; i <= n; i++)
    {
        a[k]=i;
        dfs(k+1);
    }
}
int main()
{
    cin>>n>>r;
    dfs(1);
}
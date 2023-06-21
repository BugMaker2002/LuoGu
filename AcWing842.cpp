#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int pd[10];
int used[11];
int n;
void dfs(int k)
{
    if(k==n)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<used[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!pd[i])
        {
            pd[i]=1;
            used[k+1]=i;
            dfs(k+1);
            pd[i]=0;
        }
    }
}
int main()
{
    cin>>n;
    dfs(0);
}
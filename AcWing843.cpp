#include <iostream>
using namespace std;
int n;
char g[10][10];
//col数组是记录列数，dg数组是记录对角线被使用的情况，
//udg数组是记录反对角线被使用的情况
bool col[20],dg[20],udg[20];
void dfs(int u)
{
    if (u==n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<g[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    //由u确定行数，此处是遍历每一列
    for (int i = 0; i < n; i++)
    {
        if (!col[i] && !dg[u+i] && !udg[n-u+i])
        {
            g[u][i]='Q';
            col[i]=dg[u+i]=udg[n-u+i]=true;
            dfs(u+1);
            col[i]=dg[u+i]=udg[n-u+i]=false;
            g[u][i]='.';
        }
    }
}
int main()
{
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g[i][j] = '.';
        }
    }
    dfs(0);
}
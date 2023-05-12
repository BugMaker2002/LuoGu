#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    char pos[103][103];
    int dis[103][103];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin>>pos[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pos[i][j]=='*')
            {
                dis[i][j] =(int)'*';
            }
            else if (pos[i][j]=='?')
            {
                int sum=0;
                if (pos[i-1][j-1]=='*')
                {
                    sum++;
                }
                if (pos[i-1][j]=='*')
                {
                    sum++;
                }
                if (pos[i-1][j+1]=='*')
                {
                    sum++;
                }
                if (pos[i][j-1]=='*')
                {
                    sum++;
                }
                if (pos[i][j+1]=='*')
                {
                    sum++;
                }
                if (pos[i+1][j-1]=='*')
                {
                    sum++;
                }
                if (pos[i+1][j]=='*')
                {
                    sum++;
                }
                if (pos[i+1][j+1]=='*')
                {
                    sum++;
                }
                dis[i][j] = sum;
            }
            
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (dis[i][j]>8)
            {
                cout<<"*";
            }
            else
            {
                cout<<dis[i][j];
            }
        }
        cout<<endl;
    }
}
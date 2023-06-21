#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
//g数组用于记录图上每个点到(0,0)点的最短距离，比如g[1][1]=1，表示(1,1)点距(0,0)点最短距离为1
int d[110][110],g[110][110];
int n,m;
int bfs()
{
    //队列q记录当前被放入的点的坐标
    queue<pair<int,int>>q;
    q.push({0,0});
    memset(g,-1,sizeof(g));
    g[0][0]=0;
    while (q.size()!=0)
    {
        pair<int,int>item=q.front();//取队头
        q.pop();//队头出队
        //记录向↑、→、↓、←四个方向移动时x和y坐标应采取的动作，比如加一减一啥的,方便代码的书写
        int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
        //bfs的核心步骤，记录四个方向的动作（向四周扩展）
        for (int i = 0; i < 4; i++)
        {
            int x=item.first+dx[i];
            int y=item.second+dy[i];
            //判断x,y是否满足题意
            if (x>=0 && x<n && y>=0 && y<m && d[x][y]==0 && g[x][y]==-1)
            {
                //新节点入队
                q.push({x,y});
                d[x][y]=d[item.first][item.second]+1;
            }
        }
    }
    return d[n-1][m-1];
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>d[i][j];
        }
    }
    cout<<bfs();
}
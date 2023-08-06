#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 110;

typedef pair<int, int> PII;

int n, m;
int g[N][N], d[N][N];

int bfs()
{
    queue< pair<int, int> > q;

    q.push({0, 0});

    memset(d, -1, sizeof(d));

    d[0][0] = 0;

    //记录向↑、→、↓、←四个方向移动时x和y坐标应采取的动作，比如加一减一啥的,方便代码的书写
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (q.size())//队列不为空
    {
        PII t = q.front();//取队头元素

        q.pop();//出队

        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            //bfs的核心步骤，记录四个方向的动作（向四周扩展）
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;//当前点到起点的距离
                q.push({x, y});//将新坐标入队
            }
        }
    }

    return d[n - 1][m -1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    cout << bfs() << endl;

    return 0;
}

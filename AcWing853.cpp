#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int N = 510;
const int M = 10100;
int n, m, k, x, y, z;
int dist[N], backup[N];
struct Edge
{
    int x;
    int y;
    int z;
}edges[M];
void Bellman_Ford()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for(int i = 0; i < k; i++)
    {
         memcpy(backup, dist, sizeof(dist));
         for (int j = 1; j <= m; j++)
         {
            int x = edges[j].x;
            int y = edges[j].y;
            int z = edges[j].z;
            //建立一个备份数组防止串联
            dist[y] = min(dist[y], backup[x] + z);
         }
    }
    //记住是判断0x3f3f3f3f3 / 2就行
    if (dist[n] > 0x3f3f3f3f / 2)
    {
        cout<<"impossible"<<endl;
    }
    else
    {
        cout<<dist[n]<<endl;
    }
}
int main()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        cin >> x >> y >> z;
        edges[i] = {x, y, z};
    }
    Bellman_Ford();
}
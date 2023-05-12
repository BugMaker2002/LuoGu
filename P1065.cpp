#include <iostream>
using namespace std;
/**
 * @brief 
 * 表示每个工件对应的每个工序的信息，即所在的机器号和花费的时间
 */
struct information
{
    int id;
    int cost;
}info[22][22];
/**
 * @brief 
 * 记录顺序
 */
int list[404]={0};
/**
 * @brief 
 * 记录每个工件此时到达的步骤
 */
int step[22]={0};
/**
 * @brief 
 * 记录每个工件上一个步骤的结束时间
 */
int last_time[22]={0};
/**
 * @brief 
 * 记录每台机器的时间轴
 */
int mac[22][100000]={0};
/**
 * @brief 
 * 最终的答案
 */
int ans=0;
int main()
{
    int m,n;
    cin>>m>>n;
    for (int i = 1; i <= m*n; i++)
    {
        cin>>list[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin>>info[i][j].id;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin>>info[i][j].cost;
        }
    }
    for (int i = 1; i <= m*n; i++)
    {
        int now=list[i];
        step[now]++;
        int machine=info[now][step[now]].id;
        int time=info[now][step[now]].cost;
        int s=0;
        for (int j = last_time[now] + 1; ; j++)
        {
            if (mac[machine][j]==0)
            {
                s++;
            }
            else
            {
                s=0;
            }
            if (s==time)
            {
                for (int k = j-time+1; k <= j; k++)
                {
                    mac[machine][k]=1;
                }
                if (j>ans)
                {
                    ans=j;
                }
                last_time[now]=j;
                break;
            }
        }
    }
    cout<<ans;
}
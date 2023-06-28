#include <iostream>
using namespace std;
const int N = 1000100;
int a[N], q[N], hh, tt = -1;
//q数组存放的是单调队列，队头为当前窗口最小值的下标
//注意：q数组存放的是下标！不是具体的值！
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        //i表示当前元素的下标，q[hh]表示队列当中最小元素
        //的下标，如果它们之差大于k - 1，则说明当前维护的最小值
        //已经不在我们要求的滑动区间范围内了，应该出队头
        if(i + 1 - k > q[hh])
        {
            ++ hh;
        }
        while (hh <= tt && a[i] <= a[q[tt]])
        {
            -- tt;
        }
        //此步一定要放在cout之前，因为如果hh = 0,tt = -1,那
        //这样的话q[hh]的值是会被q[++ tt] = i;修改的
        q[++ tt] = i;
        if(i + 1 >= k) cout << a[q[hh]] << " ";
    }
    cout << endl;
    //记得重置hh和tt
    hh = 0;
    tt = -1;
    //求最大值，与上述相同，只用改为a[i] >= a[q[tt]]即可
    for (int i = 0; i < n; i++)
    {
        if(i + 1 - k > q[hh])
        {
            ++ hh;
        }
        while (hh <= tt && a[i] >= a[q[tt]])
        {
            -- tt;
        }
        q[++ tt] = i;
        if(i + 1 >= k) cout << a[q[hh]] << " ";
    }
}
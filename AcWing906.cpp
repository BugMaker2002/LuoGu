#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 100010;
struct Range
{
    int l, r;
}range[N];
bool compare(Range r1, Range r2)
{
    return r1.l < r2.l;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }
    //按左端点的值从小到大排序
    sort(range, range + n, compare);
    //维护一个存放各个组的最右端点的最小值堆
    priority_queue<int, vector<int>, greater<int>>heap;
    for (int i = 0; i < n; i++)
    {
        //堆为空或者不能放到某个现有的组当中(有重叠)
        //注意是大于等于，不是大于！
        if(heap.empty() || heap.top() >= range[i].l)
        {
            heap.push(range[i].r);
        }
        //可以放到某个现有的组当中
        else
        {
            heap.pop();
            heap.push(range[i].r);
        }
    }
    cout << heap.size() << endl;
}
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 100010;
struct Range
{
    int l, r;
}range[N];
bool compare(Range r1, Range r2)
{
    return r1.r < r2.r;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }
    sort(range, range + n, compare);
    //将初始右端点置为负无穷
    int res = 0, ed = -2e9;
    for (int i = 0; i < n; i++)
    {
        if(range[i].l > ed)
        {
            res ++;
            ed = range[i].r;
        }
    }
    cout << res << endl;
}
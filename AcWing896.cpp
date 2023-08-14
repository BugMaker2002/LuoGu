#include <iostream>
using namespace std;
const int N = 100010;
//a数组正常存放元素，q[i]表示在所有长度为i的子序列当中
//末尾元素的最小值
int a[N], q[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int len = 0;
    //q[0]存放的数后面不会改变，存放的是无穷小
    q[0] = -2e9;
    for (int i = 1; i <= n; i++)
    {
        //从q数组的0~len区间范围内找数
        int l = 0, r = len;
        while(l < r)
        {
            int mid = (l + r + 1) / 2;
            if(q[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        //为什么是max而不是len = r + 1？
        //假设如果q数组元素是-2e9、0、2、8这种情况的话，此时
        //len = 3，如果我们遍历到了a[i] = 1；那我们二分q
        //数组应该得出最大小于a[i]数的下标为r = 0；
        //我们应q[r + 1] = 1，如果len = r + 1那肯定不对，
        //len应保持为3，所以len每次应该取max(len, r + 1);
        len = max(len, r + 1);
        //q[r]是数组q当中最大的小于a[i]的数
        //所以我们需要将q[r + 1]更新成为a[i]
        //不用去管q[r + 2]，因为q[r + 2]必定大于a[i]，否则
        //我们二分找到的数就不是r了
        q[r + 1] = a[i];
    }
    cout << len;
}
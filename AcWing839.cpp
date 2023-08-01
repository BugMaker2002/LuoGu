#include <iostream>
using namespace std;
const int N = 100100;
/**
 * h数组用于记录二叉树每个位置的值
 * hp数组用于记录每个位置的初始插入顺序（题目要求特殊）
 * ph数组用于记录第k个插入的元素在二叉树当中的位置
 * hp和ph数组互为映射，为反函数
 */
int h[N], hp[N], ph[N];
//m为当前插入的次序，cur_size为二叉树当中元素的个数，m和cur_size
//不一定相等，因为有删除操作会导致cur_size变小
int m, cur_size;
/**
 * @brief 区别于普通的交换，本题当中交换时
 * h、hp、ph数组都得考虑，u和t是二叉树当中元素的位置
 * @param u 
 * @param t 
 */
void heap_swap(int u, int t)
{
    swap(h[u], h[t]);
    swap(hp[u], hp[t]);
    swap(ph[hp[u]], ph[hp[t]]);
}
void down(int i)
{
    int u = i;
    if (2 * i <= cur_size && h[u] > h[2 * i])
    {
        u = 2 * i;
    }
    if (2 * i + 1 <= cur_size && h[u] > h[2 * i + 1])
    {
        u = 2 * i + 1;
    }
    if (u != i)
    {
        heap_swap(u, i);
        down(u);
    }
}
void up(int i)
{
    while (i / 2 && h[i] < h[i / 2])
    {
        heap_swap(i, i / 2);
        i /= 2;
    }
}
int main()
{
    int n;
    cin >> n;
    while (n --)
    {
        string s;
        cin >> s;
        if(s == "I")
        {
            int x;
            cin >> x;
            h[++ cur_size] = x;
            m ++;
            hp[cur_size] = m;
            ph[m] = cur_size;
            //别忘了这一步
            up(cur_size);
        }
        else if (s == "PM")
        {
            cout << h[1] << endl;
        }
        else if (s == "DM")
        {
            //这里得是heap_swap，不能是h[1] = h[cur_size]
            heap_swap(1, cur_size);
            cur_size --;
            down(1);
        }
        else if (s == "D")
        {
            int k;
            cin >> k;
            int u = ph[k];
            //这里得是heap_swap，不能是h[u] = h[cur_size]
            heap_swap(u, cur_size);
            cur_size --;
            down(u);
            up(u);
        }
        else if (s == "C")
        {
            int k, x;
            cin >> k >> x;
            int u = ph[k];
            h[u] = x;
            down(u);
            up(u);
        }
    }
}
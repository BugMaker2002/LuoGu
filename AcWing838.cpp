#include <iostream>
using namespace std;
const int N = 100100;
int n, m, heap[N], _size;
void down(int i)
{
    int u = i;
    if (2 * i <= _size && heap[u] > heap[2 * i])
    {
        u = 2 * i;
    }
    if (2 * i + 1 <= _size && heap[u] > heap[2 * i + 1])
    {
        u = 2 * i + 1;
    }
    if(u != i)
    {
        swap(heap[u], heap[i]);
        down(u);
    }
}
void up(int i)
{
    while(i / 2 && heap[i / 2] > heap[i])
    {
        swap(heap[i], heap[i / 2]);
        i /= 2;
    }
}
int main()
{
    cin >> n >> m;
    //初始化操作
    for (int i = 1; i <= n; i++)
    {
        cin >> heap[i];
    }
    _size = n;
    //这个初始化操作得背住！！！
    for(int i = n / 2; i; i--)
    {
        down(i);
    }
    while (m --)
    {
        cout << heap[1] << " ";
        heap[1] = heap[_size];
        _size --;
        down(1);
    }
}
#include <iostream>
using namespace std;
/**
 * @brief 在依次出栈比较栈顶元素和当前数组元素大小的时候，
 * 如果栈顶元素小，那么找到目标值，将当前数组元素入栈，
 * 这样保持了栈内元素大小的递增性；如果栈顶元素大，
 * 那么栈顶指针左移，直到找到目标值，再将当前数组元素入栈，
 * 这样就保持了栈内元素大小的递增性。
 * 我们不必在意这个过程破坏了栈的结构，
 * 因为之前的数已经找到之前数组元素对应的目标值了。
 */
const int N = 100100;
//栈的0号位置是不存放数据的
int stk[N], tt;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        //读入输入数据
        int x;
        cin >> x;
        /**
         * @brief 由于我们是要维护一个单调栈，因此对于
         * 当前元素而言，如果栈顶元素大于输入的元素，那就
         * 得把它移出栈
         */
        while (tt && stk[tt] >= x) 
        {
            tt --;
        }
        //判断，如果栈顶为空，说明没有元素比当前元素小，输出-1
        //否则输出栈顶元素
        if(tt)
        {
            cout << stk[tt] << " ";
        }
        else
        {
            cout << -1 << " ";
        }
        //不管怎么样，当前元素都得入栈，因为它会对下一个输入元素造成影响
        stk[++ tt] = x;
    }
}
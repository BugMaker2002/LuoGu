#include <iostream>
using namespace std;
//因为题目当中已经说了插入的字符串的总长度不超过10e5
const int N = 100100;
/**
 * 二维数组e用于存放每个字符节点的后继节点的编号
 * cnt数组用于记录以某个字符节点终止的字符串的数量
 */
int e[N][26], cnt[N], idx;
//定义一个str数组用于存放每次操作的字符串
char str[N];
/**
 * 下标为0的节点既是根节点也是空节点
 * 根节点是因为idx是0
 * 空节点是因为e数组对应值为0(因为数组未赋值的话默认值就是0) 
 */
void insert(char str[])
{
    int p = 0;
    //因为C++当中字符数组最后一位存储的是'\0'，所以可
    //以采取下面的方式去遍历
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!e[p][u])
        {
            e[p][u] = ++idx;
        }
        p = e[p][u];
    }
    cnt[p] ++;
}
int query(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        //如果中间有一个字符不匹配，就说明该字符串不在存储的集合当中
        if (!e[p][u])
        {
            return 0;
        }
        p = e[p][u];
    }
    return cnt[p];
}
int main()
{
    int n;
    //为什么op数组的大小要定义成2？
    //因为要把运算符和字符串之间的空格给吸收掉
    char op[2];
    cin >> n;
    while (n--) 
    {
        cin >> op >> str;
        if(op[0] == 'I')
        {
            insert(str);
        }
        else
        {
            cout << query(str) << endl;
        }
    }
}
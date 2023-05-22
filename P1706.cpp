#include <iostream>
#include <iomanip>
using namespace std;
int pd[11]={0};//pd数组用于记录某个数字是否被使用过
int used[11];//used数组用于记录一个序列，如1,3,2或者3,1,2等等
int n;
//提前定义一个print函数方便待会进行输出
void print()
{
    for (int i = 1; i <= n; i++)
    {
        cout<<setw(5)<<used[i];
    }
    cout<<endl;
}
//定义深度优先函数进行遍历搜索
void dfs(int k)
{
    if(k==n)
    {
        print();
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!pd[i])//如果当前数没有用过
        {
            pd[i]=1;//标记一下
            used[k+1]=i;//把这个数填入数组
            dfs(k+1);//填下一个
            pd[i]=0;//回溯
        }
    }
}
int main()
{
    cin>>n;
    dfs(0);
}
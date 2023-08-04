#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<int> num;
stack<char> op;
int getPrio(char c)
{
    if(c == '+' || c == '-')
    {
        return 1;
    }
    else if(c == '*' || c == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
//计算的逻辑函数
void compute()
{
    int k;
    //注意：num1是第二个操作数，num2是第一个操作数
    int num1 = num.top();
    num.pop();
    int num2 = num.top();
    num.pop();
    char c = op.top();
    op.pop();
    if(c == '+') k = num2 + num1;
    else if(c == '-') k = num2 - num1;
    else if(c == '*') k = num1 * num2;
    else if (c == '/')
    {
        k = num2 / num1;
    }
    num.push(k);
}
int main()
{
    string str;
    cin >> str;
    for(int i = 0;i != str.length(); i++)
    {
        if (isdigit(str[i]))
        {
            //注意这里k必须初始化为0，因为你后面对k操作时要用到k的初始值
            //当然第一次操作时k是默认初始化为0，而后面几次时由于你没有显示
            //初始化那k就变成了上次的值
            int j = i, k = 0;
            while (j < str.length() && isdigit(str[j]))
            {
                k = k * 10 + str[j] - '0';
                j ++;
            }
            i = j - 1;
            num.push(k);
        }
        else if (str[i] == '(')
        {
            op.push(str[i]);
        }
        else if (str[i] == ')')
        {
            while(op.top() != '(')
            {
                compute();
            }
            //记得将'('出栈
            op.pop();
        }
        else
        {
            //如果栈顶运算符优先级比输入元素低，那就直接入栈，while循环都不会执行
            //否则先计算，再入栈
            while(op.size() && getPrio(str[i]) <= getPrio(op.top()))
            {
                compute();
            }
            op.push(str[i]);
        }
    }
    while (op.size())
    {
        compute();
    }
    cout << num.top() << endl;
    return 0;
}
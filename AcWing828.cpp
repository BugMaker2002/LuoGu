#include <iostream>
using namespace std;
const int N = 100010;
int st[N], tt;
int main()
{
    int m;
    cin >> m;
    while (m --) 
    {
        string op;
        cin >> op;
        if(op == "push")
        {
            int x;
            cin >> x;
            st[++ tt] = x;
        }
        else if(op == "pop")
        {
            tt --;
        }
        else if(op == "empty")
        {
            if (tt <= 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else if(op == "query")
        {
            cout << st[tt] << endl;
        }
    }
}
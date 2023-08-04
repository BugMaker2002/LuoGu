#include <iostream>
using namespace std;
const int N = 100010;
int q[N], tt = -1, hh;
int main()
{
    int m;
    cin >> m;
    while(m --)
    {
        string op;
        cin >> op;
        if(op == "push")
        {
            int x;
            cin >> x;
            q[++ tt] = x;
        }
        else if(op == "pop")
        {
            hh ++;
        }
        else if(op == "empty")
        {
            if(hh <= tt)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
        else
        {
            cout << q[hh] << endl;
        }
    }
}
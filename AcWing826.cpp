#include <iostream>
using namespace std;
const int M = 100100;
int e[M], ne[M], head, idx = 1;
int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        char s;
        cin >> s;
        if(s == 'H')
        {
            int x;
            cin >> x;
            e[idx] = x;
            ne[idx] = head;
            head = idx ++;
        }
        else if(s == 'D')
        {
            int k;
            cin >> k;
            if (k == 0)
            {
                head = ne[head];
            }
            else
            {
                ne[k] = ne[ne[k]];
            }
        }
        else if(s == 'I')
        {
            int k, x;
            cin >> k >> x;
            e[idx] = x;
            ne[idx] = ne[k];
            ne[k] = idx ++;
        }
    }
    for (int i = head; i != 0; i = ne[i])
    {
        cout << e[i] << " ";
    }
}
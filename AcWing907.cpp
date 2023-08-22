#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100100;
struct Range{
    int l, r;
}range[N];
bool compare(Range r1, Range r2)
{
    return r1.l < r2.l;
}
int main()
{
    int st, ed, n;
    cin >> st >> ed >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        range[i] = {a, b};
    }
    sort(range, range + n, compare);
    int res = 0;
    bool success = false;
    for(int i = 0; i < n; i++)
    {
        int j = i, r = -2e9;
        while(j < n && range[j].l <= st)
        {
            r = max(r, range[j].r);
            j ++;
        }
        if (r < st)
        {
            break;
        }
        res ++;
        if(r >= ed)
        {
            success = true;
            break;
        }
        st = r;
        i = j - 1;
    }
    if(!success) res = -1;
    cout << res << endl;
}
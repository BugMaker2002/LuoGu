#include <iostream>
#include <algorithm>
using namespace std;
const int N = 50010;
struct Cow
{
    int w, s;
}cows[N];
bool compare(Cow a, Cow b)
{
    return a.w + a.s < b.w + b.s;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int w, s;
        cin >> w >> s;
        cows[i] = {w, s};
    }
    sort(cows, cows + n, compare);
    int res = -2e9, sum = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, sum - cows[i].s);
        sum += cows[i].w;
    }
    cout << res << endl;
}
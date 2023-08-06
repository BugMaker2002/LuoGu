#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> getDivisors(int n)
{
    vector<int> res;
    for(int i = 1; i <= n / i; i ++)
    {
        if(n % i == 0) 
        {
            res.push_back(i);
            if(i != n / i) res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}
int main()
{
    int n;
    cin >> n;
    while (n --)
    {
        int a;
        cin >> a;
        vector<int> res = getDivisors(a);
        for(auto t : res) cout << t << " ";
        cout << endl;
    }
}
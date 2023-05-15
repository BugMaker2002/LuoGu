#include <iostream>
#include <algorithm>
using namespace std;
bool compare(string s1,string s2)
{
    return s1+s2>s2+s1;
}
int main()
{
    int n;
    cin>>n;
    string s[22];
    for (int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    sort(s,s+n,compare);
    for (int i = 0; i < n; i++)
    {
        cout<<s[i];
    }
}
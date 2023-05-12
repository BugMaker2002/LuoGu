#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int sum1=1,sum2=1;
    for (int i = 0; i < s.length(); i++)
    {
        int k=s[i]-'A'+1;
        sum1*=k;
    }
    for (int i = 0; i < t.length(); i++)
    {
        int k=t[i]-'A'+1;
        sum2*=k;
    }
    if(sum1%47==sum2%47)
        cout<<"GO";
    else  cout<<"STAY";
}
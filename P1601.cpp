#include <bits/stdc++.h>
#include <cmath>
using namespace std;
string add(string s,string t)
{
    int len1=s.length();
    int len2=t.length();
    if(len1<len2)
    {
        for(int i=0;i<(len2-len1);i++)
        {
            s="0"+s;
        }
    }
    else
    {
        for(int i=0;i<(len1-len2);i++)
        {
            t="0"+t;
        }
    }
    int len=s.length();
    int r=0;
    string result;
    for(int i=len-1;i>=0;i--)
    {
        int sum=(int(s[i]-'0')+int(t[i]-'0')+r)%10;
        r=(int(s[i]-'0')+int(t[i]-'0')+r)/10;
        result=char(sum+'0')+result;
    }
    if(r!=0)
        result=char(r+'0')+result;
    return result;
}
int main()
{
    string s;
    string t;
    cin>>s>>t;
    cout<<add(s,t);
}
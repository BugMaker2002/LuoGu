#include <iostream>
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
string mul(string s,string t)
{
    if (s=="0" || t=="0")
    {
        return "0";
    }  
    int len1=s.length();
    int len2=t.length();
    string result;
    for(int i=len2-1;i>=0;i--)
    {
        string midResult;
        //获取乘数的值方便待会进行运算
        int x=t[i]-'0';
        for(int j=0;j<x;j++)
        {
            midResult=add(midResult,s);
        }
        //移位操作
        for (int j = 0; j < len2-1-i; j++)
        {
            midResult+="0";
        }
        result=add(result,midResult);
    }
    return result;
}
string sumOfFactorial(int n)
{
    string result;
    string result_now="1";
    for(int i=1;i<=n;i++)
    {
        result_now = mul(result_now,to_string(i));
        result = add(result,result_now);
    }
    return result;
}
int main()
{
    int n;
    cin>>n;
    cout<<sumOfFactorial(n);
}
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
/**
 * @brief 
 * ans数组用于保存加数
 * s数组用于保存对应加数的字符串
 */
int ans[1001];
string s[1001];
int main()
{
    int n,c=1;
    string result="1";
    cin>>n;
    if (n<=4)
    {
        cout<<"1 "<<n<<endl;
        cout<<n;
        return 0;
    }
    for (int i = 2; i <= n; i++)
    {
        if (n>=i)
        {
            n-=i;
            ans[c++]=i;
            s[c-1]=to_string(i);
        }
        else
        {
            break;
        }
    }
    for (int i = c-1; i >= 1; i--)
    {
        if (n>0)
        {
            ans[i]++;
            s[i]=to_string(ans[i]);
            n--;
        }
    }
    if (n>0)
    {
        ans[c-1]++;
        s[c-1]=to_string(ans[c-1]);
    }
    for (int i = 1; i <= c-1; i++)
    {
        cout<<ans[i]<<" ";
        result=mul(result,s[i]);
    }
    cout<<endl;
    cout<<result;
}
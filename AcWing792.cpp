#include <iostream>
#include <vector>
using namespace std;
bool cmp(string s, string t) 
{
    if(s.length() != t.length())
    {
        return s.length() >= t.length();
    }
    else
    {
        return s >= t;
    }
}
//要求A表示的数必须大于B表示的数
vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size(); i ++)
    {
        t = A[i] - t;
        if(i < B.size())
        {
            t = t - B[i];
        }
        C.push_back((t + 10) % 10);
        if(t >= 0)
        {
            t = 0;
        }
        else
        {
            t = 1;
        }
    }
    //解决9999-9991=9而非0009这种情况
    while(C.size() > 1 && C.back() == 0)
    {
        C.pop_back();
    }
    return C;
}
int main()
{
    string s,t;
    vector<int> A,B;
    cin>>s>>t;
    for(int i=s.length()-1;i>=0;i--)
    {
        A.push_back(s[i]-'0');
    }
    for(int i=t.length()-1;i>=0;i--)
    {
        B.push_back(t[i]-'0');
    }
    if (cmp(s,t))
    {
        vector<int> C=sub(A,B);
        for (int i = C.size()-1; i >= 0; i--)
        {
            printf("%d",C[i]);
        }
    }
    else
    {
        vector<int> C=sub(B,A);
        printf("-");
        for (int i = C.size()-1; i >= 0; i--)
        {
            printf("%d",C[i]);
        }
    }
}
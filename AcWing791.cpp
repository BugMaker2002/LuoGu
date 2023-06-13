#include <iostream>
#include <vector>
using namespace std;
vector<int> add(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size())
        return add(B, A);
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i ++)
    {
        t += A[i];
        if(i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if(t)
        C.push_back(t);
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
    vector<int> C=add(A,B);
    for (int i = C.size()-1; i >= 0; i--)
    {
        printf("%d",C[i]);
    }
}
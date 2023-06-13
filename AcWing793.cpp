#include <iostream>
#include <vector>
using namespace std;
vector<int> mul(vector<int>& A,int b)
{
    int t = 0;
    vector<int> C;
    for(int i = 0; i < A.size() || t; i++)
    {
        if(i < A.size())
            t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while(C.size() > 1 && C.back() == 0)
    {
        C.pop_back();
    }
    return C;
}
int main()
{
    string s;
    int b;
    vector<int> A;
    cin>>s>>b;
    for(int i=s.length()-1;i>=0;i--)
    {
        A.push_back(s[i]-'0');
    }
    vector<int> C=mul(A,b);
    for (int i = C.size()-1; i >= 0; i--)
    {
        printf("%d",C[i]);
    }
}
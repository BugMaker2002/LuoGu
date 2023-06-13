#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//要求A表示的数必须大于B表示的数
vector<int> div(vector<int>A, int b, int & r)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];
        C.push_back(r/b);
        r = r % b;
    }
    /**
     * 此时C当中存放的是正序存放的数，为了与之前的模板统
     * 一，我们需要将其倒放，并且去除七前导0，当然，为了方便，你也可以不倒放，并且判断条件C.back() == 0改为
     * 判断C.font() == 0
     **/
    reverse(C.begin(), C.end());
    while(C.size() > 1 && C.back() == 0)
    {
        C.pop_back();
    }
    return C;
}
int main()
{
    string s;
    vector<int> A;
    int b,r;
    cin>>s>>b;
    for(int i=s.length()-1;i>=0;i--)
    {
        A.push_back(s[i]-'0');
    }
    vector<int> C=div(A,b,r);
    for (int i = C.size()-1; i >= 0; i--)
    {
        printf("%d",C[i]);
    }
    cout<<endl;
    cout<<r;
}
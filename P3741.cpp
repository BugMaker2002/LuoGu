#include <iostream>
using namespace std;
int main()
{
    int n, sum = 0;
    string s;
    cin>>n>> s;
    {
        //don't need to loop the end of the string
        for (int i = 0; i < s.length() - 1; i++)
        {
            if(s[i]=='V'&&s[i+1]=='K')
            {
                sum++;
                s[i]=s[i+1]='X';
            }
        }
        for (int i = 0; i < s.length() - 1; i++)
        {
            if(s[i]!='X'&&s[i]==s[i+1])
            {
                sum++;
                break;
            }
        }
        cout << sum;
    }
}
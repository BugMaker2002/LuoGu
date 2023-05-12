#include <iostream>
using namespace std;
int main()
{
    string s;
    int sum1=0,sum2=0;
    cin>>s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]=='b' && s[i+1]=='o' && s[i+2]=='y' && i<s.length()-2)
        {
            sum1++;
            i+=2;
        }
        else if (s[i]=='o' && s[i+1]=='y' && i<s.length()-1)
        {
           sum1++;
           i+=1;
        }
        else if (s[i]=='b' && s[i+1]=='o' && i<s.length()-1)
        {
           sum1++;
           i+=1;
        }
        else if (s[i]=='y' || s[i]=='b' || s[i]=='o')
        {
            sum1++;
        }
        else if (s[i]=='g' && s[i+1]=='i' && s[i+2]=='r' && s[i+3]=='l' && i<s.length()-3)
        {
           sum2++;
           i+=3;
        }
        else if (s[i]=='i' && s[i+1]=='r' && s[i+2]=='l' && i<s.length()-2)
        {
           sum2++;
           i+=2;
        }
        else if (s[i]=='g' && s[i+1]=='i' && s[i+2]=='r' && i<s.length()-2)
        {
           sum2++;
           i+=2;
        }
        else if (s[i]=='r' && s[i+1]=='l' && i<s.length()-1)
        {
           sum2++;
           i+=1;
        }
        else if (s[i]=='g' && s[i+1]=='i' && i<s.length()-1)
        {
           sum2++;
           i+=1;
        }
        else if (s[i]=='i' && s[i+1]=='r' && i<s.length()-1)
        {
           sum2++;
           i+=1;
        }
        else if (s[i]=='g' || s[i]=='i' || s[i]=='r' || s[i]=='l')
        {
            sum2++;
        }

    }
    cout<<sum1<<endl<<sum2;
}
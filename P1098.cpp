#include <iostream>
using namespace std;
int main()
{
    int p1,p2,p3;
    cin>>p1>>p2>>p3;
    string s;
    cin>>s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]=='-')
        {
            if (s[i+1]-s[i-1]==1)
            {
                //不输出"-"
                continue;
            }
            else if (s[i+1]<=s[i-1])
            {
                cout<<s[i];
            }
            else if ((s[i+1]>='a' && s[i+1]<='z' && s[i-1]>='a' && s[i-1]<='z')||
            (s[i+1]>='0' && s[i+1]<='9' && s[i-1]>='0' && s[i-1]<='9'))
            {
                if (p3==1)
                {
                    for (char st = s[i-1]+1; st < s[i+1]; st++)
                    {
                        for (int j = 0; j < p2; j++)
                        {
                            if (p1==3)
                            {
                                cout<<"*";
                            }
                            if (p1==2)
                            {
                                if (st>='0' && st<='9')
                                {
                                    cout<<st;
                                }
                                else if (st>='a' && st<='z')
                                {
                                    cout<<char(st-'a'+'A');
                                }
                                
                            }
                            else if (p1==1)
                            {
                                if (st>='0' && st<='9')
                                {
                                    cout<<st;
                                }
                                else if (st>='a' && st<='z')
                                {
                                    cout<<st;
                                }
                            }
                            
                        }
                    }
                }
                else
                {
                    for (char st = s[i+1]-1; st >= s[i-1]+1; st--)
                    {
                        for (int j = 0; j < p2; j++)
                        {
                            if (p1==3)
                            {
                                cout<<"*";
                            }
                            if (p1==2)
                            {
                                if (st>='0' && st<='9')
                                {
                                    cout<<st;
                                }
                                else if (st>='a' && st<='z')
                                {
                                    cout<<char(st-'a'+'A');
                                }
                                
                            }
                            else if (p1==1)
                            {
                                if (st>='0' && st<='9')
                                {
                                    cout<<st;
                                }
                                else if (st>='a' && st<='z')
                                {
                                    cout<<st;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                cout<<s[i];
            }
        }
        else
        {
            cout<<s[i];
        }
    }
}
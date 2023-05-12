#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,t="",r="";
    cin>>s;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='.' || s[i]=='/')
        {
            r=s.substr(i+1);
            reverse(t.begin(),t.end());
            reverse(r.begin(),r.end());
            for (int j = 0; j < t.length(); j++) 	
            {
                if(t[j]!='0')
                {
                    break;
                }
                t[j]='x';
            }
            for (int j = 0; j < r.length(); j++) 	
            {
                if(r[j]!='0')
                {
                    break;
                }
                r[j]='x';
            }
            for (int j = r.length()-1; j >= 0; j--) 	
            {
                if(r[j]!='0')
                {
                    break;
                }
                r[j]='y';
            }
            for (int j = 0; j < t.length(); j++) 	
            {
                if(t[j]!='x')
                {
                    cout<<t[j];
                }
            }
            if(t.length()==1 && t[0]=='x') cout<<0;    
            cout<<s[i];
            bool alpha=true;
            for (int j = 0; j < r.length(); j++) 	
            {
                if(r[j]!='x' && r[j]!='y')
                {
                    cout<<r[j];
                    alpha=false;
                }
            }
            if(alpha) cout<<"0";
            break;
        }
        else if(s[i]=='%')
        {
            reverse(t.begin(),t.end());
            for (int j = 0; j < t.length(); j++) 	
            {
                if(t[j]!='0')
                {
                    break;
                }
                t[j]='x';
            }
            for (int j = 0; j < t.length(); j++) 	
            {
                if(t[j]!='x')
                {
                    cout<<t[j];
                }
            } 
            if(t=="x") cout<<0;
            cout<<s[i];
            break;
        }
        t+=s[i];
        if(i==s.length()-1)
        {
            reverse(t.begin(),t.end());
            for (int j = 0; j < t.length(); j++) 	
            {
                if(t[j]!='0')
                {
                    break;
                }
                t[j]='x';
            }
            for (int j = 0; j < t.length(); j++) 	
            {
                if(t[j]!='x')
                {
                    cout<<t[j];
                }
            } 
        }
        if(s.length()==1 && s[0]=='0') cout<<0;
    }
    
}
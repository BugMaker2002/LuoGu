#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int sum=0;
    getline(cin,s);
    for (int i = 0; i < s.length();i++) {   
        if ((s[i]>='0' && s[i]<='9') ||(s[i]>='a' && s[i]<='z')|| (s[i]>='A' && s[i]<='Z')) 
            sum++;
    }
    cout<<sum;
    
}
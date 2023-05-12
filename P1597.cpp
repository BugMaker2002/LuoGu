#include <bits/stdc++.h>
#include <map>
using namespace std;
int main()
{
    string s;
    char val[255],a[3]={'0','0','0'};
    getline(cin, s);
    int index=0;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]>='a' && s[i]<='c')
        {
            val[index++]=s[i];
        }
        else if(s[i]>='0' && s[i]<='9')
        {
            val[index++]=s[i];
        }
    }
    for (int i = 0; i < index; i+=2)
    {
        if(val[i+1]>='a' && val[i+1]<='c')
        {
            a[val[i]-'a']=a[val[i+1]-'a'];
        }
        else if(val[i+1]>='0' && val[i+1]<='9')
        {
            a[val[i]-'a']=val[i+1];  //using ascii values to convert to uppercase and store it in a variable.
        }
    }
    cout<<a[0]<<" "<<a[1]<<" "<<a[2];  //converting the uppercase characters to lowercase and print it.
}
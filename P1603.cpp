#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string word[6];
    int val[6]={-1,-1,-1,-1,-1,-1};
    for (int i = 0; i < 6; i++)
    {
        cin>>word[i];
        if (word[i]=="one" || word[i]=="a" || word[i]=="another" || word[i]=="first")
        {
            val[i]=1*1%100;
        }
        else if (word[i]=="two" || word[i]=="both" || word[i]=="second")
        {
            val[i]=2*2%100;
        }
        else if (word[i]=="three" || word[i]=="third")
        {
            val[i]=3*3%100;
        }
        else if (word[i]=="four")
        {
            val[i]=4*4%100;
        }
        else if (word[i]=="five")
        {
            val[i]=5*5%100;
        }
        else if (word[i]=="six")
        {
            val[i]=6*6%100;
        }
        else if (word[i]=="seven")
        {
            val[i]=7*7%100;
        }
        else if (word[i]=="eight")
        {
            val[i]=8*8%100;
        }
        else if (word[i]=="nine")
        {
            val[i]=9*9%100;
        }
        else if (word[i]=="ten")
        {
            val[i]=10*10%100;
        }
        else if (word[i]=="eleven")
        {
            val[i]=11*11%100;
        }
        else if (word[i]=="twelve")
        {
            val[i]=12*12%100;
        }
        else if (word[i]=="thirteen")
        {
            val[i]=13*13%100;
        }
        else if (word[i]=="fourteen")
        {
            val[i]=14*14%100;
        }
        else if (word[i]=="fifteen")
        {
            val[i]=15*15%100;
        }
        else if (word[i]=="sixteen")
        {
            val[i]=16*16%100;
        }
        else if (word[i]=="seventeen")
        {
            val[i]=17*17%100;
        }
        else if (word[i]=="eighteen")
        {
            val[i]=18*18%100;
        }
        else if (word[i]=="nineteen")
        {
            val[i]=19*19%100;
        }
        else if (word[i]=="twenty")
        {
            val[i]=20*20%100;
        }
    }
    string s="";
    sort(val, val+6);
    for (int i = 0; i < 6; i++)
    {
        // cout<<val[i]<<endl;
        if(val[i]!=-1)
        {
            if (val[i]<=9)
            {
                s+="0";
            }
            s+=to_string(val[i]);
        }
    }
    int index=-1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]!='0')
        {
            break;
        }
        index=i;
    }
    if (index==s.length()-1)
    {
        s="";
    }
    else
    {
        s=s.substr(index+1);
    }    
    if (s=="")
    {
        cout<<0;
    } 
    else
    {
        cout<<s;
    }
    
}
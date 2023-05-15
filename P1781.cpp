#include <iostream>
using namespace std;
bool isMax(string x,string max)
{
    if (x.length()>max.length())
    {
        return true;
    }
    else if (x.length()==max.length())
    {
        for (int i = 0; i < x.length(); i++)
        {
            if (x[i]-'0'>max[i]-'0')
            {
                return true;
            }
            else if (x[i]-'0'<max[i]-'0')
            {
                return false;
            }
        }
        return false;
    }
    else
    {
        return false;
    }
}
int main()
{
    string max;
    int n,k;
    string x;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        if (isMax(x,max))
        {
            max=x;
            k=i;
        }
    }
    cout<<k+1<<endl<<max;
}
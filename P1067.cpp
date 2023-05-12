#include <iostream>
using namespace std;
int main()
{
    int n,x,a[102];
    cin>>n;
    string result;
    for (int i = n; i >= 0; i--)
    {
        cin>>x;
        a[i]=x;
        if (abs(x)==1)
        {  
            if (x<0)
            {
                cout<<"-";
            }
            if (x>0 && i!=n)
            {
                bool alpha=true;
                for (int j = i+1; j <= n; j++)
                {
                    if (a[j]!=0)
                    {
                        alpha=false;
                        break;
                    }
                }
                if (!alpha)
                {
                    cout<<"+";
                }
            }
            if (i>1)
            {
                cout<<"x^"<<i;
            }
            else if (i==1)
            {
                cout<<"x";
            }
            else if (i==0)
            {
                cout<<1;
            }
        }
        else if (x==0)
        {
            if (i==0)
            {
                bool alpha=true;
                for (int j = i+1; j <= n; j++)
                {
                    if (a[j]!=0)
                    {
                        alpha=false;
                        break;
                    }
                }
                if (alpha)
                {
                    cout<<0;
                }
            }
            continue;
        }
        else
        {
            if (x<0)
            {
                cout<<"-";
            }
            if (x>0 && i!=n)
            {
                bool alpha=true;
                for (int j = i+1; j <= n; j++)
                {
                    if (a[j]!=0)
                    {
                        alpha=false;
                        break;
                    }
                }
                if (!alpha)
                {
                    cout<<"+";
                }
            }
            cout<<abs(x);
            if (i>1)
            {
                cout<<"x^"<<i;
            }
            else if (i==1)
            {
                cout<<"x";
            }
            else if (i==0)
            {
                
            }
        }
        
    }
    
}
#include <iostream>
using namespace std;
int main()
{
    /**
     * @brief b和c是两个操作数
     * 
     */
    int n,b,c;
    cin>>n;
    char a[10]={" "};
    char cur;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if ((a[0]>='a')&&(a[0]<='c'))
        {
            cin>>b>>c;
            switch (a[0])
            {
            case 'a':
                cur='a';
                cout<<b<<"+"<<c<<"="<<b+c<<endl;
                cout<<to_string(b).length()+to_string(c).length()+to_string(b+c).length()+2<<endl;
                break;
            case 'b':
                cur = 'b';
                cout<<b<<"-"<<c<<"="<<b-c<<endl;
                cout<<to_string(b).length()+to_string(c).length()+to_string(b-c).length()+2<<endl;
                break;
            case 'c':
                cur='c';
                cout<<b<<"*"<<c<<"="<<b*c<<endl;
                cout<<to_string(b).length()+to_string(c).length()+to_string(b*c).length()+2<<endl;
                break;
            default:
                break;
            }
        }
        else
        {
            /**
             * @brief 否则的话就没有输入操作类型，而此时另一个操作数已经被输入了a当中
             * 
             */
            cin>>b;
            int d=0;
            int mulp=1;
            for(int j=9;j>=0;j--)
            {
                if ((a[j]>='0')&&(a[j]<='9'))
                {
                    int e=(a[j]-'0');
                    d+=(e*mulp);
                    mulp*=10;
                }
            }
            switch (cur)
            {
            case 'a':
                cout<<d<<"+"<<b<<"="<<d+b<<endl;
                cout<<to_string(d).length()+to_string(b).length()+to_string(d+b).length()+2<<endl;
                break;
            case 'b':
                cout<<d<<"-"<<b<<"="<<d-b<<endl;
                cout<<to_string(d).length()+to_string(b).length()+to_string(d-b).length()+2<<endl;
                break;
            case 'c':
                cout<<d<<"*"<<b<<"="<<d*b<<endl;
                cout<<to_string(d).length()+to_string(b).length()+to_string(d*b).length()+2<<endl;
                break;
            default:
                break;
            }
        }
    }
}
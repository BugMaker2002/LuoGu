#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct People
{
    string name;
    string position;
    long long number;
    int level;
    int inn;
}peoples[115];
int change(string pos)
{
    if (pos=="BangZhu")
    {
        return 0;
    }
    else if (pos=="FuBangZhu")
    {
        return 1;
    }
    else if (pos=="HuFa")
    {
        return 2;
    }
    else if (pos=="ZhangLao")
    {
        return 3;
    }
    else if (pos=="TangZhu")
    {
        return 4;
    }
    else if (pos=="JingYing")
    {
        return 5;
    }
    else if (pos=="BangZhong")
    {
        return 6;
    }
}
bool compare1(People x, People y)
{
    if (x.number!=y.number)
    {
        return x.number>y.number;
    }
    else
    {
        return x.inn<y.inn;
    }
}
bool compare2(People x, People y)
{
    if (x.position==y.position)
    {
        if (x.level!=y.level)
        {
            return x.level>y.level;
        }
        else
        {
            return x.inn<y.inn;
        }
    }
    else
    {
        return change(x.position)<change(y.position);
    }
}
int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>peoples[i].name>>peoples[i].position>>peoples[i].number>>peoples[i].level;
        peoples[i].inn=i;
    }
    int num1=2;
    int num2=4;
    int num3=7;
    int num4=25;
    sort(peoples+3,peoples+n,compare1);
    for (int i = 3; i < n; i++)
    {
        if (num1>0)
        {
            peoples[i].position="HuFa";
            num1--;
        }
        else if (num2>0)
        {
            peoples[i].position="ZhangLao";
            num2--;
        }
        else if (num3>0)
        {
            peoples[i].position="TangZhu";
            num3--;
        }
        else if (num4>0)
        {
            peoples[i].position="JingYing";
            num4--;
        }
        else
        {
            peoples[i].position="BangZhong";
        }
    }
    sort(peoples,peoples+n,compare2);
    for (int i = 0; i < n; i++)
    {
        cout<<peoples[i].name<<" "<<peoples[i].position<<" "<<peoples[i].level<<endl;
    }
}
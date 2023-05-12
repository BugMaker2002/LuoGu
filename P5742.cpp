#include <bits/stdc++.h>
using namespace std;
struct Student{
    string number;
    int grade1;
    int grade2;
    double grade;
    int getTotal()
    {
        return grade1 + grade2;
    }
}studens[1002];
int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>studens[i].number>>studens[i].grade1>>studens[i].grade2;
        if(studens[i].getTotal()>140 && (7*studens[i].grade1+3*studens[i].grade2)>=800)
        {
            cout<<"Excellent"<<endl;
        }
        else
        {
            cout<<"Not excellent"<<endl;
        }
    }
    
}
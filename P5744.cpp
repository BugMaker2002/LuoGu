#include <bits/stdc++.h>
using namespace std;
struct Student
{
    string name;
    int age;
    int grade;
}students[5];
void improve(Student& student)
{
    student.grade=student.grade*1.2;
    student.age=student.age+1;
    if(student.grade>600)
        student.grade=600;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>students[i].name>>students[i].age>>students[i].grade;
        improve(students[i]);
        cout<<students[i].name<<" "<<students[i].age<<" "<<students[i].grade<<endl;
    }
    
}
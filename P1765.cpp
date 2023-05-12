#include <iostream>
using namespace std;
int main()
{
    string sentence;
    int sum=0;
    getline(cin, sentence); //get whole line into a string variable, then put it into a string stream called "cin"
    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i]=='a' || sentence[i]=='d' || sentence[i]=='g' || sentence[i] == 'j'
        || sentence[i]=='m' || sentence[i]=='p' || sentence[i]=='t' || sentence[i]=='w' || sentence[i]==' ')
        {
            sum+=1;
        }
        else if (sentence[i]=='b' || sentence[i]=='e' || sentence[i]=='h' || sentence[i] == 'k'
        || sentence[i]=='n' || sentence[i]=='q' || sentence[i]=='u' || sentence[i]=='x')
        {
            sum+=2;
        }
        else if (sentence[i]=='c' || sentence[i]=='f' || sentence[i]=='i' || sentence[i] == 'l'
        || sentence[i]=='o' || sentence[i]=='r' || sentence[i]=='v' || sentence[i]=='y')
        {
            sum+=3;
        }
        else if (sentence[i]=='s' || sentence[i]=='v' || sentence[i]=='z')
        {
            sum+=4;
        }
    }
    cout<<sum;
}
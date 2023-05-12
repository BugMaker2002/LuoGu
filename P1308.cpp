#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
bool isEqual(char s,char t)
{
    int judge=(s-t);
    if(abs(judge)==0||abs(judge)==32)
    {  return true;}    //abs(-1)=32,abs(0)=0,abs(1)=1.  It is a sign of difference
    else return false;  //if abs(s-t)!=0 or 32 or 1.  It is not a sign of difference.  It
}
int main()
{
    string word;
    string passage;
    getline(cin,word);
    getline(cin,passage); //get whole line as a string.
    int sum=0;
    vector<int>index;//to store the indices of the words which have the same sign.  It will be used to check the sign of the next word.  It will
    for (int i = 0; i < passage.length(); i++)
    {
        int judge=(passage[i]-word[0]);
        if ((isEqual(word[0],passage[i]))&&(i==0||passage[i-1]==' '))
        {
            bool alpha=true; //if it's a letter, then it's an alpha.
            for (int j = 1; j < word.length(); j++)
            {
                if (!isEqual(passage[i+j],word[j]))  
                {
                    alpha=false;  //if it's not an alpha, then it's not an alpha word.  break out of the for loop.  (i+j
                }
            }
            if (passage[i+word.length()]!=' ')
            {
                alpha=false;
            }
            if (alpha)
            {
                sum++;
                index.push_back(i);
            }
        }
    }
    if (sum>0)
    {
        cout<<sum<<" "<<index[0];
    }
    else
    {
        cout<<-1;
    }
}
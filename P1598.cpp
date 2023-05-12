#include <iostream>
using namespace std;
int main()
{
    string lines[4];
    int freq[26]={0};
    for (int i = 0; i < 4; i++)
    {
        getline(cin, lines[i]); 
        for (int j = 0; j < lines[i].length(); j++)
        {
            if (lines[i][j] >= 'A' && lines[i][j] <= 'Z') 
            {
                freq[lines[i][j]-'A']++;
            }
        }
        //read a line into a string variable, which is a sequence of characters. The function ends when a non-wh
    }
    int max=0,last=0;//max is the highest frequency of a letter found in the string, and last is the index of the last letter found.
    for (int i = 0; i < 26; i++)
    {
        if (freq[i]>max) 
        {
            max=freq[i];
        }
    }
    for (int i = 25; i >= 0; i--)
    {
        if (freq[i]!=0)
        {
            last=i;
            break;
        }
    }
    for (int i = 0; i < max+1; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (true)
            {
                if (freq[j]>=max-i)
                {
                    if (i==max)
                    {
                        cout<<char(j+'A');
                        if (j!=25)
                        {
                            cout<<" ";
                        }
                        
                    }
                    else
                    {
                        cout<<"*";
                        if (j!=25)
                        {
                            cout<<" ";
                        }
                    }
                    
                }
                else
                {
                    cout<<" ";
                        if (j!=25)
                        {
                            cout<<" ";
                        }
                }

            }
            
        }
        if (i!=max)
        {
           cout<<endl;
        }
    }
    
}
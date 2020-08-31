#include<string>
#include<iostream>
using namespace std;

bool IsUnique(string str)
{
    int len = str.length();
    if(len > 128)
        return false;
    
    bool char_set[128];

    // going through characters in string
    for(int i =0; i<len;i++)
    {
        int val = str.at(i);
        // if already in string
        if(char_set[val])
        
        char_set[val] = true;
    }

    return true;
}

int main()
{
    string str = "abcdefghijklmnopqrst";
    bool x = IsUnique(str);
    if(x)
        cout<<"hello";
    return 0;
}
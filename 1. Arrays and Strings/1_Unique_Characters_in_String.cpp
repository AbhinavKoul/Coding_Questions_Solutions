#include<string>
#include<iostream>
using namespace std;

bool IsUnique(string str)
{
    int len = str.length();
    //if greater than character limit, then dublicacy is obviosly there
    if(len > 128)
        return false;
    
    // initially everyone should be false for it to work!
    static bool char_set[128];

    // going through characters in string
    for(int i =0; i<len;i++)
    {
        int val = str.at(i);
        // if already in string
        if(char_set[val])
            return false;
        
        char_set[val] = true;
    }

    return true;
}

int main()
{
    string str = "abcdefghijklmnopqrst";
    bool x = IsUnique(str);
    if(x)
        cout<<"Everthing is distinct in the string " + str;
    else
        cout<<"Not distinct in the string " + str;
    
    cout<<endl;
    
    return 0;
}
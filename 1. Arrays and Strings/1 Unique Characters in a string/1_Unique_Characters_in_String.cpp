#include<string>
#include<iostream>
using namespace std;


/*
1. Assumed 128 ASCII characters, Can modify to 256 char in extended ASCII
2. 1st Check if we are dealing with ASCII or UNICODE
*/
bool IsUnique(string str)
{   /*
    USING EXTRA DATA STRUCTURE

    Space Complexity  : O(1) where c is the character set (but we are taking 128 space for characters O(c) )
    Time Complexity   : O(n) WHERE n is length of string
*/
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

bool IsUniqueBitVector(string str)
{   /*
    USING BIT VECTOR : OPTIMIZATION ON SPACE ASPECT!

    time complexity :   O(N)
    SPACE complexity:   O(1)

    Assume if character set is just from 'a' - 'z'.
    If more set, then we have to take diffirent data type rather than int
*/
    int checker = 0;    //bit vector of int as it has a size of 32 and since we hae 26 characters we can use bit manipulation to set flags

    for(int i=0;i<str.length();i++)
    {
        int val = str.at(i) - 'a'; //find shift from initial char 'a' to set that flag at that position
        if((checker & (1<<val))>0) // shift left to location of character and compare with 0 bit and check if > 0  means checker also has 1 at that bit and thus already present
            return false;
        
        //update checker flag
        checker |= (1<<val); // we do or here as we want to set/mask bit at that position(val) to 1 :- denoting that that char is present 

    }

    // if completes loop
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
    bool bit = IsUniqueBitVector(str);
    if(bit)
        cout<<"Everthing is distinct in the string " + str;
    else
        cout<<"Not distinct in the string " + str;
    
    cout<<endl;
    
    return 0;
}
#include<iostream>
#include<string>
#include<unordered_map>
#define ul unordered_map
using namespace std;

bool checkPalin(string arr1,string arr2)
{   /*
    Time Complex : O(n) where n is the length of string
    Space Complex : O(n) 

    Assumes both strings are of equal length and we are not searching for subscript
    */
    if(arr1.length()!=arr2.length())
        return false;
    
    //initialize unordered map
    ul<int,int> char_map;

    for(auto i:arr1)
        char_map[i] ++;

    for (auto i :arr2)
    {
        if(char_map.find(i)==char_map.end())
            return false;
        else if(char_map[i] == 0)
            return false;
        else
            char_map[i] -=1;
        
    }

    return true;
    
}

int main()
{
    string str1 = "abcdef";
    string str2 = "cbafedd";
    bool res = checkPalin(str1,str2);
    if(res)
        cout<<"yes they are palindrome";
    else
        cout<<"they are not palindrome";

    return 0;
    
}
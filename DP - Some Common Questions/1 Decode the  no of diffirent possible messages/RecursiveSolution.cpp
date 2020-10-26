#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define v vector

int numWays(string arr,int i)
{
    //base
    if(i == arr.length())
        return 1;
    
    if(arr[i] == '0')
        return 0;

    //general

    int res = numWays(arr,i+1);
    //VERY VERY IMPORTANT
    // stoi : string to int conversion
    // substring : just like string slicing in python
    if(stoi(arr.substr(i,2))<=26 && (i+2 <= arr.length()))
    {
        res += numWays(arr,i+2);
    }

    return res;
}
int main()
{

    string arr = "012134";

    cout<<"HELLO : "<< numWays(arr,0)<< " ";
    return 0;
}
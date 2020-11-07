#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define v vector
using namespace std;

bool IsDivisible(string bin)
{
    int len = bin.length();
    if(len<=6)
        return false;
    
    int div = len - 7;
    int count = 0;
    for(int i =0;i<=div;i++)
    {
        if(bin[i] == '1')
            return true;
    }
    return false;

}

int main()
{
    string inp;
    cin>>inp;

    if(IsDivisible(inp))
        cout<<"yes";
    else
    {
        cout<<"no";
    }
    


    return 0;
}
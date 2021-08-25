#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;
#define v vector
#define ll long long 

v<ll> beautifulNumbers;
unordered_map<int,string> um;
void initMap()
{
    for(int i = 1;i<=9;i++)
    {
        string str = to_string(i);
        for(int j = 1;j<i;j++)
        {
            str += to_string(i);
        }
        
        um[i] = str;   
    }
}
void printMap()
{
    for(auto i : um)
    {
        cout<<"\n"<<i.first<<" "<<i.second;
    }
}
void bfs(ll start, string prev_str)
{
    if(start > 9)
        return;
    string str = prev_str + um[start];

    if(stoll(str) > 1e12)
        return;
    
    cout<<" "<<str<<" ";
    // beautifulNumbers.push_back(stoll(str));
    while(next_permutation(str.begin(),str.end()))
    {
        if(stoll(str) > 1e12)
            break;

        cout<<" "<<str<<" ";
        // beautifulNumbers.push_back(stoll(str));
    }

    bfs(start+1,str);
}
void findAllBeautiful()
{
    for(int i = 1;i<=9;i++)
    {
        beautifulNumbers.push_back(stoll(um[i]));
        for(int j = i + 1;j<=9;j++)
            bfs(j,um[i]);
    }

}
void printVector()
{
    for(auto i : beautifulNumbers)
    {
        cout<<i<<" ";
    }
}
int main()
{
    initMap();
    printMap();

    findAllBeautiful();
    // printVector();
    return 0;
}
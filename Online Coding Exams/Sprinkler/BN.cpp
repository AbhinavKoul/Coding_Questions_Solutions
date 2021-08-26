#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
#define v vector
#define ll long long 

set<ll> beautifulNumbers;
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

    if(str.length() > 10)
        return;
    
    // cout<<" "<<str<<" ";
    beautifulNumbers.insert(stoll(str));
    while(next_permutation(str.begin(),str.end()))
    {
        if(str.length() > 10)
            break;

        // cout<<" "<<str<<" ";
        beautifulNumbers.insert(stoll(str));
    }

    bfs(start+1,str);
}
void findAllBeautiful()
{
    for(int i = 1;i<=9;i++)
    {
        beautifulNumbers.insert(stoll(um[i]));
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

    findAllBeautiful();
    // sort(beautifulNumbers.begin(),beautifulNumbers.end());
    // printVector();
    ll test;
    cin>>test;

    while(test--)
    {
        ll val;
        cin>>val;
        cout<<*upper_bound(beautifulNumbers.begin(),beautifulNumbers.end(),val)<<"\n";
    }

    return 0;
}
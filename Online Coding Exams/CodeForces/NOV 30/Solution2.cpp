#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define v vector
#define um unordered_map
#define mod 1000000007
using namespace std;
template<typename K>
void printVector(vector<K> arr)
{
    cout<<endl;
    for(auto i : arr)
        cout<<i<<" ";
}

v<int> DP(10000000);

void increment_values(int ptr)
{
    int jump = DP[ptr] + 1;
    int new_ptr = ptr + jump;
    if(new_ptr > DP.size())
        return;

    DP[new_ptr] = jump;
    DP[new_ptr - 1] = jump+1;
    ptr++;

    while (new_ptr - ptr - 1 > 0)
    {
        DP[ptr] = jump;
        ptr++;
    }
    
    
    increment_values(new_ptr);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    DP[0] = 0;
    DP[1] = 1;
    increment_values(1);
    
    int test;
    cin>>test;

    while (test)
    {
        int val;
        cin>>val;
        cout<<DP[val]<<endl;
        test--;
    }
    
    return 0;
}
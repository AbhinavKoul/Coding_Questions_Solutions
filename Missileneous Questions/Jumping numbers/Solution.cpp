#include<queue>
#include<iostream>
#include<vector>
// #include<bits/stdc++.h>

using namespace std;
#define v vector

void bfs(int x,int start,v<int> &res)
{
    //bfs
    v<int> res;
    queue<int> Q;
    Q.push(start);

    while (!Q.empty())
    {
        int src = Q.front();
        Q.pop();
        if(src < x)
            res.push_back(src);
        else
            break;

        // 3 options as seen in the tree
        int last_digit = src%10;

        // 1. 0 at tree (can only increse once)
        if(last_digit = 0)
            Q.push(src*10 + 1);
        else if(last_digit == 9)   // 2. 9 at tree (can decrease once)
            Q.push(src*10 + 8);
        else    // 3. normal ( both less and plus)
        {
            Q.push(src*10 + (last_digit + 1));
            Q.push(src*10 + (last_digit - 1));
        }
    }
    
}

void jumpingNumbers(int x)
{
    v<int> res;
    for(int i = 1;i<=9 && i<=x;i++)
        bfs(x,i,res);
    
    sort(res.begin(),res.end())
    
    for(auto i:res)
        cout<<i<<" ";
}

int main()
{
    
    return 0;
}

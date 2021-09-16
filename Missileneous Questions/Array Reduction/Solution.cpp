#include <algorithm>
#include <iostream>
#include <vector>
#include<queue>

using namespace std;
#define v vector

int reductionCost(v<int> num)
{
    priority_queue<int,v<int>,greater<int>> q;

    for(int i =0;i<num.size();i++)
        q.push(num[i]);

    int curr = 0;
    while(q.size() != 1)
    {
        int a = q.top();
        q.pop();
        int b = 0;

        if(!q.empty())
        {
            b = q.top();
            q.pop();
        }

        curr += a+b;

        q.push(a + b);
    }

    return curr;
}
int main()
{
    return 0;
}
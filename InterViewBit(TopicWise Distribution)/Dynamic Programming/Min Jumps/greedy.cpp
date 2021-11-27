#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define v vector
#define um unordered_map
#define mod 1000000007
#define ll long long int
using namespace std;

//O(N)
int jump(vector<int> &arr) 
{
    int n = arr.size();
    if (n <= 1)
        return 0;
        
    if (arr[0] == 0)
        return -1;
 

    int maxReach = arr[0];
 
    int step = arr[0];
 
    int jump = 1;
 
    for (int i = 1; i < n; i++) 
    {
       
        if (i == n - 1)
            return jump;

        maxReach = max(maxReach, i + arr[i]);
 
        step--;
 
        if (step == 0) 
        {
            jump++;
 
            if (i >= maxReach)
                return -1;
 
            step = maxReach - i;
        }
    }
 
    return -1;
}

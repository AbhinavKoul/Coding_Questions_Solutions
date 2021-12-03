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

//https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
int minTaps(vector<int>& locations) 
    {
        int size = locations.size();
        
        v<int> range(size,0);
        
        //make rangr dp
        for(int i = 0;i<size;i++)
        {
            int left = max(i - locations[i],0);
            int right = min(i + locations[i],size-1);
            
            range[left] = max(range[left],right);
        }
        
        //can go till here in current tap open
        int right = range[0];
        //this is to keep track till where max we can go
        int curmax = range[0];
        int cnt = 0;
        for(int i = 0;i<size;i++)
        {
            curmax = max(curmax,range[i]);
            
            if(i == right)  //current tap is done
            {
                cnt++;
                right = curmax;
            }
        }
        
        if(right < size-1)
            return -1;
        return cnt;
    }
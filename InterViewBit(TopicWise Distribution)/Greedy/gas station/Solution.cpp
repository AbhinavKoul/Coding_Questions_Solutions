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

#define v vector
//O(N) one pass solution https://www.youtube.com/watch?v=0D5xNs2Fy4Q
class Solution {
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
            int sumGas = 0;
            int sumCost = 0;
            int start = 0;
            int tank = 0;
            for (int i = 0; i < gas.size(); i++) {
                sumGas += gas[i];
                sumCost += cost[i];
                tank += gas[i] - cost[i];
                if (tank < 0) {
                    start = i + 1;
                    tank = 0;
                }
            }
            if (sumGas < sumCost) {
                return -1;
            } else {
                return start;
            }
        }
};
// O(N2)
int canCompleteCircuit_bruteForce(const vector<int> &A, const vector<int> &B) {

    int n = A.size();
    v<int> leftTank;// contain amount of fuel in tank after you travel for i to i+1
    
    for(int  i = 0;i<n;i++)
    {
        int diff = A[i] - B[i];
        leftTank.push_back(diff);
    }
    
    //choose starting point
    for(int i = 0;i<n;i++)
    {
        if(leftTank[i] < 0) //if initial position you cant travel full, this cant be the answer
            continue;
        
        int store = leftTank[i];        // your car tank storage
        int j = (i+1)%n;    //circular
        while(i != j)
        {
            store += leftTank[j];   //keep updating your car tank
            if(store < 0)   //if caar tank goes empty
                break;
            
            (j+1)%n;
        }
        
        if(i == j)
            return i;
    }
    
    return -1;
    
}

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

int minCoins(v<int> coins, int M, int V) 
{ 
    // Your code goes here
    vector<int> F(M+1);
    F[0] = 0;
    for(int i = 0;i<V;i++)
    {
        int temp = 1000000007;
        int j= 1;
        while(j<=M && i>=coins[j])
        {
            temp = min(F[i-coins[j]],temp);
            j++;
        }
        F[i] = temp+1;
    }
    
    return F[M];
} 

int main()
{
    v<int> coins = {9,6,5,1};
    int M = 4;
    int V = 11;
    cout<<"ELLL   :       "<<minCoins(coins,M,V);
}
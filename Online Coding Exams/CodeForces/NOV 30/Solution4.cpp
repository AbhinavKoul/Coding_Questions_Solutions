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

int indexMoreThanX(v<int>&arr,int x)
{
    for(int i = 0;i<arr.size();i++)
    {
        if(arr[i]>x)
            return i;
    }

    return -1;
}

int minSwaps(v<int>& arr,int n,int x)
{
    int operations = 0;

    while(!is_sorted(arr.begin(),arr.end()))
    {
        int index = indexMoreThanX(arr,x);
        if(index < 0)   //not sorted but cant find the index, means not possible
            return -1;
        else
        {
            int temp;
            temp = arr[index];
            arr[index] = x;
            x = temp;

            operations++;
        }
    }
    return operations;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int test;
    cin>>test;

    while (test)
    {
        int n,x;
        cin>>n>>x;
        v<int> arr(n);
        for(auto &a:arr)
            cin>>a;
        
        cout<<minSwaps(arr,n,x)<<endl;
        
        test--;
    }
    
    return 0;
}
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

v<int> result(v<int>& arr,int n)
{
    v<int> res;
    int left = 0,right = n-1;

    while (left<right)
    {
        res.push_back(arr[left]);
        res.push_back(arr[right]);

        

        left++;
        right--;
    }

    if(left == right)
        res.push_back(arr[left]);
    
    return res;
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
        signed int n;
        cin>>n;
        v<int> arr(n);

        for(int i = 0;i<n;i++)
            cin>>arr[i];
        
        v<int> res = result(arr,n);

        for(auto i:res)
            cout<<i<<" ";
        cout<<endl;

        test--;
    }

    return 0;
}
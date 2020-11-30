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

int minSwaps(v<int> arr, int n)
{
    // Create an array of 
    // pairs where first
    // element is array element 
    // and second element
    // is position of first element
    v<pair<int, int>> arrPos(n);
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
 
    // Sort the array by array 
    // element values to
    // get right position of 
    // every element as second
    // element of pair.
    sort(arrPos.begin(), arrPos.end());
 
    // To keep track of visited elements. 
    // Initialize
    // all elements as not visited or false.
    vector<bool> vis(n, false);
 
    // Initialize result
    int ans = 0;
 
    // Traverse array elements
    for (int i = 0; i < n; i++)
    {
        // already swapped and corrected or
        // already present at correct pos
        if (vis[i] || arrPos[i].second == i)
            continue;
 
        // find out the number of  node in
        // this cycle and add in ans
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;
 
            // move to next node
            j = arrPos[j].second;
            cycle_size++;
        }
 
        // Update answer by adding current cycle. 
        if (cycle_size > 0)
        {
            ans += (cycle_size - 1);
        }
    }
 
    // Return result
    return ans;
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
        for(int i = 0;i<n;i++)
            cin>>arr[i];
        arr.insert(arr.begin(),x);
        cout<<minSwaps(arr,n+1)<<endl;
        
        test--;
    }
    
    return 0;
}
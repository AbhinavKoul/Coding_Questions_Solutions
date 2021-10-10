#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<queue>
// using namespace std;
#define v vector
using namespace std;

int min_swaps(v<int> arr1,v<int> arr2,int n)
{
    int sum1 = 0,sum2 = 0;

    for(auto i : arr1)
        sum1 += i;

    for(auto i : arr2)
        sum2 += i;
    
    //both even
    if(sum2 %2 == 0 && sum1 % 2 == 0)
        return 0;
    
    //both odd
    if(sum2 %2 != 0 && sum1 % 2 != 0)
    {
        for(int i =0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(abs(arr2[j] - arr1[i])%2 == 1)
                {
                    return 1;
                }
            }
        }
    }

    return -1;

    
}
int main()
{
    int n,m;
    v<int> arr1(n),arr2(m);
    cin>>n;

    for(int i =0;i<n;i++)
        cin>>arr1[i];
    
    cin>>m;
    for(int i =0;i<n;i++)
        cin>>arr2[i];

    cout<<min_swaps(arr1,arr2,n);
    return 0;
}
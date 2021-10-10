#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<queue>
// using namespace std;
#define v vector
using namespace std;
int possibility(v<int> passengers,v<int> boats,int n,int m,int minTime)
{
    int temp = 0,count = 0;

    while (count < m)
    {
        for(int j = 0;j<minTime && temp < n && boats[count] >= passengers[temp];j+=2)
            temp++;

        count++;
    }

    if(temp == n)
        return true;
    
    return false;
    
}
int min_time(v<int> passengers,int n, v<int> boats, int m)
{
    sort(passengers.begin(),passengers.end());
    sort(boats.begin(),boats.end());

    int low = 0, high = 2*n;

    int res = 0;

    while(low <= high)
    {
        int mid = (low + high)/2;

        if(possibility(passengers,boats,n,m,mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return res;
}
int main()
{
    int m,n;

    cin>>m>>n;
    v<int> passengers(m),boats(n);
    for(int i =0;i<m;i++)
        cin>>passengers[i];
    
    for(int i =0;i<n;i++)
        cin>>boats[i];

    cout<<min_time(passengers,m,boats,n);
    return 0;
}
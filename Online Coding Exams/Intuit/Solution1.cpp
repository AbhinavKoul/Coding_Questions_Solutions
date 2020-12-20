
// Sample code to perform I/O:
#include<iostream>
// #include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#define v vector
using namespace std;

bool isLucky(v<int> arr,v<v<int>> edges)
{
	for(int i =0 ;i<arr.size();i++)
	{
		if(!edges[arr[i+1]][arr[i]])
			return false;
	}
    return true;

}
int result(v<int> arr,v<v<int>> edges)
{
    int count = 0;
    
    do
    {
        if(isLucky(arr,edges))
            count++;
    } while (next_permutation(arr.begin(),arr.end()));

	return count;
    
}


int main()
{
    int n,m;
    cin>>n>>m;
    v<int> arr(n);

    for(int i =0;i<n;i++)
        cin>>arr[i];

    v<v<int>> edges(n,v<int>(m,0));
    for(int i = 0;i<m;i++)
    {
        int src,dest;
        cin>>src>>dest;
        edges[src][dest] = 1;
    }
    
	cout<<result(arr,edges);
    return 0;
}


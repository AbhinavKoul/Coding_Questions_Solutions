#include<iostream>
#include<vector>
#include<algorithm>
// #include<bits/stdc++.h>
#define v vector
using namespace std;

int maxIndex(const v<int>& arr)
{
    int n = arr.size();
    //transform in 2 arrays
    v<int> Lmin(n);
    v<int> Rmax(n);

    //lmin
    Lmin[0] = arr[0];
    for(int i = 1;i<n;i++)
    {
        Lmin[i] = min(arr[i],Lmin[i-1]);
    }

    //Rmax
    Rmax[n-1] = arr[n-1];
    for(int i = n-2;i>=0;i--)
    {
        Rmax[i] = max(arr[i],Rmax[i+1]);
    }

    //checking both for max index diff
    int i = 0, j = 0;
    int maxdiff = -1;

    while (j<n && i<n)
    {
        if(Lmin[i] < Rmax[j])
        {

            maxdiff = max(maxdiff,(j-i));
                        j++;
        }
        else
        {
            i++;
        }
    }


    return maxdiff;
    
}

int main()
{
    v<int> arr = {34,8,10,3,2,80,30,33,1};
    cout<<"ELLLO: "<<maxIndex(arr);
}
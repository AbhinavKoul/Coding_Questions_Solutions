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




signed int helperCounter1(signed int maxCandiesAtVal,signed int count_1)
{
    maxCandiesAtVal--;
    return ((maxCandiesAtVal +(count_1/2))%mod);

}
signed int helperCounter2(signed int maxCandiesAtVal,signed int count_1)
{
    return ((maxCandiesAtVal +(count_1/2))%mod);
}


v<int> maxCandiesDP(const v<int>& arr,signed int N)
{
    v<int> dpArr;
    if(arr[0] == 1)
    {
        dpArr.push_back(1);
        return dpArr;
    }

    dpArr.push_back(arr[0]);

    signed int val = arr[0],valIndex = 0,count_1 = 0;

    for (signed int i = 1; i < N; i++)
    {
        signed int maxAtThisPoint; //store last position max candies val

        if(count_1%2 != 0)  //if no of ones is odd
        {
            if(val%2 != 0) //if last value before ones is ODD
            {
                maxAtThisPoint = helperCounter2(dpArr[valIndex],count_1);
            }
            else
            {    
                maxAtThisPoint = helperCounter1(dpArr[valIndex],count_1);
            }
        }
        else    //if no of ones is EVEN
        {
            if(val%2 != 0)  //if last value before ones is ODD
                maxAtThisPoint = helperCounter1(dpArr[valIndex],count_1);
            else
                maxAtThisPoint = helperCounter2(dpArr[valIndex],count_1);
        }

        maxAtThisPoint = (maxAtThisPoint+arr[i])%mod;
        dpArr.push_back(maxAtThisPoint);
        
        if(arr[i] != 1)
        {
            val = arr[i];
            valIndex = i;
            count_1 = 0;
        }
        else
            count_1++; 
    }
    return dpArr;
}

signed int maxCandiesResult(const v<int>&dpArr,const long long int& R,const v<int>&arr,signed int N)
{

    if(R<=N)
    {
        if(arr[0] == 1)
            return 1;
        
        return dpArr[R-1];
    }
    signed int quotient,rem;
    long long int maxCandies = dpArr[N-1];
    quotient = ((R%mod)/N)%mod;
    rem = R%N;

    if(arr[0] == 1)
    {
        maxCandies = quotient;
        if(rem > 1)
            maxCandies = (maxCandies + 1)%mod;
        
        return maxCandies;
    }



    if(arr[N-1]%2 == 0) //if last element is even ==> need to choose odd value to keep strike
    {
        maxCandies = (maxCandies - 1)%mod;
    }

    maxCandies = (maxCandies * (quotient%mod))%mod;

    if(rem > 0)
        maxCandies = (maxCandies + dpArr[rem - 1])%mod;
    else
    {
        if(arr[N-1]%2 == 0)
            maxCandies = (maxCandies + 1)%mod;
    }
    

    return maxCandies;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;

    while (test)
    {
        signed int N,Q,R;
        v<int> dpArr;
        cin>>N;

        v<int> arr(N);
        for(signed int i =0;i<N;i++)
            cin>>arr[i];
        
        dpArr = maxCandiesDP(arr,N);
        cin>>Q;
        while (Q)
        {
            cin>>R;
            cout<<maxCandiesResult(dpArr,R,arr,N)<<"\n";
            Q--;
        }
        test--;
    }
    
    return 0;
}
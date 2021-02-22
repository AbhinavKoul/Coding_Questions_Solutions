
#include <iostream>
#include<vector>
using namespace std;
int maxSubarraySum(vector<int> &arr, int n){
    
    // Your code here
    int currSum = arr[0];
    int global_max = arr[0];
    int start,end;
    start  = end = 0;
    for(int i = 1;i<n;i++)
    {
        if(arr[i] > currSum + arr[i])
        {
            currSum = arr[i];
            start = i;
        }
        else
            currSum =  currSum + arr[i];
        
        if(currSum > global_max)
        {
            global_max = currSum;
            end = i;
        }
        
    }
    cout<<endl<<start<<" "<<end<<" "<<endl<<global_max;    
}
int main()
{
    std::vector<int> arr = {74, -72, 94, -53, -59, -3, -66, 36, -13, 22, 73, 15, -52, 75} ;
    maxSubarraySum(arr,14);

    return 0;
}
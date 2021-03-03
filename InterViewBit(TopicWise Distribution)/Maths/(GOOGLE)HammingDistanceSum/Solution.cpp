#include<iostream>
#include<vector>
using namespace std;
/*
    Time : O(N)
*/
int HammingSum_Efficient(vector<int> arr)
{
    int n = arr.size(),ans = 0,count;

    //selecting one bit at a time
    for(int i =0;i<32;i++)
    {
        // count how many values have 1 at that index
        count = 0;
        for(auto j : arr)
            if(j & (1<<i))
                count++;
        
        ans += count * (n-count) * 2;
    }

    return ans;
    
}


// ------------------------------------------ O(N^2) ----------------------------
int is_bit_set(int bitVector,int index)
{
    int mask = 1<<index;
    if((bitVector & mask) == 0)
        return 0;
    else
        return 1;
    
}
int Hamming(int a,int b)
{
    int hamming = 0;
    for(int i =0;i<32;i++)
    {
        int check =((is_bit_set(a,i) && (!is_bit_set(b,i))) || ((!is_bit_set(a,i)) && is_bit_set(b,i)) ); // 1 0 and 0 1 pair selected
        if(check)
            hamming++;
        else
            continue;
    }

    return hamming;
}
/*
    Time : O(N^2)
    Returns an int with sum of all hamming diffirences
*/
int HammingSum(vector<int> &A)
{
    int n = A.size();
    int hamming_sum = 0;
    if(n == 1)
        return 0;
    
    for(int i =0;i<n-1;i++)
        for(int j = i+1 ;j<n;j++)
            hamming_sum += Hamming(A[i],A[j]);
    
    hamming_sum *= 2;
    return hamming_sum;
}


int main()
{
    vector<int> a = {12,2,5};
    int res =  HammingSum_Efficient(a);
    cout<< "   "<< res;
    res = HammingSum(a);
    cout<< "\n   "<< res;
    return 0;
}
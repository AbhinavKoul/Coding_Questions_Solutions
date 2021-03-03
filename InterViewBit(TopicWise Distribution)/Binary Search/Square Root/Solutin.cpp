#include<iostream>
int sqrt(int A) {
    /*
    Time  : O(logN)
    BINARY SEARCH IMPLEMENTATION AS IT IS A MONOTONOUSLY INCRESIGN FN
    */
    if(A==0)
        return 0;
    if(A==1||A==2||A==3)
        return 1;
    
    // to be able to incorporate INT_MAX
    unsigned int low,high,ans;
    low = 1;
    high = A;
    // as we are doing mid*mid ==> can use int normal if mid > A/mid
    long int mid;
    while(low<=high)
    {
        mid = (low + high)/2;
        if(mid*mid > A)
            high = mid - 1;
        else
        {    low = mid + 1;
             ans  = mid;
        }
    }
    return ans;
}

int main()
{
    int res = sqrt(2147483647);
    std::cout<<"helllo :   "<<res;

}
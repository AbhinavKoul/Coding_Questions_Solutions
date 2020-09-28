#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int threeSumClosest(vector<int> &A, int target) {
    sort(A.begin(),A.end());                    // O(NlogN)
    long least_sum =1000000000,sum=0;
    int i,j;
    for(int n = 0;n<(A.size() - 2);n++)         // O(N2)
    {
        i = n + 1;
        j = A.size() - 1;
        
        while(i<j)
        {
            sum = long(A[n]) + long(A[i]) + long(A[j]);
            
            if(abs(target - sum)<abs(target - least_sum))
                least_sum = sum;
            if(sum == target)
                return sum;
            else if(sum < target)
                i++;
            else
                j--;
        }
    }
    
    return least_sum;
}

int main()
{ 
    vector<int> A = {2147483647, -2147483648, -2147483648, 0, 1};   //THATS WHY LONG IS NEEDED AND WHY PASS BY REFERENCE 

    int target = 0;
    cout<< threeSumClosest(A,target);
}
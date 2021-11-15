#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int trap(const vector<int> &v) {
    int A =v.size();
    vector<int> maxR(A);
    vector<int> maxL(A);
    
    // find the max wall from left side
    maxL[0]=v[0];
    for(int i=1;i<A;i++)
        maxL[i]=max(maxL[i-1],v[i]);
    
    //find max wall from right side
    maxR[A-1]=v[A-1];
    for(int i=A-2;i>=0;i--)
        maxR[i]=max(maxR[i+1],v[i]);
    
    //find min wall length cause after that it will overflow
    vector<int> water(A);
    for(int i=0;i<A;i++)
        water[i]=min(maxL[i],maxR[i])-v[i]; //subtract current wall length cause that can't store water
    
    int sum=0;
    for(int i=0;i<A;i++)
        sum+=water[i];
    return sum;
}

class Solution {
    public:
        int trap(int A[], int n) 
        {
            /*
            Same approach as before but without various vectors
            */
            int left = 0; int right = n - 1;
            int res = 0;
            int maxleft = 0, maxright = 0;

            while(left <= right)    //till left wALL is before right wall
            {
                if(A[left] <= A[right])
                {
                    if(A[left] >= maxleft)
                        maxleft = A[left];
                    else 
                        res += maxleft-A[left];
                    
                    left++;
                }
                else
                {
                    if(A[right] >= maxright) 
                        maxright = A[right];
                    else 
                        res += maxright - A[right];
                    
                    right--;
                }
            }
            return res;
        }
};
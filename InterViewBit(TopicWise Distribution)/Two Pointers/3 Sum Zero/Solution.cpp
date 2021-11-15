#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#define ll long long
using namespace std;

vector<vector<int> > threeSumZero(vector<int> &A) {
    sort(A.begin(),A.end());
    int n = A.size();
    ll sum;
    vector<vector<int>>v;
    set<vector<int>>s;
    for(int i = 0; i < n-2;i++ )
    {
        int j = i+1;
        int k = n-1;
        while(j<k)
        {
            sum = ll(A[i])+ll(A[j])+ll(A[k]);
            if( sum == 0 )
            {
                vector<int> triplets = {A[i],A[j],A[k]};
                s.insert(triplets);
                k--;
            }
            else if( sum<0 )
                    j++;
                else 
                    k--;
        }
    }
    for(auto i = s.begin();i!=s.end();i++)
    {
        v.push_back(*i);
    }
    return v;
}

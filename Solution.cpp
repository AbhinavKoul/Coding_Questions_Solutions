#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;

#define v vector
unordered_map<int,set<int>> um = {
    {2 , {2}},
    {3 , {3}},
    {5 , {5}},
    {7 , {7}},
    {11, {11}},
    {13, {13}},
    {17, {17}},
    {19, {19}},
    {23, {23}},
    {29, {29}},
    {6 , {3,2}},
    {10 ,{5,2}},
    {14 ,{7,2}},
    {15 ,{5,3}},
    {21 ,{7,3}},
    {22 ,{11,2}},
    {26 ,{13,2}},
    {30 ,{2,3,5}}
};

// set<int> primes = {2,3,5,7,11,13,17,19,23,29};
// set<int> acceptable = {6,10,14,15,21,22,26,30};

long long solve(v<int> arr)
{
    int n = arr.size();
    v<int> res;
    
    for(int i = 0; i<n;i++)
    {
        if(um.find(arr[i])!= um.end())
            res.push_back(arr[i]);
    }

    cout<<"res : \n";
    for(auto i : res)
        cout<<i<<' ';


    queue<int> goagain;

    goagain.push(0);
    int ans_a = 0;
    v<bool> visited(res.size(),false);
    while(!goagain.empty())             // {2,3,5,15,22,26}
    {
        int count = 1;                                      // 22 26
        ans_a += 1;
        int left = goagain.front(); goagain.pop();
        visited[left] = true;

        set<int> factors_till_now(um[res[left]]);   // 5 3 2 
        int right = 0;

        while(right < res.size())
        {
            if(right != left)
            {
                
                v<int> K;
                set_intersection(um[res[right]].begin(),um[res[right]].end(),factors_till_now.begin(),factors_till_now.end(),back_inserter(K));

                if(K.size() == 0)   //have nothing in common
                {
                    v<int> factor;
                    set_union(um[res[right]].begin(),um[res[right]].end(),factors_till_now.begin(),factors_till_now.end(),back_inserter(factor));
                    
                    if(!visited[right])
                    {
                        ans_a += pow(2,count);
                    }
                    else
                    {
                        ans_a += pow(2,count - 1);
                    }

                    count++;
                    visited[right] = true;
                    factors_till_now.insert(factor.begin(),factor.end());
                }
                else if(!visited[right])
                {
                    goagain.push(right);
                }
            }
            
            right++;
        }

    }
    
    
    return ans_a;

}
int main()
{
    // int test;
    // cin>>test;

    // while (test--)
    // {
    //     v<int>  = 

    // }
    
    v<int> ar = {2,2};
    cout<<"hello  :  "<<solve(ar);


}
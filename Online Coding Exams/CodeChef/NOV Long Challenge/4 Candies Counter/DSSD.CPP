#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#include<map>
#define v vector
#define um unordered_map
#define mod 1000000007
using namespace std;

    maxOppositeTeam += (count_1 - (count_1/2)%mod)%mod;
            v<int> arr = {999999999};

    int N = arr.size();
    maxCandiesDP(arr,N);

    printVector(arr);
    printVector(dpArr);
    cout<<"HELLLO    : "<<maxCandiesResult(999999999,arr,N);




int lengthOfLongestSubstring(string s) {
        int i,j,n,k,ans=0;
        map<char,int> d;
        n=s.length();
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        i=0;
        for(k=0;k<n;k++){
            auto itr = d.find(s[k]);
            if(itr==d.end()){
                 d.insert({s[k],k});
            }
               
            else{
                ans=max(ans,k-i);
                int p=d[s[k]]+1;
                for(j=i;j<p;j++){
                    auto it = d.find(s[j]);
                    d.erase(it);
                    it=d.end();
                }
                i = p;
            }
        }
        ans=max(ans,k-i);
        return ans;
    }

int main()

{
    string arr = "abcabcbb";
    cout<<"hellooooo : "<<lengthOfLongestSubstring(arr);
    return 0;
}
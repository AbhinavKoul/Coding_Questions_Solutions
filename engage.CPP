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
// int solution(vector<int> &A) {
//     // write your code in C++14 (g++ 6.2.0)
//     map<int,int> mp;
//     for(auto x:A){
//         mp[x]=0;
//     }

//     int j=0,i=0;
//     int res=99999;
//     while(j<A.size()){
//         mp[A[j]]++;
//         bool flag=false;
//         for(auto x:mp){
//             if(x.second==0){
//                 flag=true;
//                 break;
//             }
//         }

//         if(!flag){
//             while(mp[A[i]]>1){
//                 res=min(res,j-i+1);
//                 mp[A[i]]-=1;
//                 i++;
//             }
//            res=min(res,j-i+1);
//         }

//         j++;
//     }

//     return res;
// }

#include<bits/stdc++.h>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    map<int,int> mp;
    set<int> s;
    for(auto x:A)
        s.insert(x);
    int cnt = s.size();
    int j=0,i=0;
    int res=INT_MAX;
    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    while(j<A.size()){
        mp[A[j]]++;
        // bool flag=false;
        

        if(mp.size()==cnt){
            while(mp[A[i]]>1){
                mp[A[i]]-=1;
                i++;
                res=min(res,j-i+1);
            }
             res=min(res,j-i+1);
        }

        j++;
    }

    return res;
}

int main()
{
    v<int> arr = {};
    cout<<"hello : "<<solution(arr);

    return 0;

}

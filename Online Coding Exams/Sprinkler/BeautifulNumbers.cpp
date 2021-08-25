#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;
#define v vector

typedef long long ll;

bool check(ll n){
    unordered_map<ll,ll> mp;
    while(n){
        int rem = n%10;
        mp[rem]++;
        n=n/10;
    }
    
    int track=-1;
    for(auto i=mp.begin();i!=mp.end();i++){
       if((*i).first!=(*i).second)
        return false;
    }
    
    return true;
}

ll find(ll n){
    int curr=n+1;
    bool flag=false;
    while(true){
        if(check(curr)){
            flag=true;
            return curr;
        }
        curr++;
    }
    
    return -1;
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n; 
        cout<<find(n)<<endl;
    }
    
    return 0;
}
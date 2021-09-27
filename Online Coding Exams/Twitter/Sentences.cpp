#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;
#define v vector
// using namespace std;


vector<long> find(vector<string>&wordSet,vector<vector<string>> &sentences){
 
    for(int i=0;i<wordSet.size();i++){
        sort(wordSet[i].begin(),wordSet[i].end());
    }
    
    unordered_map<string,long> mp;
    for(auto x:wordSet){
        mp[x]++;
    }

    
    vector<long> a;
    for(auto x:sentences){
        long ans=1;
        for(auto &y:x){
           
            sort(y.begin(),y.end());
            if(mp.find(y)!=mp.end())
                ans*=mp[y];
        }
        a.push_back(ans);
    }
    
    return a;
}

void solve(){
    vector<string> word={"the","bats","tabs","in","cat","act"};
    vector<vector<string>> sentences={
        {"cat","the","bats"},
        {"in","the","act"},
        {"act","tabs","in"},
    };
        
    vector<long> ans = find(word,sentences);
    for(auto x:ans){
        cout<<x<<endl;
    }
}

int main() {
	int t=1;
// 	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}


/**
 *    author:  abhishekvtangod
**/
// #undef _GLIBCXX_DEBUG
// #undef _ABHI
// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
#ifdef _GLIBCXX_DEBUG
#define debug(x...) cerr << "[" << #x << "]:[", cus_debug(x)
#else
#define debug(...) 42
#endif

string to_string(const char &c){
	string s = "";
	s += c;
	return s;
}

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a/gcd(a,b)*b  // no overflow
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

long long n;
vector<vector<ll>> subsq;
vector<ll> v;
vector<ll> temp = {2, 3, 5, 6, 7, 10, 11, 13, 14, 15, 17, 19, 21, 22, 23, 29, 30};
map<ll, ll> mp;


void PRE_Compute(int idx, vector<ll> sb, ll prod){
	if(idx == temp.size()){
		subsq.push_back(sb);
		return;
	}

	PRE_Compute(idx+1, sb, prod); // do not include

	//include
	if(gcd(prod, temp[idx]) == 1){
		sb.push_back(temp[idx]);
		PRE_Compute(idx+1, sb, (prod*temp[idx])%mod);
	}
}


// start of CP 2.0
void solve(){
	cin >> n;

	for(int i = 0; i < n; i++){
		ll temp;
		cin >> temp;
		v.push_back(temp);
		mp[temp] = (mp[temp] + 1) % mod;
	}
	ll ans = 0;
	for(int i = 0; i < subsq.size(); i++){
		if(subsq[i].size()<=0)continue;
		ll temp = 1;
		for(int j = 0; j < subsq[i].size(); j++){
			temp = (temp%mod * mp[subsq[i][j]]%mod)%mod;
		}
		ans = (ans + temp)%mod;
	}
	cout << ans << endl;
	
}

int main()
{   
	IOS;

 	#ifdef _ABHI
		freopen("/home/abhi/Documents/input.txt", "r", stdin);
		freopen("/home/abhi/Documents/output.txt", "w", stdout);
	#endif 
	vector<ll> sb;
 	PRE_Compute(0, sb, 1);
 	// debug(subsq.size());
 	// debug(subsq);
	ll t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	

    return 0;
}
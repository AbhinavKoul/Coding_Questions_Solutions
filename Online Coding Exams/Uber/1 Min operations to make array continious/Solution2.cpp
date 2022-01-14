#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(long i=a;i<b;i++)
#define pb push_back
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end() 
 
int n;
 

int main(){
fastio;



	cin>>n;
	vector<int> A;
	unordered_map<int,bool> oup;

	FOR(i,0,n){int t; cin>>t; if(oup.find(t)==oup.end()){A.pb(t); oup[t]=1; } }
	sort(all(A));
	int ans=1e9;
	FOR(i,0,A.size()){
		int s=A[i]+n-1;
		int pos=lower_bound(all(A),s)-upper_bound(all(A),A[i]);
		pos++;
		//cout<<pos<<"\n";
		ans=min(ans,n-pos);
	}


cout<<ans<<"\n";

return 0;}
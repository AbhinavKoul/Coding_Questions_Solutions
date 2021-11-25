#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

ll getCurrentWeight(ll a, ll b, ll c) {
	return a * b + b * c - b * b -  a * c;
}

void solve(ll arr[], int n) {
	ll ans = 0;
	for (int start = 0; start + 2 < n; start++) {
		int mid = start + 1;
		for (int end = start + 2; end < n; end++) {
			ll currentAns = getCurrentWeight(arr[start], arr[mid], arr[end]);
			while (mid + 1 < end) {
				ll x = getCurrentWeight(arr[start], arr[mid + 1], arr[end]);
				if (x < currentAns) break;

				mid++;
				currentAns = x;
			}

			ans += currentAns;
		}
	}
	cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		ll arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		solve(arr, n);
	}
}


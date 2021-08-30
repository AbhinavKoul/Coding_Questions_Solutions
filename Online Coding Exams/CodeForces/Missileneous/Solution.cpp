#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define v vector
#define um unordered_map
#define mod 1000000007
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
 
	int T; cin >> T;
	while (T--) {
		int N; 
        cin >> N;
		v<int> A(N);
        for(auto &a : A)
        {
            cin>>a;
            a &=1;
        }
    
		
 
		v<int> odd_parity_pos; 
        odd_parity_pos.reserve(N);

		for (int i = 0; i < N; i++)
			if(A[i]) 
                odd_parity_pos.push_back(i);
		
        int64_t ans = -1;
		for (int z = 0; z < 2; z++) 
        {
			v<int> pos2; pos2.reserve(N);

			for (int i = z; i < N; i += 2)
				pos2.push_back(i);

			if (odd_parity_pos.size() == pos2.size()) 
            {
				int64_t cnd = 0;
				
                for (int a = 0; a < int(odd_parity_pos.size()); a++) 
                    cnd += abs(odd_parity_pos[a] - pos2[a]);
				
                if (ans == -1 || cnd < ans) 
                    ans = cnd;
			}
		}
		cout << ans << '\n';
	}
 
	return 0;
}
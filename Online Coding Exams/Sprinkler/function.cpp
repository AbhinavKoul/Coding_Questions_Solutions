#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<set>
#include<bitset>
#include<math.h>
using namespace std;
#define mod 1000000009
typedef long long ll;
#define v vector

int maxSetBit(int n)
{
    return (int)(log2(n));
}
ll findValueBitwise(v<ll> arr)
{
    int n = arr.size();
    ll maximum = *max_element(arr.begin(),arr.end());
    int k = maxSetBit(maximum);
    v<bitset<20>> bit_arr(n);

    for(int i =0;i<n;i++)
        bit_arr[i] = bitset<20>(arr[i]);

    ll ans = 0;
    for(int bit = 0;bit<=k;bit++)
    {
        for(int i = 0;i<n-1;i++)
        {
            if(!bit_arr[i].test(bit))
                continue;
            
            for(int j = i+1;j<n;j++)
            {
                if(!bit_arr[j].test(bit))
                    continue;
                
                ans = (ans + (1<<bit)%mod)%mod;
            }
        }
    }

    return ans%mod;
}

ll findValue(int n,int arr[]){
    long long ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=0;k<=1e3;k++){
                int val1 = ((arr[i]>>k)%2)<<k;
                int val2 = (arr[j]>>k)%2;
                ans += (val1*val2);
                // cout<<val1<<" "<<val2<<endl;
                if(arr[i]>>k==0 || arr[j]>>k==0)
                    break;
            }
        }
    }

    return ans;
}

int main(){
    int n=3;
    int arr[]={88,78};
    v<ll> arr1 = {34,48,8,72,67,90};
    cout<<"hello : "<<findValueBitwise(arr1);
    return 0;
}
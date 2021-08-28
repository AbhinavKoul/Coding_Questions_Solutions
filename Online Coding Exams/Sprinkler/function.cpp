#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;
#define v vector
#define ll long long 

// typedef long long ll;

ll findValue(int n,int arr[]){
    long long ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=0;k<=1e3;k++){
                int val1 = pow(2,k)*(((arr[i]*arr[j])/(int)pow(2,2*k))%2);
                ans += (val1*val2);
                // cout<<val1<<" "<<val2<<endl;
                if(arr[i]/(int)pow(2,k)==0 && arr[j]/(int)pow(2,k) ==0)
                    break;
            }
        }
    }

    return ans;
}

int main(){
    int n=2;
    int arr[]={11,39};
    cout<<findValue(n,arr);
    return 0;
}

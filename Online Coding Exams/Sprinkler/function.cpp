#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
#define v vector
using namespace std;

typedef long long ll;

ll findValue(int n,int arr[]){
    long long ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=0;k<=1e3;k++){
                int val1 = pow(2,k)*((arr[i]/(int)pow(2,k))%2);
                int val2 = (arr[j]/(int)pow(2,k))%2;
                ans+=(val1*val2);
                // cout<<val1<<" "<<val2<<endl;
                if(arr[i]/(int)pow(2,k)==0 && arr[j]/(int)pow(2,k) ==0)
                    break;
            }
        }
    }

    return ans;
}

int main(){
    int n=6;
    int arr[]={34,48,8,72,67,90};
    cout<<findValue(n,arr);
    return 0;
}
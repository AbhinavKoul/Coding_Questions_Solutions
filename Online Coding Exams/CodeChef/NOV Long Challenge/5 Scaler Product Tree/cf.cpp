#include<iostream>
#include<vector>
#include <cmath>
using namespace std;
 
 
bool check(vector<long long int> a, int sum){
    long long int t1=a[0],t2=sum-a[0];
    int flag=0;
    int n= a.size();
    if(t1==t2)
        return true;
    for(int i=1; i<n;i++){
        t1+=a[i];
        t2-=a[i];
        if(t1==t2){
            flag=1;
         return true;   
        }
    }
    if(flag==0)
        return false;
}

int main(){
    long long int t,n,elem,i;
    bool res;
    cin>>t;
    while(t>0){
        vector<long long int> arr,a;
        long long int sum=0;
        cin>>n;
        for(i=0;i<n;i++){
            cin>>elem;
            arr.push_back(elem);
            int p = pow(2,elem);
            cout<<p<<" ";
            a.push_back(p);
            sum+=p;
        }
        cout<<sum;
        res= check(a,sum);
        if(res==true)
            cout<<"YES";
        else
            cout<<"NO";
        t--;
    }
}
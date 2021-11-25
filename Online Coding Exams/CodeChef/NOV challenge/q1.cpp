#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define v vector
#define um unordered_map
#define mod 1000000007
#define ll long long int
using namespace std;
bool compare(int& x, int& y)
{
    //stoll for string to long long
    long long int xy=stoll(to_string(x)+to_string(y));
    long long int yx=stoll(to_string(y)+to_string(x));
    return xy<=yx;
}
string largestNumber(const vector<int>& A)
{
    /*
        time : O(Nlog(N))
        Space: O(N)
    */
    string ans="";
    // copy vector A in vector B
    vector<int> B(A);
    // sort as per the condition we found
    sort(B.begin(),B.end(),compare);
    // add sorted B elements one by one to output string
    for(auto val:B)
        ans+=to_string(val);
    // If 1st char has 0 which means this is highest and thus answer can only be 0
    return (ans[0]=='0')?"0":ans;
}

int main() 
{
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test;
    cin>>test;

    while (test--)
    {
        int N,K;
        cin>>N>>K;

        v<ll> arr(N);

        for(int i = 0;i<N;i++)
            cin>>arr[i];

        sort(arr.begin(),arr.end());
        
        if(arr[K-1] == arr[K])
        {
            cout<<"-1\n";
            continue;
        }
            

        v<int> a;
        if(K!=1)
            a.push_back(arr[0]);

        for(int i = K;i<N;i++)
            a.push_back(arr[i]);

        string res = largestNumber(a);

        for(auto i : res)
            cout<<i<<" ";
        
        if(K!=1)
            for(int i = 1;i<K;i++)
                cout<<arr[i]<<" ";
        else
            cout<<arr[0]<<" ";

        cout<<"\n"; 
        

    }
    

    return 0;
}
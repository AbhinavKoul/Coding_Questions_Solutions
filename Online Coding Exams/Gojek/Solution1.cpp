#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define fileopen freopen("input.in", "r", stdin);
#define fileclose freopen("out.txt", "w+", stdout);
#define Fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define v vector
#define um unordered_map
#define mod 1000000007
using namespace std;

int main()
{
    Fio;
    fileopen
    fileclose

    int test;
    cin>>test;

    for(int i = 1;i<= test;i++)
    {
        signed int a,b,x;
        cin>>a>>b>>x;

        signed int res1,res2;
        res1 = b/x;
        res2 = (a - 1)/x;       

        cout<<"Case "<<i<<": "<< abs(res1 - res2);
        cout<<endl;
    }

    return 0;
}
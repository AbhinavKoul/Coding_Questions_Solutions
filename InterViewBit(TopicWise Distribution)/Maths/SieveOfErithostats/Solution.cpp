#include<iostream>
#include<vector>
using namespace std;

/*
Time : O(N log(logN))

    innermost llop ==> N/2 + N/3 + N/5 + N/7 ...... ==> loglog(N)
*/
vector<int> sieveOfErithostats(int n) {
    int isPrime[n+1];
    vector<int> res;
    for(int i = 2; i<=n;i++)
        isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;
    
    for(int i =2;i<=sqrt(n);i++)
    {
        if(isPrime[i] == 1)
        {
            for(int j =2; i*j <= n; j++)
                isPrime[i*j] = 0;
        }
    }
    
    for(int i =2;i<=n;i++)
        if(isPrime[i] == 1)
            res.push_back(i);
    
    return res;
}


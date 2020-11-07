#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define v vector
using namespace std;
v<int> prime_map;
// C++ program to print all primes smaller than or equal to 
// n using Sieve of Eratosthenes 
 
v<int> SieveOfEratosthenes(int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    v<bool> prime(n+1,true); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    v<int> primes;
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
            primes.push_back(p);
    
    return primes;
          
} 
  

v<int> restoreSequences(const v<int>& B)
{
    int n = B.size();

    v<int> res(n,0);

    for(int i = 1;i<=n;i++)
    {
        if(res[i] == 0)
        {
            if(res[B[i]] == 0)
                res[i] = res[B[i]] = prime_map[i];
            else
                res[i] = res[B[i]];
            
        }
    }

    return res;

}

int main()
{
    

    prime_map = SieveOfEratosthenes(1299709);
    prime_map.insert(prime_map.begin(),0);

    int test;
    cin>>test;

    while (test)
    {
        int n;
        cin>>n;
        v<int> B(n+1);
        v<int> res;
        B[0] = 0;
        for(int i = 1;i<=n;i++)
            cin>>B[i];

        res = restoreSequences(B);
        cout<<endl;
        for(auto i : res)
            cout<<i<<" "; 

        test--;
    }
    

        
    return 0;
}
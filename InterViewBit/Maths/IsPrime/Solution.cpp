#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

bool isPrime(int n)
{
    if(n==0 || n==1)
        return false;
    
    for(int i = 2; i<=sqrt(n);i++)
        if(n % i == 0)
            return false;
    
    return true;
}
int main()
{
    int N = 100, A = 13;
    if(isPrime(N))
        cout<<N<<" is a prime no.\n";
    else
        cout<<N<<" is not a prime no.\n";

    if(isPrime(A))
        cout<<A<<" is a prime no.\n";
    else
        cout<<A<<" is not a prime no.\n";

    return 0;

}
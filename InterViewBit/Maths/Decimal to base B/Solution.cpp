#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string DecimalToBinary(int n)
{
    int rem;
    string binary_rep;
    if(n==0)
        return("0");
    while(n>0)
    {
        rem = n % 2;
        binary_rep.append(to_string(rem));
        n = n/2;
    }
    
    reverse(binary_rep.begin(),binary_rep.end());
    return binary_rep;
}

int main()
{
    cout << "Binary : " << DecimalToBinary(10) << "  ";
    return 0;
}
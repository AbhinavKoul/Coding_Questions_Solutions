#include<string>
using namespace std;


int titleToNumber(string A) {
    int n = A.size();
    int sum = 0;
    for(int i = 0;i<n;i++)
        sum += (A[i] - 'A' + 1)*pow(26,n-i-1);
    
    return sum;
}
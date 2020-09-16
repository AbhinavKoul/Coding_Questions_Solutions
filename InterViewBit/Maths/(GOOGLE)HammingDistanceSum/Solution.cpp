#include<iostream>
#include<vector>
using namespace std;
int is_bit_set(int bitVector,int index)
{
    int mask = 1<<index;
    if((bitVector & mask) == 0)
        return 0;
    else
        return 1;
    
}
int Hamming(int a,int b)
{
    int hamming = 0;
    for(int i =0;i<32;i++)
    {
        int check =((is_bit_set(a,i) && (!is_bit_set(b,i))) || ((!is_bit_set(a,i)) && is_bit_set(b,i)) ); // 1 0 and 0 1 pair selected
        if(check)
            hamming++;
        else
            continue;
    }

    return hamming;
}

int HammingSum(vector<int> &A)
{
    int n = A.size();
    int hamming_sum = 0;
    if(n == 1)
        return 0;
    
    for(int i =0;i<n-1;i++)
        for(int j = i+1 ;j<n;j++)
            hamming_sum += Hamming(A[i],A[j]);
    
    hamming_sum *= 2;
    return hamming_sum;
}


int main()
{
    cout<< "   "<< Hamming(12,2);
    return 0;
}
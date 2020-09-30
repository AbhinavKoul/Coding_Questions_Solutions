#include<iostream>
#include<vector>
using namespace std;

vector<int> findPattern(int n,vector<int> A,vector<int> B,vector<int> C)
{
    vector<int> res;
    res.push_back(A[0]);
    int val;
    for(int i = 1;i<n;i++)
    {
        if(i == n-1)
        {
            if(A[i] == res[i-1])
            {
                val = A[i];
            }
            if(B[i] == res[i-1])
            {
                val = B[i];
            }
            if(C[i] == res[i-1])
                val = C[i];
        }
        else
        {
            if(A[i] == res[i-1])
                if(B[i] == res[i-1])
                    res.push_back(C[i]);
                else
                    res.push_back(B[i]);
            else
                res.push_back(A[i]);
        }
        
        
    }

    if(val == A[n-1])
    {
        if(val == B[n-1])
        {
            res.push_back(C[n-1]);
        }
        else
        {
            if(res[0] == B[n-1])
                res.push_back(C[n-1]);
            else
            {
                res.push_back(B[n-1]);
            }
        }
    }
    else
    {
        if(res[0] == A[n-1])
        {
                if(val == B[n-1])
            {
                res.push_back(C[n-1]);
            }
            else
            {
                if(res[0] == B[n-1])
                    res.push_back(C[n-1]);
                else
                {
                    res.push_back(B[n-1]);
                }
            }
        }
        else
        {
            res.push_back(A[n-1]);
        }
        
    }
    
    
    return res;
}
void insertVector(vector<int> &A,int n)
{
    for(int i =0;i<n;i++)
        cin>>A[i];
}
void displayVector(vector<int> &A)
{
    for(auto i:A)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
int main()
{
    int test;
    cin>>test;

    while(test)
    {
        int n;
        cin>>n;
        vector<int> A(n),B(n),C(n);
        insertVector(A,n);
        insertVector(B,n);
        insertVector(C,n);
        vector<int> res = findPattern(n,A,B,C);
        displayVector(res);
        test--;
    }
    return 0;
}

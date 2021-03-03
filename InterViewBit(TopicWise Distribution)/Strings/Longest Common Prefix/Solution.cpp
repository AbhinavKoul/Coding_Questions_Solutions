#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string longestCommonPrefix(vector<string> &A)
{
    /*
    O(NlogN)
    */
    string s = "";
    // string the strings lexicographically
    sort(A.begin(),A.end());
    int m,n;
    m = A.size() - 1;
    n = min(A[0].length(),A[m].length());

    int i = 0;
    //first and last string comparision as they will be the most dissimilar
    while (i<n && A[0][i] == A[m][i])
    {
        s.push_back(A[0][i]);
        i++;
    }
    
    return s;
}

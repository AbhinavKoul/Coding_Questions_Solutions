#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > performOps(vector<vector<int> > &A) {
    vector<vector<int> > B;
    B.resize(A.size()); // A.size just returns 3 here (OUTER SIZE ONLY ==> NOT COMPLETE SIZE)
                        // FOR INNER SIZE ==> A[].size()
    for (int i = 0; i < A.size(); i++) {
        B[i].resize(A[i].size());
        for (int j = 0; j < A[i].size(); j++) {
            B[i][A[i].size() - 1 - j] = A[i][j];//assigning value from end
        }
    }
    return B;
}

int main()
{
    vector<vector<int>> A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}; 

    vector<vector<int> > B = performOps(A);
    for(int i = 0; i < B.size(); i++){ 
        for (int j = 0; j < B[i].size(); j++) 
            cout<<B[i][j]<<" ";
        cout<<endl;
    }
}
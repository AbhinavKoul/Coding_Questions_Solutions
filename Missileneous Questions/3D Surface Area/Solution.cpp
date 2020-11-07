#include<iostream>
#include<vector>
#include<algorithm>
#define v vector
using namespace std;

using namespace std;
#define v vector
vector<string> split_string(string);

// Complete the surfaceArea function below.
int surfaceArea(vector<vector<int>> A) {
    A.insert(A.begin(),v<int>(0,A[0].size()));

    for(auto i : A)
    {
        i.insert(i.begin(),0);
        i.push_back(0);
    }
    A.push_back(v<int>(0,A[0].size()));

    for(auto i : A)
    {
        cout<<endl;
        for(auto val:i)
            cout<<val<<" ";
    }
    return 0;
}

int main()
{
    surfaceArea({{1,3,4},
                 {2,2,3},
                 {1,2,4}
                });

    return 0;
}
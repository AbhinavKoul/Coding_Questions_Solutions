#include<iostream>
#include<vector>
using namespace std;


void rearrangeArrayInPlace(vector<int> &Vec) {
    int N = Vec.size();
    // store A in each cell st. A = B + C*N
    for(int i = 0; i < N; ++i) {
        Vec[i] = Vec[i] + (Vec[Vec[i]]%N) * N;
    }
    // extract new value by A/N
    for(int i = 0; i < N; ++i) {
        Vec[i] = Vec[i] / N;
    }
}

int main()
{
    vector<int> array = {1,1,3,4,3,5};
    rearrangeArrayInPlace(array);
    cout<<endl;
    for(auto i : array)
        cout<<i<<" ";

}
#include<iostream>
#include<vector>

using namespace std;
template<class T=int, class U=int>
vector<T> rangeE(T start, T stop, U step=1){
    /*
    range() function using C++
    Exclusive ranges
    */
    std::vector<T> v;
    if(step < 0)
    {
        while(1) {
            if (start <= stop) {
                break;
            }
            v.push_back(start);
            start += step;
        }
        return v;
    }
    else
    {
        while(1) {
            if (start >= stop) {
                break;
            }
            v.push_back(start);
            start += step;
        }
        return v;
    }
}
void print_Spiral(vector<vector<int>> A,int r1,int r2,int c1,int c2)
{
    // if nothing left to print
    if( ((c2-c1)< 0) || ((r2-r1)<0))
        return;
    // if only one row or col left to print
    if(r1 == r2)
    {   
        for(auto i : rangeE(c1,c2+1,1))
            cout<< A[r1][i]<< " ";
        return;
    }
    if(c2 == c1)
    {
        for(auto i : rangeE(r1,r2+1,1))
            cout<< A[i][c1]<< " ";
        return;
    }
    
    //normal case
    
    for(auto i : rangeE(c1,c2,1))
        cout<< A[r1][i]<< " ";
    for(auto i : rangeE(r1,r2,1))
        cout<< A[i][c2]<< " ";
    for(auto i :rangeE(c2,c1,-1))
        cout<< A[r2][i]<<" ";
    for(auto i :rangeE(r2,r1,-1))
        cout<< A[i][c1] << " ";

    //recursion to go to inner similar structure
    print_Spiral(A,r1+1,r2-1,c1+1,c2-1);
}


int main()
{
    vector<vector<int>> A = {
                                {1,2,3,4},
                                {5,6,7,8},
                                {9,10,11,12},
                                {13,14,15,16}
                            
                            };
    int R = 4, C =4;
    int r1,r2,c1,c2;
    r1 = 0, r2 = R -1 , c1 = 0 , c2 =C - 1;
    print_Spiral(A,r1,r2,c1,c2);
    return 0;
}
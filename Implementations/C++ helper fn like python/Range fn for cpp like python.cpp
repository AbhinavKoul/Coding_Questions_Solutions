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
int main()
{
    //std::vector<char> v = rangeE('a', 'z', 1 );
    // std::vector<char> v = rangeE('A', 'z', 3);
     std::vector<int> v = rangeE(100, 0, -4);
    // std::vector<float> v = rangeE<float, float>(10.3, 345.3, 0.4);
    // std::vector<int> v = rangeE(10, 100);
    //std::vector<float> v = rangeE<float, float> (0, 100, 0.5);
    for(auto i: v){
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}
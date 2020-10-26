#include<iostream>
#include<vector>
#include<algorithm>
#define v vector
using namespace std;

bool towerHopperProblem(const v<int> &arr)
{
    int n = arr.size();
    v<int> range(n,-1);

    // create range array
    for(int i=0;i<n;i++)
        range[i] = i + arr[i];


    int right = 0,left = 0;
    while (left <= right)
    {   
        right = max(right,range[left]);
        
        //always increment left
        left += 1;
    }

    if(right >= n)
        return true;
    else
        return false;
}


int main()
{
    v<int> inp = {2,3,1,0,1,0};
    v<int> inp2 = {4,2,0,0,2,0};
    
    if(towerHopperProblem(inp))
        cout<<"\ntower is hoppable";
    else
        cout<<"\n tower not hoppable";

    if(towerHopperProblem(inp2))
        cout<<"\ntower is hoppable";
    else
        cout<<"\n tower not hoppable";
    return 0;
}
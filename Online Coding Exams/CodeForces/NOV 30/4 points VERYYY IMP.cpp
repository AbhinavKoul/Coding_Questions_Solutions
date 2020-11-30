#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define v vector
#define um unordered_map
#define mod 1000000007
using namespace std;

int64_t variable_K = int(1e9) + 5;

long long int costFn_Val(int64_t K,v<int64_t> CostX,v<int64_t> CostY)
{
    /*
    I  will keep trying to find K such that 2 mid points overlap and thus both become median and then i calculate steps taken by end points to reach that median.
    ==> Thus i need right end of the convex fn rather than left where[l,r] is the range where we have equal values 
    l : when all 4 points overlap (in pairls of 2)
    r : when onlt 2 middle(median) points overlap
    */
    CostX[1] -= K;
    CostX[3] -= K;
    CostY[2] -= K;
    CostY[3] -= K;

    sort(CostX.begin(),CostX.end());
    sort(CostY.begin(),CostY.end());
    long long int cost = 0;

    for(int i = 0;i<4;i++)
    {
        // for X the convex fn is SUM OF DIFF WITH THE MEDIAN!
        // for y the onvex fn is SUM OF DIFF WITH MEDIAN!
        // adding both we get another convex fn
        cost += abs(CostX[i] - CostX[1]) + abs(CostY[i] - CostY[1]); 
    }
    return cost;
}

int64_t minStepsToMakeASquare(v<int64_t>& X,v<int64_t>& Y)
{
    v<int64_t> OrigX = X, OrigY = Y;

    v<int> permutaion_arr = {0,1,2,3};

    int64_t best = variable_K*variable_K;

    do
    {
        //select each ermutation X and Y and then calculate the cost function convex fn and apply kinda regression using binary search kinda thing

        for(int i = 0;i<4;i++)
        {
            X[i] = OrigX[permutaion_arr[i]];
            Y[i] = OrigY[permutaion_arr[i]];
        }

        int64_t low = 0, high = 2*variable_K;   //since we have a convex fn for COST vs K(where K s side length of square) ==> similar to regression, we will minimize the cost fn and keep chexking

        while(low<high)
        {
             /*
            I  will keep trying to find K such that 2 mid points overlap and thus both become median and then i calculate steps taken by end points to reach that median.
            ==> Thus i need right end of the convex fn rather than left where[l,r] is the range where we have equal values 
            l : when all 4 points overlap (in pairls of 2)
            r : when onlt 2 middle(median) points overlap
            */
            int64_t mid = (low+high)/2;

            if(costFn_Val(mid,X,Y) < costFn_Val(mid+1,X,Y))
                high = mid;
            else
                low = mid +1;
        }

        best = min(best,costFn_Val(low,X,Y));    // to find the least cost in all permutations

    } while (next_permutation(permutaion_arr.begin(),permutaion_arr.end()));

    return best;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int test;
    cin>>test;

    while (test)
    {
        v<int64_t> X(4),Y(4);

        for(int i = 0;i<4;i++)
            cin>>X[i]>>Y[i];
        
        cout<<minStepsToMakeASquare(X,Y)<<endl;
        
        test--;
    }
    
    return 0;
}
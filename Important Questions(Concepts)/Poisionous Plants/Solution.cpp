#include <iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
struct Node 
{
    int plantID; // we label plants from 0 to N - 1
    int daysToDie; // the days a plant needs to die, -1 means it will not die
};
/*
Time : O(N) --> each element is inserted and deleted atmost once ==> thus we have O(2N)
Space: O(N)
*/
int poisonousPlants(vector<int> pesticides) 
{
    int N = pesticides.size();
    stack<Node> s;

    //1st element wont die ever
    s.push({ 0, -1 });
    int maxDaysToDie = -1; // the max days needed to die among all the plants
    
    // for each element we find the timeToDie
    
    for (int i = 1; i < N; i++)
    {
        // we only care about the plants whose pesticide is smaller (potential killer)
        int daysToDie = 1;  //if the 1st element in top of stack is killer,then that one will die on 1st pass only.. no need to check that element die time
                            // we only check die time, if that element needs to die before us.. so  is that element dies after 2 passes, then current element can die only on 3rd pass
        
        while (!s.empty())
        {
            //we keep only the smallest element in stack, cause if curr > some i > i +1 ==> curr > i+1
            // remove all the elements > current from stack
            if (pesticides[s.top().plantID] >= pesticides[i])
            {
                // need to wait the front plants to die, like "1 5 4", 4 will die only after 5 died
                daysToDie = max(daysToDie, s.top().daysToDie + 1);
                s.pop();    
            }
            else // killer found
            {
                break;
            }
        }


        if (s.empty()) // this means no preceding plants have less pesticide than ith plant ==> no one can kill this
        {
            daysToDie = -1;
        }

        //max among all elements
        maxDaysToDie = max(maxDaysToDie, daysToDie);
        
        //push the current element which is smallest or whose killer has been found, and thus that killer can still kill others later on, so we keep that also in stack
        s.push({ i, daysToDie });
    }

    return (maxDaysToDie < 0 ? 0 : maxDaysToDie);
}

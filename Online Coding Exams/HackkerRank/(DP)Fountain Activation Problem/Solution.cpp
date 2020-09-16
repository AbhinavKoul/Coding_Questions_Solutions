#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*

 */

int fountainActivation(vector<int> locations) {
    int n = locations.size();
    vector<int> range(n);
    int count = 1;

    //store max right possible from each index(this index will be left)
    for(int i =1;i<=n;i++)
    {
        int left = max(i-locations[i-1],1);
        int right = max(i+locations[i-1],n);

        range[left - 1] = right; 
    }

    int right = range[0];//TO STORE THE RIGHTMOST LOCATION of fountain which is "ON"
    int curmax = right; //TO STORE MAXIMUM RANGE COVERED TILL NOW
    for(int i = 0;i<n;i++)
    {   
        //update current maximum range till right
        curmax = max(curmax,range[i]);

        // if last fountain has range only uptil this point
        // Ie. if range expired of previous, then only we need another
        if( i == right)
        {
            count++;
            // since we can select the rightmost fountain which is "on" after the range is completed(GREEDY!)
            right = curmax;
        }

    }

    return count;

}

int main()
{
    vector<int> A = {2,0,0,0};
    int res = fountainActivation(A);
    cout<<" HELLO : "<<res;
}
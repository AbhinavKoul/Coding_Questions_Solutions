// Program to find minimum number of platforms
// required on a railway station
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#define v vector

// Returns minimum number of platforms required
int findPlatform(v<int> arrival, v<int> departure, int n)
{
	sort(arrival.begin(), arrival.end());
	sort(departure.begin(),departure.end());

	int comp_needed = 0, res = 0;
	int i = 1, j = 0;

	while (i < n && j < n) 
    {
        
		if (arrival[i] <= departure[j]) {
			comp_needed++;
			i++;
		}
		else if (arrival[i] > departure[j]) {
			comp_needed--;
			j++;
		}

		if (comp_needed > res)
			res = comp_needed;
	}

	return res;
}

// Driver code
int main()
{
	int test;
    cin>>test;

    v<int> arr(test);
    v<int> dep(test);
    
    for(int i = 0;i<test;i++)
    {
        cin>>arr[i]>>dep[i];
    }
    	
    cout<<findPlatform(arr, dep, test);
        
    return 0;
}

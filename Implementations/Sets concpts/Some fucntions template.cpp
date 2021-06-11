
// Sample code to perform I/O:

#include <iostream>
#include<set>
#include<vector>


using namespace std;
#define v vector

int main() {
	set<int> arr = {1,2,4,6};
	set<int> nums = {1,2,6,4};
	// print(arr);
	
	v<int> res;
	set_difference(arr.begin(),arr.end(),nums.begin(),nums.end(),back_inserter(res));
	
	// print(res);
	if(res.empty())
		cout<<"Empty";
	else
		for(auto i : res)
		cout<<i<<" ";
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail


// Write your code here

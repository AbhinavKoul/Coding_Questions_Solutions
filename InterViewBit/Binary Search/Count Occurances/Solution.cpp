#include<iostream>
#include<vector>
using namespace std;


int findCount_MostEfficient(vector<int> arr,int key)
{
    /*
    Time : O(logN) ==>still tell me ==> obviosly something wrong is there
    */
    int low,high,mid;
    int right,left;
    bool found = false;

    // finding rightmost array
    low = 0;
    high = arr.size() - 1;

    while(low<=high)
    {
        mid = (low+high)/2;

        if(arr[mid] == key)
        {
            found = true;
            right = mid;
            low = mid + 1;
        }
        else if(key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    // Finding leftmost part
    low = 0;
    high = arr.size() - 1;

    while(low<=high)
    {
        mid = (low+high)/2;

        if(arr[mid] == key)
        {
            found = true;
            left = mid;
            high = mid - 1;
        }
        else if(key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if(found)
        return(right -left + 1);
    else
        return 0;
    
}

int main()
{
   vector<int> arr =  { 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 7, 7, 8, 8, 8, 8, 9, 9, 10, 10, 10 };
   int key = 1;
   int result = findCount_MostEfficient(arr,key);
   cout<<"answer is : "<< result;
}
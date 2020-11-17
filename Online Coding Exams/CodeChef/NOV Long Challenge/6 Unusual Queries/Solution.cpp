#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define v vector
#define um unordered_map
#define endl "\n"
#define pb push_back
#define mod 4294967296

using namespace std;

// // Binary search (note boundaries in the caller) 
// int CeilIndex(std::vector<int>& v, int l, int r, int key) 
// { 
//     while (r - l > 1) { 
//         int m = l + (r - l) / 2; 
//         if (v[m] >= key) 
//             r = m; 
//         else
//             l = m; 
//     } 
  
//     return r; 
// } 
  
// int LongestIncreasingSubsequenceLength(std::vector<int> v) 
// { 
//     if (v.size() == 0) 
//         return 0; 
  
//     std::vector<int> tail(v.size(), 0); 
//     int length = 1; // always points empty slot in tail 
  
//     tail[0] = v[0]; 
//     for (size_t i = 1; i < v.size(); i++) { 
  
//         // new smallest value 
//         if (v[i] < tail[0]) 
//             tail[0] = v[i]; 
  
//         // v[i] extends largest subsequence 
//         else if (v[i] > tail[length - 1]) 
//             tail[length++] = v[i]; 
  
//         // v[i] will become end candidate of an existing 
//         // subsequence or Throw away larger elements in all 
//         // LIS, to make room for upcoming grater elements 
//         // than v[i] (and also, v[i] would have already 
//         // appeared in one of LIS, identify the location 
//         // and replace it) 
//         else
//             tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i]; 
//     } 
  
//     return length; 
// } 
int LongestIncreasingSubsequenceLength(std::vector<signed int> v)  
{  
    if (v.size() == 0)  
        return 0;  
  
    std::vector<int> tail(v.size(), 0);  
    int length = 1; // always points empty slot in tail  
  
    tail[0] = v[0];  
      
    for (int i = 1; i < v.size(); i++) {  
  
            // Do binary search for the element in  
            // the range from begin to begin + length 
        auto b = tail.begin(), e = tail.begin() + length; 
        auto it = lower_bound(b, e, v[i]);  
              
        // If not present change the tail element to v[i]  
        if (it == tail.begin() + length) 
        tail[length++] = v[i];  
        else   
        *it = v[i];  
    }  
  
    return length;  
}  

template<typename K, typename V>
void print_pair(std::pair<K,V> const &m)
{
	std::cout << "{" << m.first << ": " << m.second << "}\n";
}

template<typename K>
void printVector(vector<K> arr)
{
    cout<<endl;
    for(auto i : arr)
        cout<<i<<" ";
}

pair<signed int,signed int> calcLeftRight(signed int last,signed int x,signed int y,signed int s,signed int N)
{
    signed int left,right;

    left = (x + s*last - 1)%N;
    right = (y + s*last - 1)%N;
    
    if(left > right)
    {
        signed int temp;
        temp = right;
        right = left;
        left = temp;
    }

    return{left,right};
}

template <typename T> 
vector<T> slicing(vector<T> const& v2, 
                  int X, int Y) 
{ 
  
    // Begin and End iterator 
    auto first = v2.begin() + X; 
    auto last = v2.begin() + Y + 1; 
  
    // Copy the element 
    v<T> v1(first, last); 
  
    // Return the results 
    return v1; 
} 

v<int> lis(v<signed int> arr)  
{  
    int n = arr.size();
    v<signed int> lis(n); 
   
    lis[0] = 1;    
  
    /* Compute optimized LIS values in  
       bottom up manner */
    for (int i = 1; i < n; i++ )  
    { 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)  
                lis[i] = lis[j] + 1;  
    } 
  
    // Return maximum value in lis[] 
    return lis; 
}  
int maxSatisfaction(const v<signed int>& DP,signed int left,signed int right)
{
    v<signed int> lis;
    signed int offset = DP[left] - 1,min  = DP[left];
    signed int max = 0;
    for(signed int i = left;i<=right;i++)
    {
        signed int val;
        if(DP[i] < min)
        {
            min = DP[i];
            offset = DP[i] - 1;
        }
        val = DP[i] - offset;
        
        if(val > max)
            max = val;

    }
    return max;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // v<signed int> arr ={7, 8, 8, 9, 10, 10, 2, 3, 5,10};//{0,4,2,3,1,5,5};
    // v<signed int> DP =lis(arr);
    // signed int N = arr.size();
    // signed int S = 1;
    // signed int last = 1;
    // pair<signed int,signed int> range = calcLeftRight(last,5,10,S,N);

    // cout<< " hello :      "<<maxSatisfaction(DP,range.first,range.second);
    
    signed int N,Q,S;
    cin>>N>>Q>>S;
    v<signed int> arr(N);

    for(signed int i =0;i<N;i++)
        cin>>arr[i];

    // v<signed int> DP =lis(arr);
    signed int last = 0;
    while (Q)
    {
        signed int x,y;
        cin>>x>>y;
        pair<signed int,signed int> range = calcLeftRight(last,x,y,S,N);
        last = LongestIncreasingSubsequenceLength(slicing(arr,range.first,range.second));
        cout<<last<<endl; 
        Q--;
    }
    

    return 0;
}

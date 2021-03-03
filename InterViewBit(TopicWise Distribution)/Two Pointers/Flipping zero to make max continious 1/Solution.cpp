#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> maxone(vector <int> &a, int m) {
    
    int n = a.size();
    int currLeft = 0, currRight = 0; //Indexes for the Current Window
    int bestLeft = 0, bestRight = 0; // Indexes for the Best Window
    int count0 = 0;
    vector<int> result;
    
    while(currRight < n){
        
        if(count0 <= m){
            if(a[currRight] == 0) count0++; // Including new zeroes in the window.
            currRight++;
        }
        
        if(count0 > m){
            // Travelling till we find the leftmost zero to discard it from the window
            if(a[currLeft] == 0) count0--;
            currLeft++; 
        }
        // Cuntiniously updating best_right ABD best_left after each updation of curr_tight and left
        if(currRight - currLeft > bestRight - bestLeft){
            bestLeft = currLeft;
            bestRight = currRight;
        }
    }
    
    for(int i = bestLeft; i<bestRight; i++){
        result.push_back(i);    
    }
    return result;
    
}

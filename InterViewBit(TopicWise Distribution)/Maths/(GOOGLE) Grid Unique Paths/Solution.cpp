#include<iostream>
#include<time.h>
#include<vector>
using namespace std;

int uniquePaths_DP(int A, int B) {
    /*
    Time : O(N^2)
    Space: O(N^2)
    */

    vector<vector<int>> path(A,vector<int>(B,0));

    for(int i=0;i<B;i++) 
        path[0][i]=1;
    for(int i=0;i<A;i++) 
        path[i][0]=1;

    for(int i=1;i<A;i++)
    {
        for(int j=1;j<B;j++)
        {
            path[i][j]=path[i-1][j]+path[i][j-1];
        }
    }

    return path[A-1][B-1];
}

int uniquePaths_Recursive(int A, int B) {
    /*
    Time : O(2^N)
    */
    if(A<=0||B<=0)
        return 0;
    if(A==1 && B==1)
        return 1;
        
    return uniquePaths_Recursive(A,B-1) + uniquePaths_Recursive(A-1,B);
}

int main()
{
    clock_t start,end;
    double time;

	start = clock();
    cout<<"Recursive_No of Unique Paths(4,4) : "<<uniquePaths_Recursive(400,400)<<endl;
    end = clock();
    time = (double)(end-start)/CLOCKS_PER_SEC; 
    cout<<"time for above : "<<time<<endl;

    start = clock();
    cout<<"DP_No of Unique Paths(4,4) : "<<uniquePaths_Recursive(400,400)<<endl;
    end = clock();
    time = (double)(end-start)/CLOCKS_PER_SEC; 
    cout<<"time for above : "<<time<<endl;

//     start = clock();
//     cout<<"Recursive_No of Unique Paths(15800,40000) : "<<uniquePaths_Recursive(15800,40000)<<endl;
//     end = clock();
//     time = (double)(end-start)/CLOCKS_PER_SEC; 
//     cout<<"time for above : "<<time<<endl;

//     start = clock();
//     cout<<"DP_No of Unique Paths(15800,40000) : "<<uniquePaths_Recursive(15800,40000)<<endl;
//     end = clock();
//     time = (double)(end-start)/CLOCKS_PER_SEC; 
//     cout<<"time for above : "<<time<<endl;
}

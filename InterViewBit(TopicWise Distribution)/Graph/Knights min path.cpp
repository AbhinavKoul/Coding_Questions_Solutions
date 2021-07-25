// { Driver Code Starts
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;

#define v vector

 // } Driver Code Ends

#define v vector
struct cell
{
    int x, y;
    int dist;
    cell(int a,int b, int c) : x(a),y(b),dist(c) {}
};
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool isValidState(int x,int y, const int &N)
    {
        if(x > N || y>N || x < 1 || y < 1)
            return false;
            
        return true;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    //use bfs since we need to calculate minimum
	    
	    v<int> dx = {-2,-2,-1,-1,1,1,2,2};
	    v<int> dy = {-1,1,-2,2,-2,2,-1,1};
	    
	    v<v<bool>> visited(N+1,v<bool>(N,false));
	    queue<cell> Q;
	    
	    //initiate begin
	    Q.push(cell(KnightPos[0],KnightPos[1],0));
	    visited[KnightPos[0]][KnightPos[1]] = true;
	    
	    while(!Q.empty())
	    {
	        cell k = Q.front(); Q.pop();
	        
	        //reached?
	        if(k.x == TargetPos[0] && k.y == TargetPos[1])
	            return k.dist;
	        
	        // travel all options
	        for(int i = 0;i<8;i++)
	        {
	            int x = k.x + dx[i];
	            int y = k.y + dy[i];
	            
	            if(isValidState(x,y,N) && !visited[x][y])
	            {
	                visited[x][y] = true;
	               // cout<<" x : "<<x<<" y : "<<y<<" dist : "<<k.dist+1<<"\n";
	                Q.push(cell(x,y,k.dist + 1));
	            }
	        }
	    }
	    
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends

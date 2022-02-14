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
string solve(int x, int y, int n, int r, vector<int> &X, vector<int> &Y) {
    v<v<bool>> visited(x+1,v<bool>(y+1,false));
    updateVisitedDueToCircles(visited,n,r,X,Y);
    
    if(isPathExist(visited,x,y))
        return "YES";
        
    return "NO";
}

void updateVisitedDueToCircles(v<v<bool>> &visited,const int& n,const int&r,const v<int>& X,const v<int>& Y)
{
    for(int i = 0;i<visited.size();i++)
    {
        for(int j = 0;j<visited[0].size();j++)
        {
            for(int k = 0;k<n;k++)
            {
                int a = X[k] - i;
                int b = Y[k] - j;
                
                if(a*a + b*b <= r*r)
                    visited[i][j] = true;
            }
        }
    }
}
bool limit(int &i,int &j, const int &x,const int &y)
{
    if(i < 0 || j < 0 || i > x || j > y)
        return false;
        
    return true;
}
bool isPathExist(v<v<bool>> &visited, const int& x,const int& y)
{
    v<int> dx = {-1,-1,-1,0,0,1,1,1};
    v<int> dy = {-1,0,1,-1,1,-1,0,1};
    queue<pair<int,int>> Q;
    Q.push(make_pair(0,0));
    if(visited[0][0])
        return false;
        
    while(!Q.empty())
    {
        pair<int,int> temp = Q.front(); Q.pop();
        visited[temp.first][temp.second] = true;
        
        if(temp.first == x && temp.second == y)
            return true;
        for(int i = 0;i<8;i++)
        {
            int x1 = temp.first + dx[i];
            int y1 = temp.second + dy[i];
            
            if(limit(x1,y1,x,y) && !visited[x1][y1])
                Q.push(make_pair(x1,y1));
                
        }
    }
    return false;
}

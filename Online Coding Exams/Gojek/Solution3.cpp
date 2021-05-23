#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
#include<set>
#define fileopen freopen("input.in", "r", stdin);
#define fileclose freopen("out.txt", "w+", stdout);
#define Fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define v vector
#define um unordered_map
#define mod 1000000007
using namespace std;
void findAndContest(const v<v<char>> &grid,v<v<bool>> &visited,set<char>& tempFraction,int row, int col,int x, int y)
{
    if(x<0 || x>=row)
        return;
    if(y<0 || y>=col)
        return;

    if(!visited[x][y])
    {
        visited[x][y] = true;

        if(grid[x][y] == '#')
            return;
        if(!(grid[x][y] == '.'))
            tempFraction.insert(grid[x][y]);

        findAndContest(grid,visited,tempFraction,row,col,x,y+1); // move direction right
        findAndContest(grid,visited,tempFraction,row,col,x,y-1); // move direction left
        findAndContest(grid,visited,tempFraction,row,col,x+1,y); // move direction up
        findAndContest(grid,visited,tempFraction,row,col,x-1,y); // move direction down
    }

}
int main()
{
    Fio;
    fileopen
    fileclose
    int test;
    cin>>test;
    
    for(int i = 1;i<= test;i++)
    {
        signed int m,n;
        cin>>m;
        cin>>n;

        v<v<char>> grid(m,v<char>(n));

        for(int a = 0;a<m;a++)
            for(int b = 0;b<n;b++)
                cin>>grid[a][b];      


        v<v<bool>> visited(m,v<bool>(n,false));
        int conquer = 0;
        map<char,int> fraction;
        for(int j = 0;j<m;j++)
        {
            for(int k = 0;k<n;k++)
            {
                set<char> tempFractions;

                findAndContest(grid,visited,tempFractions,m,n,j,k);

                if(tempFractions.size() == 1)
                {
                    for(auto val : tempFractions)
                    {
                        if(fraction.find(val) == fraction.end())
                            fraction[val] = 1;
                        else
                            fraction[val]++;
                    }
                }
                else if(tempFractions.size() > 1)
                    conquer++;
            }
        }

        cout<<"Case "<<i<<":";
        for(auto i : fraction)
        {
            cout<<"\n"<<i.first<<" "<<i.second;
        }
        cout<<"\ncontested "<<conquer;
        cout<<endl;
    }

    return 0;
}
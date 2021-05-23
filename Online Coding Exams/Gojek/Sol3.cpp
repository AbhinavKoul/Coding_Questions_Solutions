#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#include<set>
#define fileopen freopen("input.in", "r", stdin);
#define fileclose freopen("out.txt", "w+", stdout);
#define Fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define v vector
#define um unordered_map
#define mod 1000000007
using namespace std;

void findAndContest(v<v<char>> &maps,v<v<bool>> &visited,set<char> tempFraction,int row, int col,int x, int y)
{       
    //Map< String,Integer> fractions
    if(x < 0 || x >= row)
    { // make sure not not exceed the limit
        return;
    }
    if(y < 0 || y >= col){ // make sure not not exceed the limit
        return;
    }
    if(visited[x][y]){ // ignore it when already visited
        return;
    }

    visited[x][y] = true; // set true when the maps is already visited
    
    if(maps[x][y] == '#'){ // ignore #
        return;
    }
    
    if(!(maps[x][y] == '.')){ // add fraction to the Set tempFraction
        tempFraction.insert(maps[x][y]);
    }

    findAndContest(maps,visited,tempFraction,row,col,x,y+1); // move direction right
    findAndContest(maps,visited,tempFraction,row,col,x,y-1); // move direction left
    findAndContest(maps,visited,tempFraction,row,col,x+1,y); // move direction up
    findAndContest(maps,visited,tempFraction,row,col,x-1,y); // move direction down
    return;
}

int main()
{
    Fio;
    fileopen
    fileclose
    int test;
    cin>>test;

    for (int i = 1; i <=test; i++) 
    {
        int row,col;


        v<v<char>> maps(row,v<char>(col)); // map the input string to 2d array
        v<v<bool>> visited(row,v<bool>(col,false)); // array to store if the node is already visited

        
        unordered_map<char,int> fractions; // using tree map to store fraction by alpahbetical order

        for (int i = 0; i < row; i++) 
            for(int j =0;j<col;j++)
                cin>>maps[i][j];


        int Conquer = 0;
        for (int j = 0; j < row; j++) 
        {
            for (int k = 0; k < col; k++) 
            {
                set<char> tempFractions;
                
                findAndContest(maps,visited,tempFractions,row,col,j,k);
                if(tempFractions.size() > 1)
                { // if set fraction > 1 there's a contest
                    Conquer++;
                }
                else{ // if set = 1 then store value in set(tempfraction) to fraction
                    for(auto frac : tempFractions)
                    {
                        if(fractions.find(frac) != fractions.end()){
                            fractions[frac] = fractions[frac]+1;
                        }else{
                            fractions[frac] = 1;
                        }
                    }
                }
            }
        }
        
        cout<<"Case "<<i<<":";

        for(auto i : fractions) {
            char key = i.first;
            int val = i.second;

            cout<<key<<" "<<val;
        }
        cout<<"contested "<<Conquer;
    }
    return 0;
}
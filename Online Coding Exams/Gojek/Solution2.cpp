#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define fileopen freopen("input.in", "r", stdin);
#define fileclose freopen("out.txt", "w+", stdout);
#define Fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define v vector
#define um unordered_map
#define mod 1000000007
using namespace std;

bool word_formed_dir(v<v<char>> &grid,string word,int index,int i,int j,int dir,int m, int n)
{
    // For searching in all 8 direction
    v<int> x = {-1, -1, -1,  0, 0,  1, 1, 1 };
    v<int> y = {-1,  0,  1, -1, 1, -1, 0, 1 };


    if(grid[i][j] != word[index])
        return false;
    else if(index == word.length() - 1)//last letter
        return true;
    else
    {
        int rd = i + x[dir];
        int cd = j + y[dir];
        if (rd >= m || rd < 0 || cd >= n || cd < 0)
                return false;

        return word_formed_dir(grid,word,index + 1,rd,cd,dir,m,n);
    }

    return false;


}
int res(v<v<char>> &grid, string word,int m,int n)
{
    int cnt = 0;

    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            for(int k = 0;k<8;k++)
            {
                if(word_formed_dir(grid,word,0,i,j,k,m,n))
                    cnt++;
            }
        }       
    }
    return cnt;
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

        string word;
        cin>>word;

        int cnt = res(grid,word,m,n);
        cout<<"Case "<<i<<": "<< cnt;
        cout<<endl;
    }

    return 0;
}
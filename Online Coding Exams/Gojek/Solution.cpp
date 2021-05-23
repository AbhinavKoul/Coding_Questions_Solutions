// C++ programs to search a word in a 2D grid
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
// #define fileopen freopen("input.in", "r", stdin);
// #define fileclose freopen("out.txt", "w+", stdout);
#define Fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define v vector
#define um unordered_map
#define mod 1000000007
using namespace std;
int cnt;
// For searching in all 8 direction
int x[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
int y[] = { -1,  0,  1, -1, 1, -1, 0, 1 };
 
// This function searches in
// all 8-direction from point
// (row, col) in grid[][]
bool search2D(char *grid, int row, int col,
               string word, int R, int C)
{
    // If first character of word doesn't
    // match with given starting point in grid.
    if (*(grid+row*C+col) != word[0])
        return false;
 
    int len = word.length();
 
    // Search word in all 8 directions
    // starting from (row, col)
    for (int dir = 0; dir < 8; dir++) {
        // Initialize starting point
        // for current direction
        int k, rd = row + x[dir], cd = col + y[dir];
 
        // First character is already checked,
        // match remaining characters
        for (k = 1; k < len; k++) {
            // If out of bound break
            if (rd >= R || rd < 0 || cd >= C || cd < 0)
                break;
 
            // If not matched,  break
            if (*(grid+rd*C+cd) != word[k])
                break;
 
            // Moving in particular direction
            rd += x[dir], cd += y[dir];
        }
 
        if(k == len)
            cnt++;
    }
    return true;
}
 
// Searches given word in a given
// matrix in all 8 directions
void patternSearch(char *grid, string word,
                  int R, int C)
{
    // Consider every point as starting
    // point and search given word
    for (int row = 0; row < R; row++)
        for (int col = 0; col < C; col++)
            if (search2D(grid, row, col, word, R, C))
                cout << "pattern found at "
                     << row << ", "
                     << col << endl;
}
 
// Driver program
int main()
{
      int R = 3, C = 4;
    char grid[3][5] = { "catt",
                        "aata",
                        "tatc" };
    cnt = 0;
    patternSearch((char *)grid, "cat", R, C);

    cout<<" "<<cnt;
    return 0;
}
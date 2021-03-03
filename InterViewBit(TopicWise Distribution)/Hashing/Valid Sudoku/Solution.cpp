#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define v vector

using namespace std;
// 24ms
class Solution {
public:
    
    bool isUnique(v<char> &arr)
    {
        unordered_map<char,int> map;
        for(auto i : arr)
        {
            if(i == '.')
                continue;
            map[i]++;
            if(map[i] >= 2)
                return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        //rows
        for(int i = 0;i<9;i++)
        {
            if(!isUnique(board[i]))
                return false;
        }
        //cols
        
        for(int i =0;i<9;i++)
        {
            v<char> col;
            for(int j = 0;j<9;j++)                  //selecting all elements in that particular column
                col.push_back(board[j][i]);
            
            if(!isUnique(col))
                return false;
        }
        
        //boxes
        for(int i =0;i<9;i+=3)
        {
            for(int j = 0;j<9;j+=3)
            {
                v<char> box;
                for(int k = i;k<i+3;k++)            //entering box elements
                    for(int m = j;m<j+3;m++)
                        box.push_back(board[k][m]);
                
                if(!isUnique(box))
                    return false;
            }
        }
        return true;
    }
};
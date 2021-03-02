//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define v vector

using namespace std;
/*
This question is similar to graph colouring problem where
Colours = m =  9
edges = V = 9*9

Time Complexity = O(V^M)    //since checking all possibilities
*/
bool isValid(vector<vector<char>> &A, int row, int col, char t){
    // if present in the same row
    for(int j=0; j<9; j++){
        if(A[row][j]==t) return false;
    }    

    // if present in same col
    for(int i=0; i<9; i++){
        if(A[i][col]==t) return false;
    }

    // if present in same block

    //find initial index by lower bound int division and then multiply by facfe value(ie 3)     O(n2)
    int rowB=(row/3)*3;
    int colB=(col/3)*3;
    for(int i=rowB; i<rowB+3; i++){
        for(int j=colB; j<colB+3; j++){
            if(A[i][j]==t) return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>> &A, int row, int col){
    if(row==9) return true;
    if(col==9) return solve(A, row+1, 0);   //since we are changing values rowwise rather than colwise
    if(A[row][col]!='.') return solve(A, row, col+1);   //we are keeping row same and udate col 1st and thus going rowwise

    //check which value will work one by one

    for(int i=1; i<=9; i++){
        char t = '0'+i;
        if(isValid(A, row, col, t)){    //check if value can work in existing scenario
            A[row][col]=t;
            if(solve(A, row, col+1)) 
                return true;   //check if uppdating this value lead to a solution for all othr spaces or not
            else 
                A[row][col]='.'; // if no solution, then undo what you did
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>> &A) {
    bool t = solve(A, 0, 0);
}
#include<iostream>
#include<vector>
using namespace std;
// ---------------------------------------------- BIT VECTOR IMPLEMENTATION --------------------------------------------
// HELPER FNS
/*
returns true if the bit is set at that index else false
Time : O(1)
Space: O(1) == can be made zero if we check additional var mask(just added for readability)
*/
int is_bit_set(int bitVector,int index)
{
    int mask = 1<<index;
    if((bitVector & mask) == 0)
        return 0;
    else
        return 1;
    
}
/*
updates the bit from 0 to 1 only. doesnt change bit if it is already 1.
Time : O(1)
SPACE: O(1)
use by reference to elimate copying overheads
*/
void bit_update(int &bitVector,int index)
{

    int mask = 1<<index;
    bitVector |= mask;
}
/*
Time : O(R*C)
Space: O(1)
max size allowed of R and C is dependent on int size ie 4bytes(8*4 bits) == 32*32.
*/
void setZeroes_BITVECTOR(vector<vector<int>> &A)
{
    int R = A.size(),C = A[0].size();
    //bitVectors
    static int row,col;

    // transverse entire input 2d vector and update bitvectors accordingly
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(A[i][j] == 0)
            {
                bit_update(row,i);
                bit_update(col,j);
            }
        }
    }

    //change 2d vector in place so as to save space
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            if(is_bit_set(row,i)||is_bit_set(col,j))
                A[i][j] = 0;
    
    cout<<row<<" "<< col;

}
// ----------------------------------------------- Array implementation -------------------------------------------------

/*
    TIME: O(R*C)
    SPACE: O(R+C) 
*/
void setZeroes(vector<vector<int> > &A) {

    // get size of 2d array
    int R=A.size();
    int C=A[0].size();
    // make row and col vector to tell which col and row has to be made zero
    vector<int> row(R,0);
    vector<int> col(C,0);
    //traverse through complete 2d array and find which rows and col has to be made 0
    for(int i=0;i<R;i++)            // O(R*C)
    {
        for(int j=0;j<C;j++)
            if(A[i][j]==0)
            {
                row[i]=1;
                col[j]=1;
            }
    }
    //change 2d array inplace as per the row and col to save space
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
            if(row[i]||col[j])
            {
                A[i][j]=0;
            }
    }
    return;
}

/*
Prints a 2d vector
*/
void print_2D_Vector(vector<vector<int>> &arr)
{
    for(auto i : arr)
    {
        cout<<endl;
        for(auto val :i)
            cout<<val<<" ";
        
    }
}
int main()
{
    vector<vector<int>> A = {
                    {1,0,1},
                    {1,1,1},
                    {1,1,1}
    };

    vector<vector<int>> B = {
                    {1,0,1},
                    {1,1,1},
                    {0,1,1}
    };

    // setZeroes_BITVECTOR(A);
    setZeroes_BITVECTOR(B);

    print_2D_Vector(B);
    
}

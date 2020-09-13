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
Toggle the ith bit in the bitvector
*/
void toggle_bit(int &bitVector,int index)
{
    if(index<0)
        return;
    
    int mask = 1 << index;
    if((bitVector & mask) == 0)
        bitVector |= mask;
    else
        bitVector &= ~mask;
    
    return;
}

bool checkExactlyOneBitSet(int bitVector)
{
    /*
    eg. bitV = 001000 ==> bitV - 1 = 000111 {these 2 doesnt overlap} thus anding them will return 0
        bitV = 00101000 ==> bitV - 1 = 00100111 {here they overlap}   */
    return ((bitVector & (bitVector - 1)) == 0) ;
}
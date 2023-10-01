#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'game_value' function below.
#
# The function is expected to return a DOUBLE.
# The function accepts INTEGER deck_size as parameter.
# deck_size is an even non-negative integer
#
# RED  : +1 
# GREEN: -1
#recursive fn telling how many red or green cards we have left in deck till now and total deck_size
# value = 0
def func(deck_size,red,green,dp):
    #base conditions
    if dp[red][green] != None:
        return dp[red][green]
    
    # 1 card left?
    #if red left in deck, then we need to draw that as curVal = -1, else we would have +1 value
    if  red == 1 and green == 0:
        # dp[red][green] = 0;
        # return dp[red][green]
        return 0;
    elif green == 1 and red == 0:
        # dp[red][green] = 1;
        # return dp[red][green]
        return 1;
        
    # 0 card left for Red or Green
    # 
    if green == 0 and red != 0:
        # dp[red][green] = 0;
        # return dp[red][green]
        return 0;
    elif red == 0 and green != 0:
        # dp[red][green] = green;
        # return dp[red][green]
        return green;

    
    # 1 of each
    if red == 1 and green == 1:
        # dp[red][green] = 0.5; 
        # return dp[red][green]
        return 0.5;
        
    prob_red = red/(red + green)
    prob_green = green/(red + green)
    
    # expected_red_value = prob_red * func(deck_size, red - 1, green,dp)
    # expected_green_value = prob_green * func(deck_size,red,green-1,dp)
    expected_red_value = prob_red * func(deck_size, red - 1, green,dp)
    expected_green_value = prob_green * func(deck_size,red,green-1,dp)
    expected_value_if_i_keep_playing = expected_red_value +  expected_green_value
    
    dp[red][green] = max(green - red,expected_value_if_i_keep_playing)
    return dp[red][green]
    # print("red:",red,"green:",green,max(green - red,expected_value_if_i_keep_playing))
    # dp[red][green] = max(green - red,expected_value_if_i_keep_playing)

    # return max(green - red,expected_value_if_i_keep_playing)
    
    
    
    

def game_value(deck_size):
    # Write your code here
    val = int(deck_size/2);
    n = val + 1 
    dp = [[None]*n]*n
    print(dp)
    return func(deck_size,val,val,dp);

print(game_value(8))
# print(game_value(30))
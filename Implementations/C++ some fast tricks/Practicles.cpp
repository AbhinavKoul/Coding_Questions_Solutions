#include<vector>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define v vector

v<int> res;
//erasing by element value

/*
1. find fn returns an iterator for that element position
2. erase uses that iterator to delete
*/
res.erase(find(res.begin(),res.end(),1));


/*
1. Iterator declaration
2. find
3. distance        format ->  [first element itr, itr)
*/
v<bool>::iterator itr = find(is_present.begin()+1,is_present.end(),false);
        
        if(itr == is_present.end())
            return is_present.size();
        else
            return(abs(distance(itr,is_present.begin())));
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
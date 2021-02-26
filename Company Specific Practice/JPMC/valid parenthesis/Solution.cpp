#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_map>
#include<stack>
#define v vector
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        set<char> a = {'(','{','['};
        unordered_map <char,char> um = {
            {'(',')'},
            {'{' , '}'},
            {'[' , ']'}
        };
        stack<char> st;
        for(auto i:s)
        {
            auto it = um.find(i);
            if(it != a.end())
            {
                st.push(i);
            }
            else
            {
                if(!st.empty())
                {
                    char br = st.top();
                    if(i != um[br])
                        return false;
                    st.pop();
                }
                else
                    return false;
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};
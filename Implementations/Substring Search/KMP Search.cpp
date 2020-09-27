#include<iostream>
#include<vector>
#include<string>
using namespace std;

void computeLPS(string substr,vector<int> &lps)
{
    /*
    LPS Array : lps indicates longest proper prefix which is also suffix.
    lps is passed as reference thus we dont return
    */
    int len = 0;
    lps[0] = 0;
    int i = 1;
    int n = substr.size();
    while(i<n)
    {
        if(substr[i] == substr[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                //update len ptr to check for previous hits
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> KMPSearch(const string txt, const string pat) {
    /*
    returns a list of index where the substr is found
    WORST CASE : O(N)

    */
    int m = pat.size();
    int n = txt.size();
    vector<int> res;
    vector<int> lps(m,0);
    
    computeLPS(pat,lps);
    int i=0,j=0;
    
    while(i<n)
    {
        if(pat[j] == txt[i])
        {
            // slide the window towards right
            i++;
            j++;
        }
        if(j == m)
        {
            res.push_back(i-j);
            //update j index to check from last possible location
            j = lps[j - 1];
        }
        else if((i<n) && (pat[j]!=txt[i]))
        {
            if(j!=0)
                j = lps[j - 1]; //update j index to check from last possible location
            else
                i++;    //cant decrement more ==> so not in substr ==> thus slide string window
        }
    }
    
    if(res.size())
        return res;
    else
        return {-1};
}

int main()
{
    string str = "bbbbbbbbab";
    string substr = "baba";
    cout<<"HELLO :  "<<endl;
    for(int i :KMPSearch(str,substr))
        if(i == -1)
            cout<<"coudnt find in string";
        else
            cout<<i<<" ";
        
}
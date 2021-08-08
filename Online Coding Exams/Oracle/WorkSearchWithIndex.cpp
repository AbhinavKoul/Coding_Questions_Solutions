#include<iostream>
#include<vector>

#define v vector
using namespace std;
string str;
string a[1000+10];  //2D --> IMP
vector<int> ans;    //contains all my indexes which contributed to the word match!
bool solve(int n,int idx,int i,int j,v<v<bool>> &flag)
{
    //base conditions
    if(idx==str.size())
        return true;
    if(a[i][j]!=str[idx])   // if not equal to the index we want --> directly false here
        return false;
        
    //normal true condition
    flag[i][j]=true;
    ans.push_back(i);
    ans.push_back(j);
    bool ff=false;
    //check all directions now
    if(i-1>=0 && !flag[i-1][j])
    {
        ff = solve(n,idx+1,i-1,j,flag);
        if(ff)
            return true;
    }
    if(i+1<n && !flag[i+1][j])
    {
        ff=solve(n,idx+1,i+1,j,flag);
        if(ff)
            return true;
    }
    if(j-1>=0 && !flag[i][j-1])
    {
        ff=solve(n,idx+1,i,j-1,flag);
        if(ff)
            return true;
    }
    if(j+1<n && !flag[i][j+1])
    {
        ff=solve(n,idx+1,i,j+1,flag);
        if(ff)
            return true;
    }

    //revert back
    flag[i][j]=false;
    ans.pop_back();     //we do pop 2 times because we need to remove both x and y coordinates
    ans.pop_back();
    return false;
}
int main() {
    int n;
    cin>>n;
    cin>>str;
    for(int i=0;i<n;i++)    //your grid (smart way)
    {
        cin>>a[i];
    }

    v<v<bool>> flag(n,v<bool>(n,false));
    
    bool ff = false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ff=solve(n,0,i,j,flag);
            if(ff)
                break;
        }
        if(ff)
          break;
   }
    if(ff)
    {
        cout<<"yes ";
               for(auto i:ans)
               {
                   cout<<(i+1); //cause answer needed in 1 based indexing
               }
           }
           else
           {
               cout<<"no";
           }
	return 0;
}
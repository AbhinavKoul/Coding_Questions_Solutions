
class Solution {
public:
    std:: vector<vector<int>> fin;
    void dfs(map<int,vector<int>>& dict,int p,int n,vector<int>& ans){
        if (p==n)
        {
            fin.push_back(ans);
            return;
        }
        auto itr=dict.find(p);
        for(int i=0;i<itr->second.size();i++){
            int x=itr->second[i];
            ans.push_back(x);
            dfs(dict,x,n,ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int i,n,p;
        vector<int>ans;
        n=graph.size();
        map<int,vector<int>> dict;
        for (i=0;i<n;i++){
            dict.insert({i,graph[i]});
        }
        ans.push_back(0);
        dfs(dict,0,n-1,ans);
        return fin;
    }
};
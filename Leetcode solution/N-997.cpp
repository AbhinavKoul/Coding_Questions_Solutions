class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int i,j,flag=0;
        map<int,vector<int>> dict,dict1;
        vector<int>demo;
        for (i=0;i<N;i++){
            demo.push_back(0);
            dict.insert({i+1,demo});
            dict1.insert({i+1,demo});
            demo.clear();
        }
        for (i=0;i<trust.size();i++){
            auto itr=dict.find(trust[i][0]);
            itr->second.push_back(trust[i][1]);
            itr=dict1.find(trust[i][1]);
            itr->second.push_back(trust[i][0]);
        }
        demo.clear();
        demo.push_back(0);
        for(auto itr:dict){
            if (itr.second==demo){
                auto itr1= dict1.find(itr.first);
                if(itr1->second.size()==N){
                    return itr.first;
                }
            }
        }
        return -1;
    }
};
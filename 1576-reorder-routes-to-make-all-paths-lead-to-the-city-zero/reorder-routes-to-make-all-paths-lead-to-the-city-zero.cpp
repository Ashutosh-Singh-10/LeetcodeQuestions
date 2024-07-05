class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> gr(n);
        int ans=0;
        for(auto &i:connections)
        {
            gr[i[0]].push_back({i[1],1});
            gr[i[1]].push_back({i[0],0});
        }
        function<void(int,int)>   dfs=[&](int cur,int prev)
        {
            for(auto &i:gr[cur])
            {
                if(i.first!=prev)
                {
                    ans+=i.second;
                    dfs(i.first,cur);
                }
            }


        };
        dfs(0,-1);
        return ans;

        
    }
};
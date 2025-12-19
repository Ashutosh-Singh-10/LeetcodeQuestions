class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& vec, int f) {

        vector<vector<pair<int,int>>> gr(n);
        for(auto &i:vec)
        {
            gr[i[0]].push_back({i[1],i[2]});
            gr[i[1]].push_back({i[0],i[2]});
        }
        vector<int> vis(n,INT_MAX);   
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qu;
        qu.push({0,0});
        qu.push({0,f});
        while(qu.size())
        {
            auto [a,b]=qu.top();
            qu.pop();
            if(vis[b]!=INT_MAX)
            {
                continue;
            }
            vis[b]=a;
            for(auto [i,j]:gr[b])
            {
                if(j>=a)
                {
                    qu.push({j,i});
                }
                

            }
 
            
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=INT_MAX)
            {
                ans.push_back(i);
            }

        }
        return ans;





        return  {};

        
    }
};
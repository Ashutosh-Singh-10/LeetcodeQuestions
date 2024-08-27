class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        priority_queue<pair<double,int>> p;

        p.push({1,start});
        vector<vector<pair<int,double>>> vec(n,vector<pair<int,double>>(0,{0,0}));
        for(int i=0;i<edges.size();i++)
        {
            vec[edges[i][0]].push_back({edges[i][1],succProb[i]});
            vec[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<int> visited(n,0);
        int ed;double prob;
        while(p.size())
        {
            prob=p.top().first;
            ed=p.top().second;
            p.pop();
            if(ed==end)
            {
                return prob;
            }
            if(visited[ed]==1)
            {
                continue;
            }
            visited[ed]=1;
            for(auto &i:vec[ed])
            {
                if(visited[i.first]==0)
                {
                    p.push({prob*i.second,i.first});
                }
            }

        }
        return 0;


        
        
    }
};
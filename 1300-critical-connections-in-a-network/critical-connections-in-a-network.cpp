
vector<int> tin,low;
int bridgeDfs(vector<vector<int>> &gr,int cur,int prev,int tm,    set<pair<int,int>> &bridges)
{
    if(tin[cur]!=-1) 
    {
        low[prev]=min(low[prev],low[cur]);
        return 0;
    }
    tin[cur]=tm;
    low[cur]=tm;
    for(auto &nxt:gr[cur])
    {
        if(nxt!=prev)
        {
            if(bridgeDfs(gr,nxt,cur,tm+1,bridges))
            {
                bridges.insert({cur,nxt});
            }
        }
    }
    low[prev]=min(low[prev],low[cur]);
    if(tin[cur]==low[cur]) return 1;
    return 0;
}
void bridgeFind(vector<vector<int>> &gr,int n,vector<vector<int>> &ans)
{
    tin.clear();
    low.clear();
    tin.resize(n,-1);
    low.resize(n,-1);
    set<pair<int,int>> bridges;
    bridgeDfs(gr,0,0,0,bridges);
    for(auto &[a,b]:bridges)
    {
        ans.push_back({a,b});
        // cout<<a<<" "<<b<<endl;
    }
}
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>gr(n);
        for(auto &i:connections) 
        {
            gr[i[0]].push_back(i[1]);
            gr[i[1]].push_back(i[0]);
        }
        vector<vector<int>> ans;
        bridgeFind(gr,n,ans);
        return ans;
        
    }
};
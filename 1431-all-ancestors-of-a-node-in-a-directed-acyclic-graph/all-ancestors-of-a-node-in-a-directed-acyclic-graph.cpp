void dfs(vector<vector<int>>& gr,int cur,int parent,vector<set<int>> & ans,vector<int> &vis)
{
    if(vis[cur]==parent) return ;
    vis[cur]=parent;
    if(cur!=parent)    
    ans[cur].insert(parent);
    for(auto &i:gr[cur])dfs(gr,i,parent,ans,vis);
}
class Solution {
public:
vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) 
{
    vector<int> vis(n,-1);   
    vector<vector<int>> gr(n),fin(n);
    vector<set<int>> ans(n);
    for(auto &i:edges)
        gr[i[0]].push_back(i[1]);
    for(int i=0;i<n;i++)
        dfs(gr,i,i,ans,vis);
    for(int i=0;i<n;i++)
    {
        for(auto &j:ans[i])
        {
            fin[i].push_back(j);
        }
        
    }
    
    return fin;
    }
};
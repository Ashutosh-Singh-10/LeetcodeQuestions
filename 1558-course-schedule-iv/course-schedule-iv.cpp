class Solution {
public:
    void dfs(int cur,vector<vector<int>> & gr,vector<vector<int>>& adj,int node)
    {
        if(gr[node][cur]==1) return;
        gr[node][cur]=1;
        for(auto &i:adj[cur])
        {
            dfs(i,gr,adj,node);
        }
        
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& preq, vector<vector<int>>& queries) {
        vector<vector<int>> gr(n,vector<int>(n,0));
        vector<vector<int>> adj(n);
        for(auto &i:preq)
        {
            adj[i[0]].push_back(i[1]);
        }
        for(int i=0;i<n;i++) 
        {
            dfs(i,gr,adj,i);
        }
        int m=queries.size();
        vector<bool> ans(m);
        for(int i=0;i<m;i++)
        {
            ans[i]=gr[queries[i][0]][queries[i][1]];
        }
        return ans;



        

        
    }
};
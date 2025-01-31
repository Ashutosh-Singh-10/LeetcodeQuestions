class Solution {
public:
    int n;
    int dfs(vector<vector<int>> & vis,int idx,int x,int y,vector<vector<int>> &grid)
    {
        if(x>=n || y>=n || x<0 || y<0) return 0 ;
        if(grid[x][y]==0) return 0;
        if(vis[x][y]!=0) return 0;
        vis[x][y]=idx;
        vector<int> dx={1,0,-1,0};
        vector<int> dy={0,1,0,-1};
        int ret=1;
        for(int i=0;i<4;i++)
        {
            ret+=dfs(vis,idx,x+dx[i],y+dy[i],grid);
        }
        return ret;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        int idx=1,ans=0;
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    mp[idx]=dfs(vis,idx,i,j,grid);
                    ans=max(ans,mp[idx]);
                }
                idx++;
                
            }
        } 
   
        vector<int> dx={1,0,-1,0};
        vector<int> dy={0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) continue;
                set<int> st;
                for(int k=0;k<4;k++)
                {
                    int x=dx[k]+i,y=dy[k]+j;
                    if(x>=n || y>=n || y<0 || x<0 || grid[x][y]==0) continue;
                    st.insert(vis[x][y]);
                }
                int cnt=1;
                for(auto &k:st)
                {
                    cnt+=mp[k];
                }
                ans=max(ans,cnt);
                
            }
        }
        return ans;
        
    }
};
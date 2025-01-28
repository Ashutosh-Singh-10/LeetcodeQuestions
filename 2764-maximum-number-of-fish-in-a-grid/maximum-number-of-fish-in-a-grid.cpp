class Solution {
public:
    int dfs(vector<vector<int>> & grid,int x,int y,int n,int m)
    {
        if(x>=n || x<0 || y>=m || y<0) return 0;
        if(grid[x][y]>0)
        {
            int ret=grid[x][y];
            grid[x][y]=0;
            vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
            for(auto &i:dir) 
            {
                ret+=dfs(grid,x+i[0],y+i[1],n,m);
            }
            return ret;

        }
        else return 0;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0,n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=max(dfs(grid,i,j,n,m),ans);
            }
        }
        return ans;
        
    }
};
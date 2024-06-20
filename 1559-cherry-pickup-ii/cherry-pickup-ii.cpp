class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>( m,0) ));
        vector<vector<vector<int>>> vis(n,vector<vector<int>>(m,vector<int>( m,0) ));
        dp[0][0][m-1]=grid[0][0]+grid[0][m-1];
        vis[0][0][m-1]=1;
        vector<int> dir={-1,0,1};
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=j;k<m;k++)
                {
                    for(auto &l:dir)
                    {
                        for(auto &o:dir)
                        {
                            if(j+l<o+k  && o+k<m && l+j>=0 && vis[i][j][k])
                            {
                                dp[i+1][j+l][k+o]=max(dp[i+1][j+l][k+o],dp[i][j][k]+grid[i+1][j+l]+grid[i+1][k+o]);
                                vis[i+1][j+l][k+o]=1;
                            }
                            if(j+l==o+k  && o+k<m && l+j>=0 && vis[i][j][k]  )
                            {
                                dp[i+1][j+l][k+o]=max(dp[i+1][j+l][k+o],dp[i][j][k]+grid[i+1][j+l]);
                                vis[i+1][j+l][k+o]=1;
                            }
                        }
                    }

                }
            }
        }
        int ans=0;
        for(auto &i:dp[n-1])
        {
            for(auto &j:i)
            {
                ans=max(ans,j);

            }
        }
        return ans;

        
    }
};
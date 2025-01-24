class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> a(n),b(m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) 
                {
                    a[i]++;b[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++) 
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && (a[i]>1 || b[j]>1)) ans++;
            }
        }
        return ans;
    }
};
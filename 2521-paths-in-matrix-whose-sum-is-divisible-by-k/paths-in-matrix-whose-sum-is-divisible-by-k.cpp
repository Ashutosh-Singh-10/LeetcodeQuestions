class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        int mod=1e9+7;
        vector<vector<vector<int>>> vec
        (n+1,vector<vector<int>>(m+1,vector<int>(50,0)) );
        vec[0][1][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int el=grid[i-1][j-1];
                for(int l=0;l<k;l++){
                    vec[i][j][(l+el)%k]=(vec[i-1][j][l]+vec[i][j-1][l])%mod;
                    

                }
            }
        }
        return vec[n][m][0];
        
    }
};
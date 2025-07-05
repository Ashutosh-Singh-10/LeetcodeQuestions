class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<long long>> vec(m+1,vector<long long> (n+1,1e18));
        vec[1][0]=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                
                long long wt=waitCost[i-1][j-1];
                long long ct=i*j;
                vec[i][j]=min(vec[i-1][j],vec[i][j-1])+ct+wt;
             
            }
        }
        
        return vec[m][n]-waitCost[0][0]-waitCost[m-1][n-1];
        
    }
};
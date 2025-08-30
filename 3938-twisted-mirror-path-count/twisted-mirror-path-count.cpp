long long mod=1e9+7;
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(2,0)));
        // 0 mean upar se aaya h 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int el=grid[i][j];
                if(i==0 && j==0)
                {
                    dp[i][j][0]=dp[i][j][1]=1;
                }
                else if(i==0)
                {
                    if(grid[i][j-1]==0)
                    {
                        dp[i][j][1]=dp[i][j-1][1];
                    }
                }
                else if(j==0){
                    if(grid[i-1][j]==0) dp[i][j][0]=dp[i-1][j][0];
                }
                else 
                {
                    int a=dp[i-1][j][1];
                    int b=dp[i][j-1][0];
                    if(grid[i][j]==0)
                    {
                        int val=(a+b)%mod;
                        dp[i][j][0]=dp[i][j][1]=val;
                    }
                    else 
                    {
                        dp[i][j][0]=a;
                        dp[i][j][1]=b;
                    }



                }
                

            }

        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         cout<<"{ "<<dp[i][j][0]<<" "<<dp[i][j][1]<<" }  ";

        //     }
        //     cout<<endl;
        // }
        return dp[n-1][m-1][0];
        
    }
};
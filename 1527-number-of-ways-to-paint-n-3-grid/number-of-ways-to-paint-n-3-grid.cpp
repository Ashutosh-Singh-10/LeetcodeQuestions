class Solution {
public:
    int numOfWays(int n) {
        long long mod=1e9+7,ans=0;
        vector<vector<long long>> dp(n+1,vector<long long>(12,0));
        vector<pair<long long,long long>> vec={
            {0,4},{0,5},{0,7},{0,8},{0,9},
            {1,4},{1,6},{1,7},{1,8},
            {2,4},{2,5},{2,8},{2,9},{2,11},
            {3,5},{3,9},{3,10},{3,11},
            {4,10},{4,11},
            {5,10},
            {6,8},{6,9},{6,11},
            {7,9},{7,10},{7,11}
        };
        for(int i=0;i<12;i++) dp[0][i]=1;
        for(int i=1;i<n;i++){
            for(auto &[a,b]:vec){
                // cout<<dp[i][a]<<" ";
                dp[i][a]=(dp[i][a]+dp[i-1][b])%mod;
                dp[i][b]=(dp[i][b]+dp[i-1][a])%mod;
                dp[i][a]%=mod;
                dp[i][b]%=mod;
            }
        }
        for(auto &i:dp[n-1]){
            ans=(ans+i)%mod;
        }
        return ans;
        

        
    }
};
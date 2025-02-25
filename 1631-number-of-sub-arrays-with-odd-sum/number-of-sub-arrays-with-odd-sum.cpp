class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int> > dp(n+1,vector<int>(3,0));
        int ans=0,mod=1e9+7;
        for(int i=1;i<=n;i++)
        {
            int el=arr[i-1];
            if(el%2)
            {
                dp[i][1]=dp[i-1][2];
                dp[i][2]=dp[i-1][1];
                dp[i][1]++;
            }
            else 
            {
                dp[i][1]=dp[i-1][1];
                dp[i][2]=dp[i-1][2];
                dp[i][2]++;
            }
            ans=(ans+dp[i][1])%mod;
        }
        return ans;
        
        
    }
};
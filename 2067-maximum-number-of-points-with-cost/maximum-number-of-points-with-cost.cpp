#define ll long long
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        ll n=points.size(),m=points[0].size();
        vector<vector<ll>> dp(n+1,vector<ll>(m,0));
        for(int i=0;i<m;i++) dp[0][i]=points[0][i];
        for(ll i=0;i<n-1;i++)
        {
            ll pf=0;
            for(int j=0;j<m;j++)
            {
                pf=max(pf,dp[i][j]);
                dp[i+1][j]=pf+(ll)points[i+1][j];
                pf--;
            }
            pf=0;
        
            for(int j=m-1;j>=0;j--)
            {
                pf=max(pf,dp[i][j]);
                dp[i+1][j]=max(dp[i+1][j],pf+(ll)points[i+1][j]);
                pf--;
            }
            
        }
        
        ll ans=0;
        for(int i=0;i<m;i++) ans=max(ans,dp[n-1][i]);
        return ans;

        
    }
};
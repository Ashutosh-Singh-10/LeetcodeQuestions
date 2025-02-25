#define ll long long 
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        ll n=arr.size();
        vector<vector<ll> > dp(n+1,vector<ll>(3,0));
        ll ans=0,mod=1e9+7;
        for(ll i=1;i<=n;i++)
        {
            ll el=arr[i-1];
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
        cout<<ans<<endl;
        return ans;
        
        
    }
};
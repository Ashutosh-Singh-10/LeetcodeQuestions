class Solution {
public:
    int fun(vector<int> &piles,int i,int j,vector<int> &pre,vector<vector<int>> &dp)
    {
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(j==i) return 0;
        int ans=pre[j+1]-pre[i];
        ans=max(pre[j+1]-pre[i+1]-fun(piles,i+1,j,pre,dp),pre[j]-pre[i]-fun(piles,i,j-1,pre,dp));
        dp[i][j]=ans;
        return ans;
    
    }
    int stoneGameVII(vector<int>& piles) {
        int n=piles.size();
        vector<int> pre={0};
        vector<vector<int>> dp(n,vector<int> (n,-1));
        for(auto &i:piles) pre.push_back(pre.back()+i);
        return fun(piles,0,n-1,pre,dp);

        
    }
};
int fun(vector<int> &vec,int k)
{   
    int n=vec.size();
    vector<vector<int>>dp(n+2,vector<int>(k+1));
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            dp[i+2][j+1]=max(dp[i][j+1],dp[i][j]+vec[i]);
            dp[i+2][j+1]=max(dp[i+2][j+1],dp[i+1][j+1]);
            ans=max({dp[i+2][j+1],ans});
            
        }
    }
 
    return ans;
    


}
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int x=slices.back();
        int k=slices.size()/3;
        slices.pop_back();
        vector<int> vec;
        for(int i=1;i<slices.size();i++) vec.push_back(slices[i]);
        vec.push_back(x);
        int ans=fun(slices,k);
        
        return max(ans,fun(vec,k));

        
        
    }
};
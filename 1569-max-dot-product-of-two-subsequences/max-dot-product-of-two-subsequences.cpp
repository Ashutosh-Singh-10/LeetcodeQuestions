class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) { 
        int m=nums1.size();
        int n=nums2.size();
        long long mod=10e9+7;
        vector<vector<long long>> vec(m+1,vector<long long>(n+1,INT_MIN));
        long long ans=INT_MIN;
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                {
                    vec[i][j]=INT_MIN;
                }
                else 
                {
                    vec[i][j]=(nums1[i-1]*nums2[j-1])%mod;
                    vec[i][j]=max(max(vec[i][j],(vec[i][j]+vec[i-1][j-1])%mod),max(vec[i-1][j-1],max(vec[i][j-1],vec[i-1][j])));
                }

            }
        }

  
        return vec[m][n];



        
    }
};
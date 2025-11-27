class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans=-1e18,n=nums.size();;
        vector<long long> pre(n+1,0);
        for(int i=1;i<=n;i++) pre[i]+=pre[i-1]+nums[i-1];
        for(int i=0;i<k;i++){
            long long sum=0;
            for(int j=i+k;j<=n;j+=k){
                sum+=pre[j]-pre[j-k];
                ans=max(ans,sum);
                // cout<<j<<" "<<sum<<endl;
                if(sum<0) sum=0;
            }
            

            
        }
        // for(auto &i:pre) cout<<i<<" ";
        return ans;
  
        
    }
};
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum=0,start=0,n=nums.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            while(sum*(i-start+1)>=k)
            {
                sum-=nums[start];
                start++;

            }
            ans+=i-start+1;
        }
        return ans;
        
    }
};
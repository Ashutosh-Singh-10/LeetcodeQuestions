class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        set<long long> st;
        long long idx=0,ans=0;
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=(long long)nums[i];
            while(i-idx+1>k)
            {
                st.erase(nums[idx]);
                sum-=(long long)nums[idx];
                idx++;
            }
            while(st.count(nums[i]))
            {
                st.erase(nums[idx]);
                sum-=(long long)nums[idx];
                idx++;
            }
            st.insert(nums[i]);
            if(i-idx+1==k) 
            {
                ans=max(ans,sum);
            }
        }
        return ans;
        
    }
};
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long mn=nums[0];
        long long mx=nums[1];
        long long val=mn-mx;
        mn=max(nums[0],nums[1]);
        long long ans=0;
        for(int i=2;i<nums.size();i++)
        {
            ans=max(ans,nums[i]*val);
            if(mn-nums[i]>val)
            {
                val=mn-nums[i];
                
            }
            mn=max(mn,(long long)nums[i]);
        }
        return ans;
        
    }
};
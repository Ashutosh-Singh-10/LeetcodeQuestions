class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
             sort(nums.begin(),nums.end());
        int start=0;
        int end=0;
        int n=nums.size();
        int ans=0;
        for(auto &i:nums)
        {
            end++;
            if(-2*k+i>nums[start])
            {
                start++;
            
            }
            ans=max(ans,end-start);  
        }
        return ans;

            
        
        
    }
};
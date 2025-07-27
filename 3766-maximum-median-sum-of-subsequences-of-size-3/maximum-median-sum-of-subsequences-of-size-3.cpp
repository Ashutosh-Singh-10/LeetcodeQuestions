class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long idx=nums.size()-2,ans=0;
        for(int i=0;i<nums.size()/3;i++) 
        {
            ans+=nums[idx];
            idx-=2;
        }
        return ans;
        
    }
};
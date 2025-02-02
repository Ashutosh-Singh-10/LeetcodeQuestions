class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                reverse(nums.begin(),nums.begin()+i+1);
                reverse(nums.begin()+i+1,nums.end());
                reverse(nums.begin(),nums.end());
                break;
            }
        }
        return is_sorted(nums.begin(),nums.end());
        
    }
};
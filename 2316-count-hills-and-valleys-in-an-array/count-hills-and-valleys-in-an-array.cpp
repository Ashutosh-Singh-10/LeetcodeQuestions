class Solution {
public:
    int countHillValley(vector<int>& vec) {
        vector<int> nums;
        for(auto &i:vec)
        {
            if(nums.size()==0 || nums.back()!=i) nums.push_back(i);
        }
        int n=nums.size(),ans=0;
        
        for(int i=1;i<n-1;i++)
        {
            if(max(nums[i-1],nums[i+1])<nums[i] || nums[i]<min(nums[i-1],nums[i+1]))
            ans++;
        }
        return ans;
        
    }
};
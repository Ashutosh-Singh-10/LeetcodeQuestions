class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i+=2) 
        {
            if(nums[i]!=nums[i-1]) return 0;
        
        }
        return 1;
        
    }
};
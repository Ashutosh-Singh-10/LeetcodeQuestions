class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());

        
        int  cur=nums[0];
        int ans=0,l=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if((cur&nums[i])==mx)
            {
                ans=max(i-l+1,ans);
            }
            else 
            {
                l=i+1;
                if(i<n-1)
                cur=nums[i+1];
            }

            
        }
        return ans;
        
    }
};
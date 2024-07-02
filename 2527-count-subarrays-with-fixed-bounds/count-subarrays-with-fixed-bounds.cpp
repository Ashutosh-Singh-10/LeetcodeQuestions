class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        int idx=-1;
        int l=0,h=0,mx=-1,mn=1e7;
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>maxK || nums[i]<minK)
            {
                mn=1e7;mx=-1;
                idx=i;
                continue;
            }
            mn=min(mn,nums[i]);
            mx=max(mx,nums[i]);
            if(nums[i]==minK) l=i;
            if(nums[i]==maxK) h=i;
            if(mn==minK && mx==maxK) 
            {
                ans+=min(l,h)-idx;
            }
            
        }
        return ans;
        
    }
};
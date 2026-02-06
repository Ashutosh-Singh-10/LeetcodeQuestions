class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int r=0,n=nums.size(),ans=nums.size();;
        for(int i=0;i<n;i++){
            while(r<n && (long long)nums[r]<=(long long)nums[i]*(long long)k)
            {
                r++;
            }
            ans=min(ans,n-(r-i));
        }
        return ans;
        
    }
};
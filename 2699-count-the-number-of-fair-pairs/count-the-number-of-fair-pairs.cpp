class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        map<long long,long long> mp;
        for(auto &i:nums)
        {
            mp[i]++;
        }
        sort(nums.begin(),nums.end());
        
        int l=0,r=-1;
        int n=nums.size();
        for(int i=n-1;i>=0;i--)
        {
            while((r<n-1) && (nums[r+1]+nums[i]<=upper))
            {
                r++;
            }
            while((l<n) && (nums[l]+nums[i]<lower))
            {
                l++;
            }
            ans+=r-l+1;
            // cout<<nums[i]<<" "<<l<<" "<<r<<" "<<ans<<endl;
            if(nums[i]+nums[i]>=lower && nums[i]+nums[i]<=upper ) ans--;
        }
        return ans/2;
        // 0 1 4 5 7
        
    }
};
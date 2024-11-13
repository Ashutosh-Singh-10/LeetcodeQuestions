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
        vector<int> vec(nums.size());
        int idx=0;
        for(auto a:nums)
        {
            vec[idx]=nums[idx];;
            idx++;
        }
        
        int l=0,r=-1;
        int n=nums.size();
        for(int i=n-1;i>=0;i--)
        {
            while((r<n-1) && (vec[r+1]+vec[i]<=upper))
            {
                r++;
            }
            while((l<n) && (vec[l]+vec[i]<lower))
            {
                l++;
            }
            ans+=r-l+1;
            // cout<<vec[i]<<" "<<l<<" "<<r<<" "<<ans<<endl;
            if(vec[i]+vec[i]>=lower && vec[i]+vec[i]<=upper ) ans--;
        }
        return ans/2;
        // 0 1 4 5 7
        
    }
};
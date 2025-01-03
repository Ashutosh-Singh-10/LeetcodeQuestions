class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long r=0;
        for(auto &i:nums) r+=i;
        long long l=0,ans=0;
        reverse(nums.begin(),nums.end());
        for(auto &i:nums)
        {
            r-=i;
            l+=i;
            if(l<=r) ans++;

        }
        if(l<=r) ans--;
        return ans;
        
    }
};
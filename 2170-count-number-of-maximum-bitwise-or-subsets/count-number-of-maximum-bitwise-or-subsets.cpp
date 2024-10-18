class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int o=0;
        for(auto &i:nums) o|=i;
        int n=nums.size();
        int ans=0;
        for(int i=1;i<(1ll<<n);i++)
        {
            int tmp=0;
            for(int j=0;j<n;j++)
            {
                if((1ll<<j)&i) tmp|=nums[j];
            }
            if(tmp==o) ans++;

        }
    

    return ans;
        
    }
};
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<set<int>> st(35);
        for(int j=0;j<nums.size();j++)
        {
            int el=nums[j];
            for(int i=0;i<=30;i++)
            {
                if((1<<i)&el)
                {
                    st[i].insert(j);
                }
            }
        }
        vector<int> ans(nums.size(),0);
        for(int j=0;j<nums.size();j++)
        {
            
            int r=j;
            for(int i=0;i<=30;i++)
            {
                if(st[i].size())
                {
                    r=max(r,*st[i].begin());
                }
                if(st[i].count(j)) st[i].erase(j);
            }
            ans[j]=r-j+1;
        }
        return ans;

        
        
        
    }
    
};
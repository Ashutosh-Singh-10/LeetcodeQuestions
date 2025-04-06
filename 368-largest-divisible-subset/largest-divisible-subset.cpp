class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> vec(n,1);
        vector<int> prev;
        int el=0;
        for(int i=0;i<n;i++) prev.push_back(i);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            int pr=i;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && cnt<vec[j])
                {
                    cnt=vec[j];
                    pr=j;
                }
            }
            vec[i]=cnt+1;
            prev[i]=pr;
            if(ans<vec[i])
            {

                ans=max(vec[i],ans);
                el=i;
            }
        }
        vector<int> ret;
        while(1)
        {
            ret.push_back(nums[el]);
            if(el==prev[el]) break;
            el=prev[el];
        }
        return ret;
        
    }
};
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> vec(35,0);
        if(k==0) return 1;
        int n=nums.size(),idx=0;
        int ans=n+1,val=0;
        for(int i=0;i<n;i++)
        {
            val|=nums[i];
            for(int j=0;j<=30;j++)
            {
                if(nums[i]&(1<<j)) vec[j]++;
            }
            while(val>=k)
            {
                ans=min(ans,i-idx+1);
                
                for(int j=0;j<=30;j++)
                {
                    if(nums[idx]&(1<<j))
                    {

                        vec[j]--;
                        if(vec[j]==0)
                        val^=(1<<j);
                    } 
                }
                idx++;
            }


        }
        if(ans==n+1) return -1;
        return max(ans,1);
        
    }
};
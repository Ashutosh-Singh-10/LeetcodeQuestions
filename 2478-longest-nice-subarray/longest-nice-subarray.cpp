class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        vector<int> vec(34,0);
        int j=0,ans=0;
        for(int a=0;a<nums.size();a++)
        {
            for(int i=0;i<=30;i++)
            {
                int bit=nums[a]&(1<<i);
                if(bit)
                vec[i]++;
                while(vec[i]>1)
                {
                    for(int b=0;b<=30;b++)
                    {
                        if(nums[j]&(1<<b))
                        vec[b]--;
                        
                    }
                    j++;
                }

            }
            ans=max(a-j+1,ans);
        }
        return ans;
        
        
    }
};